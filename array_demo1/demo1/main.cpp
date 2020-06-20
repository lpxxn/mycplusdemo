#include<iostream>

int sum(int arr[], int len); // arr = array name, len = size

int main() {
    int arr1[] = {1 , 2, 4 ,5};
    int arr1_len = sizeof arr1/sizeof(int);
    std::cout<< "arr1 len: " << arr1_len << std::endl;
    // 数组名就是第一个元素的地址
    // arr == &arr[0] // array name is address of first element
    // 
    // arr1[i] == *(arr + i)
    // &arr[i] == arr + i

    int int_arr[] = {1, 2, 3};
    // 
    int int_arr_len = sizeof int_arr/sizeof(int);
    auto total = sum(int_arr, int_arr_len);
    std::cout << "total: " << total << std::endl;
}

// int sum(int arr[], int len) {
//     int total = 0;
//     for (int i = 0; i < len; i++)
//         total += arr[i];
//     return total;
// }

// 上面和下面是一样，两个同不能同时存在
int sum(int *arr, int len) {
    int total = 0;
    for (int i = 0; i < len; i++)
        total += arr[i];
    return total; 
}

/*
g++ main.cpp 
output a.out
g++ -std=c++11 main.cpp
./a.out
或者指定输出
g++ main.cpp -o main

// multiple
g++ a.cpp b.cpp -o test

# alias for g++ support C++ standard 11, 14, 17, 20
alias g++11='g++ -std=c++11'
alias g++14='g++ -std=c++14'
alias g++17='g++ -std=c++17'
alias g++20='g++ -std=c++2a'


#生成预处理后的.i文件
g++ -E test.cpp -o test.i
#或
cpp test.cpp -o test.i

#生成汇编.s文件
g++ -S test.i -o test.s			

#或
ln -s /usr/libexec/gcc/x86_64-redhat-linux/4.8.2/cc1plus /usr/local/bin
cc1plus test.i -o test.s

#生成二进制.o文件
g++ -c test.s -o test.o

#或
as test.s -o test.o

//生成二进制.out可执行文件
g++ test.o -o test.out

#或者直接使用ld进行链接，但是需要注意使用ld需添加较长命令选项。使用g++ -v选项可以查看最后一行collect2使用的命令选项。collect2是对ld的封装，最终还是要调用ld来完成链接工作。
ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib64/crt1.o /usr/lib64/crti.o /usr/lib64/crtn.o /usr/lib/gcc/x86_64-redhat-linux/4.8.5/crtbegin.o /usr/lib/gcc/x86_64-redhat-linux/4.8.5/crtend.o -L/usr/lib/gcc/x86_64-redhat-linux/4.8.5 -L/usr/lib64 -L/usr/lib -lstdc++ -lm -lgcc_s -lc -lgcc  main.o -o test.out

*/