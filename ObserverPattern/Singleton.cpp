#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton s;
    int i;
    Singleton(int x):i(x){ }
    Singleton(const Singleton&);
    Singleton& operator=(Singleton&);
public:
    static Singleton& instance()
    {
        return s;
    }
    int getVal() const {
        return i;
    }
    void setVal(int x) {
        i = x;
    }
};

Singleton Singleton::s(47);
int main()
{
    Singleton& s = Singleton::instance();
    std::cout<<s.getVal()<<"\n";
    Singleton& s2 = Singleton::instance();
    s2.setVal(9);
    std::cout<<s.getVal()<<"\n";
  
    return 0;
}
