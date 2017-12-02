#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_blake.h"
#include "sha3/sph_bmw.h"
#include "sha3/sph_groestl.h"
#include "sha3/sph_jh.h"
#include "sha3/sph_keccak.h"
#include "sha3/sph_skein.h"
#include "sha3/sph_luffa.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_shavite.h"
#include "sha3/sph_simd.h"
#include "sha3/sph_echo.h"

#define HASH_FUNC_BASE_TIMESTAMP 1492973331U   // Machinecoin: Genesis Timestamp
#define HASH_FUNC_COUNT 10                     // Machinecoin: HASH_FUNC_COUNT of 11
#define HASH_FUNC_COUNT_PRINTFS 40320         // Machinecoin: HASH_FUNC_COUNT!
#define HASH_FUNC_COUNT_PERMUTATIONS 40320

static __thread uint32_t s_ntime = UINT32_MAX;
static __thread int permutation[HASH_FUNC_COUNT] = { 0 };
#define _ALIGN(x) __attribute__ ((aligned(x)))

// helpers
inline void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

static void reverse(int *pbegin, int *pend) {
	while ( (pbegin != pend) && (pbegin != --pend) )
		swap(pbegin++, pend);
}

static void next_permutation(int *pbegin, int *pend) {
	if (pbegin == pend)
		return;

	int *i = pbegin;
	++i;
	if (i == pend)
		return;

	i = pend;
	--i;

	while (1) {
		int *j = i;
		--i;

		if (*i < *j) {
			int *k = pend;

			while (!(*i < *--k))
				/* pass */;

			swap(i, k);
			reverse(j, pend);
			return; // true
		}

		if (i == pbegin) {
			reverse(pbegin, pend);
			return; // false
		}
	}
}
// helpers

void bitcore_hash(const char* input, char* output, uint32_t len)
{
	uint32_t _ALIGN(64) hash[16 * HASH_FUNC_COUNT]; // 16 bytes * HASH_FUNC_COUNT
	uint32_t *hashA, *hashB;
	uint32_t dataLen = 64;
	uint32_t *work_data = (uint32_t *)input;
	const uint32_t timestamp = work_data[17];


	sph_blake512_context     ctx_blake;
	sph_bmw512_context       ctx_bmw;
	sph_groestl512_context   ctx_groestl;
	sph_skein512_context     ctx_skein;
	sph_jh512_context        ctx_jh;
	sph_keccak512_context    ctx_keccak;
	sph_luffa512_context     ctx_luffa;
	sph_cubehash512_context  ctx_cubehash;
	sph_shavite512_context   ctx_shavite;
	sph_simd512_context      ctx_simd;
	sph_echo512_context      ctx_echo;

	// We want to permute algorithms. To get started we
	// initialize an array with a sorted sequence of unique
	// integers where every integer represents its own algorithm.
	if (timestamp != s_ntime) {
		int steps = (int) (timestamp - HASH_FUNC_BASE_TIMESTAMP) % HASH_FUNC_COUNT_PERMUTATIONS;
		for (int i = 0; i < HASH_FUNC_COUNT; i++) {
			permutation[i] = i;
		}
		for (int i = 0; i < steps; i++) {
			next_permutation(permutation, permutation + HASH_FUNC_COUNT);
		}
		s_ntime = timestamp;
	}
	
	
	for (int i = 0; i < HASH_FUNC_COUNT; i++) {
		if (i == 0) {
			dataLen = 80;
			hashA = work_data;
		} else {
			dataLen = 64;
			hashA = &hash[16 * (i - 1)];
		}
		hashB = &hash[16 * i];

		switch(permutation[i]) {
			case 0:
				sph_blake512_init(&ctx_blake);
				sph_blake512(&ctx_blake, hashA, dataLen);
				sph_blake512_close(&ctx_blake, hashB);
				break;
			case 1:
				sph_bmw512_init(&ctx_bmw);
				sph_bmw512 (&ctx_bmw, hashA, dataLen);
				sph_bmw512_close(&ctx_bmw, hashB);
				break;
			case 2:
				sph_groestl512_init(&ctx_groestl);
				sph_groestl512 (&ctx_groestl, hashA, dataLen);
				sph_groestl512_close(&ctx_groestl, hashB);
				break;
			case 3:
				sph_skein512_init(&ctx_skein);
				sph_skein512 (&ctx_skein, hashA, dataLen);
				sph_skein512_close(&ctx_skein, hashB);
				break;
			case 4:
				sph_jh512_init(&ctx_jh);
				sph_jh512 (&ctx_jh, hashA, dataLen);
				sph_jh512_close(&ctx_jh, hashB);
				break;
			case 5:
				sph_keccak512_init(&ctx_keccak);
				sph_keccak512 (&ctx_keccak, hashA, dataLen);
				sph_keccak512_close(&ctx_keccak, hashB);
				break;
			case 6:
				sph_luffa512_init(&ctx_luffa);
				sph_luffa512 (&ctx_luffa, hashA, dataLen);
				sph_luffa512_close(&ctx_luffa, hashB);
				break;
			case 7:
				sph_cubehash512_init(&ctx_cubehash);
				sph_cubehash512 (&ctx_cubehash, hashA, dataLen);
				sph_cubehash512_close(&ctx_cubehash, hashB);
				break;
			case 8:
				sph_shavite512_init(&ctx_shavite);
				sph_shavite512(&ctx_shavite, hashA, dataLen);
				sph_shavite512_close(&ctx_shavite, hashB);
				break;
			case 9:
				sph_simd512_init(&ctx_simd);
				sph_simd512 (&ctx_simd, hashA, dataLen);
				sph_simd512_close(&ctx_simd, hashB);
				break;
			case 10:
				sph_echo512_init(&ctx_echo);
				sph_echo512 (&ctx_echo, hashA, dataLen);
				sph_echo512_close(&ctx_echo, hashB);
				break;
			default:
				break;
		}
	}

	memcpy(output, &hash[16 * (HASH_FUNC_COUNT - 1)], 32);
}
