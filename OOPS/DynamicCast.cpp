#include <iostream>
#include <exception>
using namespace std;

class Base
{
};

class Derived: public Base
{
};

class Base1
{
    public:
    virtual void dummy(){}
};

class Derived1: public Base1
{
    int a;
};

int main()
{

#if 0
    //Example 1
    Base a;
    Base *ptr_a;

    Derived b;
    Derived *ptr_b;
    ptr_a = dynamic_cast<Base*>(&b);

    //ptr_b = dynamic_cast<Derived*>(&a); //Error: cannot dynamic_cast type Base* to type Derived* (source type is not polymorphic)
    return 0;
#endif
    try
    {
        Base1 *ptr_a = new Derived1;
        Base1 *ptr_b = new Base1;
        Derived1 *ptr_c;
        ptr_c = dynamic_cast<Derived1*>(ptr_a);
        if (ptr_c == NULL)
            std::cout<<"NULL Pointer on first cast"<<"\n";
        ptr_c = dynamic_cast<Derived1*>(ptr_b);
        if (ptr_c == NULL)
            std::cout<<"NULL Pointer on first cast"<<"\n";
    }
    catch(exception& my_ex)
    {
        std::cout<<"Exception: "<<my_ex.what()<<"\n";
    }

    return 0;
}


