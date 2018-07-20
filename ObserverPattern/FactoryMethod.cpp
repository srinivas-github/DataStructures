#include <iostream>
using namespace std;

enum VehicleType
{
    VT_TwoWheeler,
    VT_ThreeWheeler,
    VT_FourWheeler
};

class Vehicle
{
    public:
    virtual void printVehicle() = 0;
    static Vehicle* Create(VehicleType type);
};

class TwoWheeler: public Vehicle
{
   public:
       void printVehicle()
       {
           std::cout<<"Two Wheeler\n";
       }
};

class ThreeWheeler: public Vehicle
{
   public:
       void printVehicle()
       {
           std::cout<<"Three Wheeler\n";
       }
};

class FourWheeler: public Vehicle
{
   public:
       void printVehicle()
       {
           std::cout<<"Four Wheeler\n";
       }
};

Vehicle* Vehicle::Create(VehicleType type)
{
    if (type == VT_TwoWheeler)
        return new TwoWheeler();
    else if (type == VT_ThreeWheeler)
        return new ThreeWheeler();
    else if (type == VT_FourWheeler)
        return new FourWheeler();
    else
        return NULL;
}

class Client
{
    private:
        Vehicle* vType;
    public:
        Client()
        {
            VehicleType type = VT_ThreeWheeler;
            vType = Vehicle::Create(type);
        }
        ~Client()
        {
            if (vType)
            {
                delete[] vType;
                vType = NULL;
            }
        }
        Vehicle* getVehicle()
        {
            return vType;
        }
};

int main()
{
    Client* pClient = new Client();
    Vehicle* vType = pClient->getVehicle();
    vType->printVehicle();
    return 0;
}
