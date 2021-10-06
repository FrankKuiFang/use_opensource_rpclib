

mkdir -p build
pushd build >/dev/null

cmake  -DCMAKE_CXX_FLAGS="-pthread -std=c++14" \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX="../my_install" \
        ..

make

make install

popd >/dev/null
