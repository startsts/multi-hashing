cmd_Release/obj.target/multihashing/polytimos.o := cc '-DNODE_GYP_MODULE_NAME=multihashing' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/root/.node-gyp/0.10.28/include/node -I/root/.node-gyp/0.10.28/src -I/root/.node-gyp/0.10.28/deps/uv/include -I/root/.node-gyp/0.10.28/deps/v8/include -I../crypto  -fPIC -Wall -Wextra -Wno-unused-parameter -pthread -m64 -O2 -fno-strict-aliasing -fno-tree-vrp -fno-omit-frame-pointer  -MMD -MF ./Release/.deps/Release/obj.target/multihashing/polytimos.o.d.raw  -c -o Release/obj.target/multihashing/polytimos.o ../polytimos.c
Release/obj.target/multihashing/polytimos.o: ../polytimos.c \
 ../polytimos.h ../sha3/sph_skein.h ../sha3/sph_types.h \
 ../sha3/sph_echo.h ../sha3/sph_fugue.h ../sha3/sph_luffa.h \
 ../sha3/sph_shabal.h ../sha3/gost_streebog.h
../polytimos.c:
../polytimos.h:
../sha3/sph_skein.h:
../sha3/sph_types.h:
../sha3/sph_echo.h:
../sha3/sph_fugue.h:
../sha3/sph_luffa.h:
../sha3/sph_shabal.h:
../sha3/gost_streebog.h:
