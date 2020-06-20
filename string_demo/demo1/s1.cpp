#include<iostream>

int main() {
    char a[] = "abc";
    std::cout << strlen(a) << "  " << sizeof(a) << "  " 
    << sizeof a  << "   " << sizeof a / sizeof(char) << std::endl; // 3  4  4  4 
    return 0;
}