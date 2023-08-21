#include <filesystem>
#include <iostream>
#include <unistd.h> // --> 使用access函数获取文件状态，成功则存在，否则不存在
#include <string>
#include <sys/stat.h> // --> 使用stat函数获取文件状态，成功则存在，否则不存在
#include <ctime>

bool isFileExists_access(std::string&);
bool isFileExists_stat(std::string& name);

int main(int argc, char **argv) {
    // 1
    std::cout << "argv[0]: " << argv[0] << std::endl;

    char buff[FILENAME_MAX];
    getcwd( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    std::cout << "current_working_dir: " << current_working_dir << std::endl;

    std::string filePath = current_working_dir + "/current_path";

    if (isFileExists_access(filePath)) {
        std::cout << "isFileExists_access" << std::endl;
    }
    if (isFileExists_stat(filePath)) {
        std::cout << "isFileExists_stat" << std::endl;
    }

    // https://en.cppreference.com/w/cpp/filesystem/current_path filesystem c++17才支持的
    if (std::filesystem::exists(filePath)) {
        std::cout << "filesystem::exists" << std::endl;

    }
    fork();
    printf("1");
    fork();
    printf("2");
    return 0;
}

bool isFileExists_access(std::string& name) {
    return (access(name.c_str(), F_OK ) != -1 );
}

bool isFileExists_stat(std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}