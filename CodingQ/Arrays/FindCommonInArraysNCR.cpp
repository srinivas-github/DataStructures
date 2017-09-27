#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

void findCommon(int arr1[], int arr2[], int n, std::map<int,int>& rMap)
{
    for(int i = 0; i < n; i++)
    {
        rMap[arr1[i]];
    }
    std::cout<<"Common Elements are:";
    std::map<int, int>::iterator itr;

    for (int i = 0; i < n; i++)
    {
        if ( (itr = rMap.find(arr2[i])) != rMap.end())
            std::cout<<(*itr).first<<" ";
    }
    std::cout<<"\n";
}
int main()
{
    int arr1[] = {5,2,7,6,3,14,11};
    int arr2[] = {2,434,6,77,8,33,111};
    std::map<int, int> myMap;
    findCommon(arr1, arr1, sizeof(arr1)/sizeof(arr1[0]), myMap);
    std::map<int, int>::iterator itr = myMap.begin();
    for(; itr != myMap.end(); itr++)
        std::cout<<(*itr).first<<"  ";
    return 0;
}
