#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void missingAndRepeatNum(int arr[], int sz)
{
    int temp[sz];
    for (int i = 0; i < sz; i++)
        temp[i] = 0;

    int repeat = 0;
    int missing = 0;

    for (int i = 0; i < sz; i++)
    {
        if (temp[arr[i]] == 0)
            temp[arr[i]] = 1;
        else if (temp[arr[i]] == 1)
           repeat = arr[i];
    }
    for (int i =0; i < sz; i++)
    {
        if (temp[i] == 0)
            missing = i;
    }
    std::cout<<"Missing: "<<missing<<" Repeating: "<<repeat<<"\n";
}

void missingAndRepeatNum_v2(int arr[], int sz)
{
   int i;
   std::cout<<"Repeating element: ";
   for (i = 0; i < sz; i++)
   {
       if (arr[abs(arr[i])-1]> 0)
           arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
       else
           std::cout<<abs(arr[i]);
   }
   std::cout<<"\n Mising element: ";
   for(i = 0; i < sz; i++)
       if (arr[i] > 0 )
           std::cout<<i+1<<"\n";
}

int main()
{
    int arr[] = {1,3,6,2,3,4,7,8,9,10};
    int sz = sizeof(arr)/sizeof(arr[0]);
    //missingAndRepeatNum(arr, sz);
    missingAndRepeatNum_v2(arr, sz);
    return 0;
}
