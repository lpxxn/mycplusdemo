#include <filesystem>
#include <iostream>
#include <string>
#include <ctime>
#include <regex>

#include <restclient-cpp/restclient.h>
#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>
#include <CLI/CLI11.hpp>

#include "utils/log.h"

void parseConfig();

int main(int argc, char **argv) {
    auto logger = utils::rotating_example();
    logger->info("argv[0] {0} {1}", argv[0], "test");
    std::cout << "argv[0]: " << argv[0] << std::endl;
    utils::rotating_example()->info("hello world!");

    CLI::App app{"App description"};
    // Define options
    int p = 0;
    app.add_option("-p", p, "Parameter");
    CLI11_PARSE(app, argc, argv);

    std::cout << "Parameter value: " << p << std::endl;

    std::cout << "Hello, World!" << std::endl;
    RestClient::init();
    RestClient::Response r = RestClient::get("https://www.baidu.com");
    std::cout << r.body << std::endl;
    auto a = 1;
    time_t t = time(nullptr);
    tm *local_time = localtime(&t);
    std::cout << "hour: " << local_time->tm_hour << " min: " << local_time->tm_min << std::endl;

    auto s = std::to_string(1);
    int n_zero(2);
    auto dest = std::string(n_zero - s.length(), '0').append(s);
    auto min_str = std::to_string(local_time->tm_min);
    std::cout << "fill zero: " << dest << " current min: "
              << std::string(n_zero - min_str.length(), '0').append(min_str) << std::endl;
    parseConfig();
    return 0;
}

void parseConfig() {
    std::filesystem::path config_path = std::__fs::filesystem::current_path() / "config.yaml";
    std::cout << config_path << std::endl;
    YAML::Node config = YAML::LoadFile(config_path);

    if (config["lastLogin"]) {
        std::cout << "Last logged in: " << config["lastLogin"].as<std::string>() << "\n";
    }
}

