cmd_Release/obj.target/multihashing/bitcore.o := cc '-DNODE_GYP_MODULE_NAME=multihashing' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/root/.node-gyp/0.10.28/include/node -I/root/.node-gyp/0.10.28/src -I/root/.node-gyp/0.10.28/deps/uv/include -I/root/.node-gyp/0.10.28/deps/v8/include -I../crypto  -fPIC -Wall -Wextra -Wno-unused-parameter -pthread -m64 -O2 -fno-strict-aliasing -fno-tree-vrp -fno-omit-frame-pointer  -MMD -MF ./Release/.deps/Release/obj.target/multihashing/bitcore.o.d.raw  -c -o Release/obj.target/multihashing/bitcore.o ../bitcore.c
Release/obj.target/multihashing/bitcore.o: ../bitcore.c \
 ../sha3/sph_blake.h ../sha3/sph_types.h ../sha3/sph_bmw.h \
 ../sha3/sph_groestl.h ../sha3/sph_jh.h ../sha3/sph_keccak.h \
 ../sha3/sph_skein.h ../sha3/sph_luffa.h ../sha3/sph_cubehash.h \
 ../sha3/sph_shavite.h ../sha3/sph_simd.h ../sha3/sph_echo.h
../bitcore.c:
../sha3/sph_blake.h:
../sha3/sph_types.h:
../sha3/sph_bmw.h:
../sha3/sph_groestl.h:
../sha3/sph_jh.h:
../sha3/sph_keccak.h:
../sha3/sph_skein.h:
../sha3/sph_luffa.h:
../sha3/sph_cubehash.h:
../sha3/sph_shavite.h:
../sha3/sph_simd.h:
../sha3/sph_echo.h: