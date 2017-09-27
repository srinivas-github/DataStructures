#include <cstdio>
#include <cstdlib>

int* getCharCountArr(char* str)
{
    int* count = (int*)calloc(sizeof(int), 256);
    for (int i = 0; *(str+i); i++)
        count[*(str+i)]++;
    return count;
}

int firstNonRepeatingChar(char* str)
{
    int* count = getCharCountArr(str);
    int index = -1;
    for (int i = 0; i < *(str+i); i++)
    {
        if (count[*(str+i)] == 1)
        {
            index = i;
            break;
        }
    }
    free(count);
    return index;
}

int main()
{
    char str[] = "srinivas";
    int index = firstNonRepeatingChar(str);
    if (index == -1)
        printf("No non repeating chars\n");
    else
        printf("first non-repeat char: %c\n", str[index]);
    return 0;
}

