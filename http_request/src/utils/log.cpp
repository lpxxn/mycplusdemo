//
// Created by li on 2020/12/18.
//

#include "log.h"

//namespace utils {
//    std::shared_ptr<spdlog::logger> rotating_example() {
//        // Create a file rotating logger with 5mb size max and 3 rotated files
//        auto max_size = 1048576 * 5;
//        auto max_files = 3;
//        return spdlog::rotating_logger_mt("log", "logs/rotating.txt", max_size, max_files);
//    }
//}

std::shared_ptr<spdlog::logger> utils::rotating_example() {
    // Create a file rotating logger with 5mb size max and 3 rotated files
    auto max_size = 1048576 * 5;
    auto max_files = 3;
    return spdlog::rotating_logger_mt("log", "logs/rotating.txt", max_size, max_files);
}
