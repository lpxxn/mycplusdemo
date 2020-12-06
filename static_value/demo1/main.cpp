#include<iostream>

#include "a.h"
#include "b.h"

int main() {
    aAdd();
    bAdd();
    b::test();
    std::cout << aV() << std::endl;
    std::cout << bV() << std::endl;
}