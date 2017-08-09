#include <iostream>
using namespace std;

class Integer
{
    int i;
public:
   Integer(int ii): i(ii){}
   const Integer operator+(const Integer& rv)
   {
       std::cout<<"operator+"<<"\n";
       return Integer(i + rv.i);
   }

   Integer& operator+=(const Integer& rv)
   {
       std::cout<<"operator+="<<"\n";
       i += rv.i;
       return *this;
   }
};

int main()
{
    int i = 1, j = 2, k = 3;
    i += j + k;
    std::cout<<"user defined types:"<<"\n";
    Integer ii(1), jj(2), kk(3);
    kk += ii +jj;
    return 0;
}
