#include <filesystem>
#include <iostream>
#include <string>
#include <ctime>

int main(int argc, char **argv) {
    // 1
    std::cout << "argv[0]: " << argv[0] << std::endl;

    char buff[FILENAME_MAX];
    getcwd( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    std::cout << "current_working_dir" << current_working_dir << std::endl;

    return 0;
}