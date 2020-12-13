#include <filesystem>
#include <iostream>
#include <unistd.h>
#include <string>
#include <ctime>

bool isFileExists_access(std::string&);

int main(int argc, char **argv) {
    // 1
    std::cout << "argv[0]: " << argv[0] << std::endl;

    char buff[FILENAME_MAX];
    getcwd( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    std::cout << "current_working_dir: " << current_working_dir << std::endl;

    std::string filePath = current_working_dir + "/current_path";

    //https://en.cppreference.com/w/cpp/filesystem/current_path filesystem c++17才支持的
    if (std::filesystem::exists(filePath)) {
        std::cout << "filesystem::exists" << std::endl;

    }
    if (isFileExists_access(filePath)) {
        std::cout << "exist" << std::endl;
    }
    return 0;
}

bool isFileExists_access(std::string& name) {
    return (access(name.c_str(), F_OK ) != -1 );
}