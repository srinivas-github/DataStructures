/**
 * Given a list of tickets, find itinerary in order using the given list.
 * Example:
 * Input:
 * "Chennai" -> "Banglore"
 * "Bombay" -> "Delhi"
 * "Goa"    -> "Chennai"
 * "Delhi"  -> "Goa"
 *
 * Output: 
 * Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore
 *
 * Steps:
 * 1) Create a HashMap of given pair of tickets.  Let the created 
 *    HashMap be 'dataset'. Every entry of 'dataset' is of the form 
 *    "from->to" like "Chennai" -> "Banglore"
 *
 * 2) Find the starting point of itinerary.
 *    a) Create a reverse HashMap.  Let the reverse be 'reverseMap'
 *       Entries of 'reverseMap' are of the form "to->form". 
 *       Following is 'reverseMap' for above example.
 *       "Banglore"-> "Chennai" 
 *       "Delhi"   -> "Bombay" 
 *       "Chennai" -> "Goa"
 *       "Goa"     ->  "Delhi"
 * 
 *    b) Traverse 'dataset'.  For every key of dataset, check if it
 *       is there in 'reverseMap'.  If a key is not present, then we 
 *       found the starting point. In the above example, "Bombay" is
 *       starting point.
 *
 * 3) Start from above found starting point and traverse the 'dataset' 
 *    to print itinerary.
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

void printItinerary(std::map<std::string, std::string> dataSet)
{
    std::map<std::string, std::string> reverseDataSet;
    std::map<std::string, std::string>::iterator it;

    /**
     * Construct a reverse data set
     */
    for (it = dataSet.begin(); it != dataSet.end(); it++)
        reverseDataSet[it->second] = it->first;

    /**
     * find the starting point
     */
    std::string start;
    for(it = dataSet.begin(); it != dataSet.end(); it++)
    {
        if (reverseDataSet.find(it->first) == reverseDataSet.end())
        {
            start = it->first;
            break;
        }
    }

    if (start.empty())
    {
        std::cout<<"Invalid input\n";
        return ;
    }

    it = dataSet.find(start);
    while (it != dataSet.end())
    {
        std::cout<<it->first<<"->"<<it->second<<"\n";
        it = dataSet.find(it->second);
    }
}

int main()
{
    std::map<std::string, std::string> dataSet;
    dataSet["Chennai"] = "Banglore";
    dataSet["Bombay"] = "Delhi";
    dataSet["Goa"] = "Chennai";
    dataSet["Delhi"] = "Goa";
    
    printItinerary(dataSet);
    return 0;
}
