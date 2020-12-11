build 目录下
cmake ..

otool -L ./bin/http_request
install_name_tool -change /Users/li/Developer/cplus_workspace/restclient-cpp/my_install/lib/librestclient-cpp.1.dylib @loader_path/librestclient-cpp.1.dylib ./http_request


当前文件夹
DYLD_LIBRARY_PATH=./ ./http_request
./autogen.sh
./configure --prefix=$(pwd)/my_install
make
make install