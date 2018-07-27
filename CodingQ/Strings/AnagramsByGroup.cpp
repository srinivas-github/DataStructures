#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

void printAnagrams(unordered_map<string, vector<string> >& store)
{
    unordered_map<string, vector<string> >::iterator itr = store.begin();
    for(; itr != store.end(); itr++)
    {
        vector<string> tempVec(itr->second);
        int sz = tempVec.size();
        
        if ( sz > 1)
        {
            for(int i = 0; i < sz; i++)
                cout<<tempVec[i]<<" ";
            
        }
    }
}

void storeInMap(std::vector<std::string>& vecStr)
{
    unordered_map<string, vector<string> >store;
    
    for( int i = 0; i < vecStr.size(); i++)
    {
        string temp_str(vecStr[i]);
        sort(temp_str.begin(), temp_str.end());
        
        if (store.find(temp_str) == store.end())
        {
            vector<string> tempVec;
            tempVec.push_back(vecStr[i]);
            store.insert(make_pair(temp_str, tempVec));
        }
        else
        {
            vector<string> tempVec(store[temp_str]);
            tempVec.push_back(vecStr[i]);
            store[temp_str] = tempVec;
        }
    }
    
    printAnagrams(store);
}

int main()
{
    std::vector<std::string> arr;
    arr.push_back("dog");
    arr.push_back("god");
    arr.push_back("ate");
    arr.push_back("eat");
    arr.push_back("act");
    arr.push_back("tac");
    
    storeInMap(arr);
    return 0;
}
