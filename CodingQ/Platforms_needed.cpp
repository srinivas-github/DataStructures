#include <iostream>
#include <algorithm>

using namespace std;

int platforms_needed(int arr[], int dep[], int n)
{
    int plat_needed = 1;
    int result = 1;
    int i = 1; 
    int j = 0;

    while (i < n && j < n)
    {
        if (arr[i] < dep[j])
        {
            plat_needed++;
            i++;
            if (plat_needed > result)
                result = plat_needed;
        }
        else
        {
            plat_needed--;
            j++;
        }
    }
    return result;
}

int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr)/sizeof(arr[0]);

    int pNeeded = platforms_needed(arr, dep, n);
    std::cout<<"No. of platforms needed: "<<pNeeded<<"\n";
    return 0;   
}
