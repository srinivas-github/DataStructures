#include <cstdio>
using namespace std;
#define MAX_CHARS 256

char getSecondMostFreq(char* str)
{
    int count[MAX_CHARS] = {0};
    int i;

    for(i = 0; str[i]; i++)
        (count[str[i]])++;

    int first = 0;
    int second = 0;
    for(i = 0; i < MAX_CHARS; i++)
    {
        if (count[i] > count[first])
        {
            second = first;
            first = i;
        }
        else if (count[i] > count[second] && count[i] != count[first])
            second = i;
    }
    return second;
}

int main()
{
    char str[] = "acbssseeddsseesdee";
    char res = getSecondMostFreq(str);
    printf("Second Most Freq Char:  %c, %d\n", res, res);
    return 0;
}
