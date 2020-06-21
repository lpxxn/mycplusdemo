#include<iostream>

class C 
{
public:
    C(int v)
    {

    }
    virtual ~C()
    {

    }     
    void DelIntV() {
        valueInt =0;
        delete ptrInt;
    }   
private:
    int *ptrInt;
    int valueInt;        
};