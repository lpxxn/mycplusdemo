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

    C(const C& c)
    {
        std::cout << "C(const C& c)" << std::endl;
    }

    int *ptrInt;
    int valueInt;   
private:         
};

int main() {
    C c1(2);
    C c2(3);
    c2=c1;
    std::cout << "c1 ptrInt: " << c1.ptrInt << " value: " << *c1.ptrInt << std::endl;
    std::cout << "c2 ptrInt: " << c2.ptrInt << " value: " << *c2.ptrInt << std::endl;
    std::cout << "c2 valueInt: " << c2.valueInt << std::endl;
    c1.delIntV();
    // 地址是相同的 
    // delete 后可访问，只是delte分配的空间，但并不修改他的值
    // windows 上这个 *c2.ptrInt 是负，不同的编译器，行为不一样
    std::cout << "c2 ptrInt: " << c2.ptrInt << " value: " << *c2.ptrInt << std::endl;
    std::cout << "c2 valueInt: " << c2.valueInt << std::endl;
    //std::cin.get();
    return 0;
}

/*
https://stackoverflow.com/questions/1930459/c-delete-it-deletes-my-objects-but-i-can-still-access-the-data

In most cases, yes. Calling delete doesn't zero the memory.

Note that the behavior is not defined. Using certain compilers, the memory may be zeroed. When you call delete, what happens is that the memory is marked as available, so the next time someone does new, the memory may be used.

If you think about it, it's logical - when you tell the compiler that you are no longer interested in the memory (using delete), why should the computer spend time on zeroing it.

Delete doesn't delete anything -- it just marks the memory as "being free for reuse". Until some other allocation call reserves and fills that space it will have the old data. However, relying on that is a big no-no, basically if you delete something forget about it.

One of the practices in this regard that is often encountered in libraries is a Delete function:

template< class T > void Delete( T*& pointer )
{
    delete pointer;
    pointer = NULL;
}
This prevents us from accidentally accessing invalid memory.

Note that it is perfectly okay to call delete NULL;.
*/