#ifndef BITCORE_H
#define BITCORE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void bitcore_hash(const char* input, char* output, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif
