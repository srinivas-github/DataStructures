#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool my_compare(std::string X, std::string Y)
{
    std::string XY = X.append(Y);
    std::string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1:0;
    
}

void largestNumber(std::vector<std::string> strNum)
{
    std::sort(strNum.begin(), strNum.end(), my_compare);

    for(int i = 0; i < strNum.size(); i++)
        std::cout<<strNum[i];    
}

int main()
{
    std::vector<std::string> arr;
    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    largestNumber(arr);
    return 0;
}
