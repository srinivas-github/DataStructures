#include <iostream>
using namespace std;

class Integer
{
    int i;
public:
    Integer(int ii = 0): i(ii){ }
    //prefix
    friend const Integer& operator++(Integer& rv);

    //postfix
    friend const Integer operator++(Integer& rv, int);
};

//prefix: return the incremented value
const Integer& operator++(Integer& rv)
{
    std::cout<<"operator++ prefix"<<"\n";
    rv.i++;
    return rv;
}

//postfix: return the value before increment
const Integer operator++(const Integer& rv, int)
{
    std::cout<<"operator++ postfix"<<"\n";
    Integer before(rv.i);
    rv.i++;
    return before;
}

void f(Integer a)
{
    ++a;
    a++;
}

int main()
{
    Integer i;
    f(i);
    return 0;
}


