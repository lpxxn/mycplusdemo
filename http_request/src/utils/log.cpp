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


namespace utils {
    std::shared_ptr<spdlog::logger> real_log = nullptr;
    std::shared_ptr<spdlog::logger> utils::rotating_example() {
        if (real_log == nullptr) {
            // Create a file rotating logger with 5mb size max and 3 rotated files
            auto max_size = 1048576 * 5;
            auto max_files = 3;
            real_log = spdlog::rotating_logger_mt("log", "logs/rotating.txt", max_size, max_files);
            real_log->info("init log info");
        }

        return real_log;
    }
//    Logger *utils::Logger::m_log = nullptr;
//
//    Logger *utils::Logger::Log() {
//        if (m_log == nullptr) {
//            m_log = new Logger();
//            auto max_size = 1048576 * 5;
//            auto max_files = 3;
//            m_log->real_log = spdlog::rotating_logger_mt("log", "logs/rotating.txt", max_size, max_files);
//        }
//        return m_log;
//    }
//
//    Logger::Logger() {
//
//    }
}

