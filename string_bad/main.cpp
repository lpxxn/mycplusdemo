//
// Created by li on 2020/12/8.
//

#include <iostream>

#include "string_bad_1.h"

using namespace std;

void callme1(StringBad1 &); // pass by reference
void callme2(StringBad1); // pass by value

int main() {
    {
        StringBad1 sb1("hello world");
        cout << "sb1 address: " << &sb1 << endl;
        callme1(sb1);
        cout << StringBad1::get_num_strings() << endl;
        callme2(sb1);
        cout << StringBad1::get_num_strings() << endl;
    } // 退出这的时候会报错，因为callme2中的临时变量已经，已经把str指针给释放了。
    cout << StringBad1::get_num_strings() << endl;

    return 0;
}

void callme1(StringBad1 &sb) {
    cout << "pass by reference address: " << &sb << endl;
    cout << sb << endl;
}

// 值传递， StringBad1 会调用默认的复制构造函数，创建一个临时变量，在退出时会被销毁
// 为什么说是临时变量呢，因为在 析构函数里打印出了 this 地址。和原来的不是一个。
void callme2(StringBad1 sb) {
    cout << "pass by value address: " << &sb << endl;
    cout << sb << endl;
}
