#include <iostream>
using namespace std;

class Singleton
{
   private:
       static bool isInstance;
       static Singleton* single;
       Singleton() { }
   
   public:
       static Singleton* getInstance();
       void someMethod();
       ~Singleton()
       {
           isInstance = false;
       }
};

bool Singleton::isInstance = false;
Singleton* Singleton::single = NULL;

Singleton* Singleton::getInstance()
{
    if (!isInstance)
    {
        single = new Singleton();
        isInstance = true;
        return single;
    }
    else
    {
        return single;
    }
}

void Singleton::someMethod()
{
    std::cout<<"in someMethod\n";
}

int main()
{
    Singleton* sc1 = Singleton::getInstance();
    sc1->someMethod();
    
    Singleton* sc2 = Singleton::getInstance();
    sc2->someMethod();
    
    return 0;
}
