#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class IObserver
{
public:
   virtual void update(float price) = 0;
};

class Shop: public IObserver
{
   std::string name;
   float price;
public:
   Shop(std::string n):name(n)
   {
   }
   void update(float price)
   {
       this->price = price;
       std::cout<<"Price at "<<name<<" is now "<<price<< "\n";
   }
};


class ASubject
{
    std::vector<Shop*> shop_list;
public:
    void Attach(Shop* shop);
    void Dettach(Shop* shop);
    void Notify(float price);
};

void ASubject::Attach(Shop* shop)
{
   shop_list.push_back(shop);
}

void ASubject::Dettach(Shop* shop)
{
    shop_list.erase( std::remove(shop_list.begin(), shop_list.end(), shop), shop_list.end());
}

void ASubject::Notify(float price)
{
    std::vector<Shop*>::const_iterator itr = shop_list.begin();
    for(; itr != shop_list.end(); itr++)
    {
        if (*itr != 0)
            (*itr)->update(price);
    }
}

class DummyProduct: public ASubject
{
public:
    void ChangePrice(float price)
    {
        Notify(price);
    }
};

int main()
{
    DummyProduct product;

    Shop shop1("Shop1");
    Shop shop2("Shop2");

    product.Attach(&shop1);
    product.Attach(&shop2);
    product.ChangePrice(100.0f);
   
    product.Dettach(&shop2);

    product.ChangePrice(95.0f);
    return 0;
}
