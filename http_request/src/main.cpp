#include <iostream>
#include <ctime>
#include <regex>
#include <CLI/CLI11.hpp>
#include <restclient-cpp/restclient.h>

int main(int argc, char **argv) {
    CLI::App app{"App description"};
    // Define options
    int p = 0;
    app.add_option("-p", p, "Parameter");
    CLI11_PARSE(app, argc, argv);

    std::cout << "Parameter value: " << p << std::endl;

    std::cout << "Hello, World!" << std::endl;
    RestClient::init();
    RestClient::Response r = RestClient::get("https://baseinfo.meican.com");
    std::cout << r.body << std::endl;
    auto a = 1;
    time_t t = time(nullptr);
    tm *local_time = localtime(&t);
    std::cout << "hour: " << local_time->tm_hour << " min: " << local_time->tm_min << std::endl;

    return 0;
}
