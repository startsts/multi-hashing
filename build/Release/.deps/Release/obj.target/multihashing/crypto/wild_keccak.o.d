cmd_Release/obj.target/multihashing/crypto/wild_keccak.o := g++ '-DNODE_GYP_MODULE_NAME=multihashing' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/root/.node-gyp/0.10.28/include/node -I/root/.node-gyp/0.10.28/src -I/root/.node-gyp/0.10.28/deps/uv/include -I/root/.node-gyp/0.10.28/deps/v8/include -I../crypto  -fPIC -Wall -Wextra -Wno-unused-parameter -pthread -m64 -O2 -fno-strict-aliasing -fno-tree-vrp -fno-omit-frame-pointer -fno-rtti -fno-exceptions -std=c++0x -MMD -MF ./Release/.deps/Release/obj.target/multihashing/crypto/wild_keccak.o.d.raw   -c -o Release/obj.target/multihashing/crypto/wild_keccak.o ../crypto/wild_keccak.cpp
Release/obj.target/multihashing/crypto/wild_keccak.o: \
 ../crypto/wild_keccak.cpp ../crypto/wild_keccak.h ../crypto/hash.h \
 ../crypto/hash-ops.h
../crypto/wild_keccak.cpp:
../crypto/wild_keccak.h:
../crypto/hash.h:
../crypto/hash-ops.h:
