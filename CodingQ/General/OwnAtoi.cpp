#include <cstdio>

int myAtoi(char* str)
{
    int res = 0;
    for( int i = 0 ; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';

    return res;
}


/**
 * To handle negative (-ve) numbers
 */
int myAtoi_v2(char* str)
{
    int sign = 1;
    int i = 0;
    int res = 0;

    if (str[0] == '-')
    {
        sign = -1;
        ++i;
    }
    for(; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';

    return sign*res;

}

/**
 * To handle Error cases..
 */
bool isNumeric(char x)
{
    return ( x >= '0' && x <= '9') ? true:false;
}

int myAtoi_v3(char* str)
{
    int sign = 1;
    int i = 0; 
    int res = 0;

    if (str[0] == '-')
    {
        sign = -1;
        ++i;
    }
    for(; str[i] != '\0'; ++i)
    {
        if (isNumeric(str[i]) == false)
            return 0;
        res = res*10 + str[i] - '0';
    }
    return res*sign;

}
int main()
{
    char str[] = "8798";
    int res = myAtoi(str);
    printf("The Value: %d\n", res);

    char str2[] = "-2345";
    int r2 = myAtoi_v2(str2);
    printf("The value: %d\n", r2);

    char str3[] = "-324";
    int r3 = myAtoi_v3(str3);
    printf("Res3 = %d\n", r3);
    return 0;
}
