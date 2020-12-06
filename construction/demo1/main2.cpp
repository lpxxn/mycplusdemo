#include<iostream>

class C 
{
public:
    C(int v)
    {
        ptrInt = new int;
        *ptrInt = v;
        valueInt = v;
    }
    void setV(int v) {
        *ptrInt = v;
    }
    
    virtual ~C()
    {

    }     
    void delIntV() {
        valueInt = 0;
        delete ptrInt;
        ptrInt = nullptr;
        //ptrInt = NULL;
    }   

    // 副本构造器(copy constructor)
    C(const C& c)
    {
        std::cout << "C(const C& c)" << std::endl;
        // 调用 C& operator=
        *this = c;
    }

    C& operator=(const C &c) 
    {
        std::cout << "C& operator=(" << std::endl;
        if (this != &c) {
            if (ptrInt != NULL || ptrInt != nullptr || !ptrInt) {
                std::cout << "p is not null delete ptrInt" << std::endl;
                delete ptrInt;
            }
            ptrInt = new int;
            *ptrInt = *c.ptrInt;
            valueInt = c.valueInt;
        }
        return *this;
    }

    //int *ptrInt;
    int *ptrInt = nullptr;
    int valueInt;   
private:         
};

int main() {
    C c1(2);
    C c2(3);
    // C& operator=
    c2=c1;
    std::cout << "c1 ptrInt: " << c1.ptrInt << " value: " << *c1.ptrInt << std::endl;
    std::cout << "c2 ptrInt: " << c2.ptrInt << " value: " << *c2.ptrInt << std::endl;
    std::cout << "c2 valueInt: " << c2.valueInt << std::endl;
    c1.delIntV();
    // 地址是不同的 
    std::cout << "c2 ptrInt: " << c2.ptrInt << " value: " << *c2.ptrInt << std::endl;
    std::cout << "c2 valueInt: " << c2.valueInt << std::endl;

    C c3(2);
    // C(const C& c)  副本构造器(copy constructor)
    C c4(c3);
    std::cout << "c3 ptrInt: " << c3.ptrInt << " value: " << *c3.ptrInt << std::endl;
    std::cout << "c4 ptrInt: " << c4.ptrInt << " value: " << *c4.ptrInt << std::endl;
    std::cout << "c4 valueInt: " << c4.valueInt << std::endl;
    c1.delIntV();
    // 地址是不同的 
    std::cout << "c2 ptrInt: " << c4.ptrInt << " value: " << *c4.ptrInt << std::endl;
    std::cout << "c2 valueInt: " << c4.valueInt << std::endl;
    //std::cin.get();
    return 0;
}

/*
对象可以使用*this。this是对象的地址，而不是对象本身。

*this是对象本身。可以将*this 作为调用对象的别名

Stock::Stock(const std::string &name)
{
    this->m_company=name;
    (*this).m_company="123";
}
*/