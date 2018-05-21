/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
const int NO_OF_CHARS = 256;

int* getCharCounts(char* str)
{
    int* count = (int*)calloc(NO_OF_CHARS, sizeof(int));
    int i = 0;
    for( i = 0; *(str+i); i++)
        count[*(str+i)]++;
    return count;
}

char* removeCharsFromStr1(char* str, char* mask_str)
{
   int *count = getCharCounts(mask_str);
   int res_ind = 0;
   int ip_ind = 0;
   
   while ( *(str+ip_ind))
   {
       char temp = *(str+ip_ind);
       if (count[temp] == 0)
       {
           *(str+res_ind) = *(str+ip_ind);
           res_ind++;
       }
       ip_ind++;
   }
   *(str+res_ind) = '\0';
   return str;
}

int main()
{
    char str[] = "malayalammanthika";
    char mask_str[] = "malt";
    printf("Result str= %s\n", removeCharsFromStr1(str, mask_str));
    return 0;
}
