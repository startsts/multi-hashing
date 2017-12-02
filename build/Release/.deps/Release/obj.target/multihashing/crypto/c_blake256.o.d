cmd_Release/obj.target/multihashing/crypto/c_blake256.o := cc '-DNODE_GYP_MODULE_NAME=multihashing' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/root/.node-gyp/0.10.28/include/node -I/root/.node-gyp/0.10.28/src -I/root/.node-gyp/0.10.28/deps/uv/include -I/root/.node-gyp/0.10.28/deps/v8/include -I../crypto  -fPIC -Wall -Wextra -Wno-unused-parameter -pthread -m64 -O2 -fno-strict-aliasing -fno-tree-vrp -fno-omit-frame-pointer  -MMD -MF ./Release/.deps/Release/obj.target/multihashing/crypto/c_blake256.o.d.raw  -c -o Release/obj.target/multihashing/crypto/c_blake256.o ../crypto/c_blake256.c
Release/obj.target/multihashing/crypto/c_blake256.o: \
 ../crypto/c_blake256.c ../crypto/c_blake256.h
../crypto/c_blake256.c:
../crypto/c_blake256.h:
