//
// Created by li on 2020/12/8.
//

#ifndef MYCPLUSDEMO_STRING_BAD_1_H
#define MYCPLUSDEMO_STRING_BAD_1_H
#include <iostream>

class StringBad1
{
private:
    char *str;
    int len;
    static int num_strings;
public:
    StringBad1();
    StringBad1(const char *s);
    friend std::ostream & operator<< (std::ostream &os, const StringBad1 & st);
    static int get_num_strings();

    ~StringBad1();
};
#endif //MYCPLUSDEMO_STRING_BAD_1_H
