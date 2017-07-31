#include <iostream>
#include <set>

int main()
{
    std::set<int> mySet;
    for (int i = 0; i <=5; i++)
        mySet.insert(i*10);
    std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
    ret = mySet.equal_range(30);
    std::cout<<"Lower Bound: "<<*ret.first<<"\n";
    std::cout<<"Upper Bound: "<<*ret.second<<"\n";
    return 0;
}
