#include <cstdio>
#define OUT 0
#define IN 1

unsigned countWords(char* str)
{
    int state = OUT;
    unsigned wc = 0;
    while(*str)
    {
        if (*str == ' ' || *str == '\n' || *str == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++wc;
        }
        str++;
    }
    return wc;
}

int main()
{
    char* str = "This is\t not\n  a word\n has a many spaces";
    unsigned wc = countWords(str);
    printf("Word Count: %d\n", wc);
    return 0;
}
