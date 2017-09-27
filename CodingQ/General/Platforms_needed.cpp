/**
 * We can solve the above problem in O(nLogn) time. 
 * The idea is to consider all events in sorted order. 
 * Once we have all events in sorted order, we can trace the number of trains 
 * at any time keeping track of trains that have arrived, but not departed.
 * For Example:
 *  arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
 *  dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

 * All events sorted by time.
 * Total platforms at any time can be obtained by subtracting total 
 * departures from total arrivals by that time.
 *
 * Time     Event Type     Total Platforms Needed at this Time                               
 * 9:00       Arrival                  1
 * 9:10       Departure                0
 * 9:40       Arrival                  1
 * 9:50       Arrival                  2
 * 11:00      Arrival                  3 
 * 11:20      Departure                2
 * 11:30      Departure                1
 * 12:00      Departure                0
 * 15:00      Arrival                  1
 * 18:00      Arrival                  2 
 * 19:00      Departure                1
 * 20:00      Departure                0
 *
 * Minimum Platforms needed on railway station = Maximum platforms 
 *                                             needed at any time 
 *                                             = 3  
 */
 


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
