#include<iostream>

int main() {
    // 字符串常量(string constant) 或者 字符串字面值(string litral)
    // 为兼容C语言，C++中所有的字符串字面值都由编译器自动在末尾添加一个空字符。
    char a[] = "abc";
    std::cout << strlen(a) << "  " << sizeof(a) << "  " 
    << sizeof a  << "   " << sizeof a / sizeof(char) << std::endl; // 3  4  4  4 
    // sizeof a 是4 也就是后面有\0 "abc\0"
    // warning: array index 4 is past the end of the array (which contains 4 elements)
    std::cout << a[3] << " -- "<< a[4] << std::endl;

    char a2[10] = "def";
    // 3 10
    std::cout << "strlen a2: " << strlen(a2) << "  "<< sizeof a2 << std::endl;
    //  char array is too long
    //char a3[3] = "ghi";
    char a3[3] = "gh";
    // strlen a3: 2  3
    std::cout << "strlen a3: " << strlen(a3) << "  "<< sizeof a3 << std::endl;
       

    // char b[] = "def";
    // char c[] = a + b;

    int b[] = {1, 2, 3};
    std::cout << sizeof b << std::endl;
    return 0;
}

/*
https://blog.csdn.net/waveviewer/article/details/81565935?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.nonecase

*/