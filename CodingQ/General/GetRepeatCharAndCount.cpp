#include <iostream>

using namespace std;
const int NO_OF_CHARS = 256;

void fillCharCounts(char* str, int* count)
{
    int i = 0;
    for( i = 0; *(str+i); i++)
        count[*(str+i)]++;
}

void getDupCharCount(char* str)
{
    int* count = (int*)calloc(NO_OF_CHARS, sizeof(int));
    fillCharCounts(str, count);
    
    for(int i = 0; i < NO_OF_CHARS; i++)
    {
        if ( count[i] > 1)
            printf("%c count is: %d\n", i, count[i]);
    }
    free(count);
}

int main()
{
    char textStr[] = "malayalam";
    getDupCharCount(textStr);

    return 0;
}
