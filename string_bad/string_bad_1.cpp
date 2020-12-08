//
// Created by li on 2020/12/8.
//

#include "string_bad_1.h"

int StringBad1::num_strings = 0;

StringBad1::StringBad1(const char *s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    //num_strings++
    std::cout<< num_strings << ": \"" << str << "\" object created" << std::endl;
}

StringBad1::StringBad1() {
    len = 4;
    str = new char[4];
    // num_strings++
    std::cout<< num_strings << ": \"" << str << "\" default object created" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const StringBad1 &st) {
    os << st.str;
    return os;
}

int StringBad1::get_num_strings() {
    return num_strings;
}

StringBad1::~StringBad1() {
    --num_strings;
    std::cout<< "address: " << this << " \"" << str << "\" default object deleted, " << num_strings << std::endl;
    delete []str;
}
