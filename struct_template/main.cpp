//
// Created by li on 2020/12/14.
//
#include <string>
#include <iostream>


template<typename T>
struct my_as_if;

class MyNode {
public:
    template<typename T>
    T as() const {
        return my_as_if<T>(*this)();
    }
};

struct label {
    std::string app;
    std::string image;
};

template<typename T>
struct myt;

template<>
struct myt<label> {
    static bool abc(const MyNode &node, label &rhs) {
        rhs.image = "my------";
        rhs.app = "haha----";
        return true;
    }
};

template<>
struct myt<int> {
    static bool def() {
        return true;
    }
};


template<typename T>
struct my_as_if {
    explicit my_as_if(const MyNode &node_) : node(node_) {}

    const MyNode &node;

    T operator()() const {

        T t;
        if (myt<T>::abc(node, t))
            return t;
        throw "err";
    }
};

int main(int argc, char **argv) {
    //label myl;
    MyNode mn1;

    bool d = myt<int>::def();
    std::cout << d << std::endl;
    auto rl = mn1.as<label>();
    std::cout << rl.app << std::endl << rl.image << std::endl;
}