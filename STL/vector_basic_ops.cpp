#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    first.assign(7, 100);

    std::vector<int>::iterator it;
    it = first.begin()+1;
    second.assign(it, first.end()-1);

    int myInts[] = {1776, 56, 3};
    third.assign(myInts, myInts+3);

    std::cout<<" Size of first:"<<first.size()<<"\n";
    std::cout<<" Size of first:"<<second.size()<<"\n";
    std::cout<<" Size of third"<<third.size()<<"\n";



    //at operation
    std::vector<int> vInts(10);
    for (int i = 0; i < vInts.size(); i++)
        vInts.at(i) = i;

    for(std::vector<int>::iterator it = vInts.begin(); it != vInts.end(); it++)
        std::cout<<*it<<"  ";

    //back method
    std::vector<int> bVec;
    bVec.push_back(10);
    while ( bVec.back() != 0)
        bVec.push_back(bVec.back()-1);

    std::cout<<"bVec contains:"<<"\n";
    for (unsigned i = 0; i < bVec.size(); i++)
        std::cout<<' '<<bVec[i];
    std::cout<< "\n";     
    return 0;
}
