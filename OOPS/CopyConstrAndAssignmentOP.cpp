#include <cstdio>
#include <stdlib>
using namespace std;

class SmartArray
{
    private:
        int m_size;
        int* m_data;
    public:
        SmartArray(int size = 100);
        SmartArray(const SmartArray& rSA);
        SmartArray& operator=(const SmartArray& rSA);
        ~SmartArray();
};

SmartArray::SmartArray(int size)
{
    m_size = size;
    for(int i = 0; i < m_size; i++)
        m_data[i] = 0;
}

SamrtArray::~SmartArray()
{
    delete []m_data;
}

SmartArray::SmartArray(const SmartArray& rSA)
{
    m_size = rSA.m_size;
    m_data = new int[m_size];
    for(int i = 0; i < m_size; i++)
    {
        m_data[i] = rSA.m_data[i];
    }
}

SmartArray& SmartArray::operator=(const SmartArray& rSA)
{
    if (this != &rSA)
    {
        delete []m_data;
        m_size = rSA.m_size;
        for(int i = 0; i < m_size; i++)
            m_data[i] = rSA.m_data[i];
    }
    return (*this);
}
