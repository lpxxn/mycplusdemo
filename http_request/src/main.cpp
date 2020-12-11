#include <iostream>
#include <restclient-cpp/restclient.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    RestClient::init();
    RestClient::Response r = RestClient::get("https://baseinfo.meican.com");
    std::cout << r.body << std::endl;
    return 0;
}
