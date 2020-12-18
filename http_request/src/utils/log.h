//
// Created by li on 2020/12/18.
//

#ifndef HTTP_REQUEST_UTILS_LOG_H
#define HTTP_REQUEST_UTILS_LOG_H

#include <spdlog/sinks/rotating_file_sink.h>

namespace utils {
    std::shared_ptr<spdlog::logger> rotating_example();
}

#endif //HTTP_REQUEST_UTILS_LOG_H
