RPCLIB_PATCH_TAG=v2.2.1_c3
RPCLIB_NAME_PRE=rpclib-${RPCLIB_PATCH_TAG}

# Download TAG v2.2.1_c3 into ${RPCLIB_NAME_PRE}-source dir.
git clone -b ${RPCLIB_PATCH_TAG} https://github.com/carla-simulator/rpclib.git ${RPCLIB_NAME_PRE}-source


mkdir -p rpc-build
pushd rpc-build >/dev/null

cmake  -DCMAKE_CXX_FLAGS="-pthread -std=c++14" \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX="../rpc-install" \
        ../${RPCLIB_NAME_PRE}-source

make

make install

popd >/dev/null
