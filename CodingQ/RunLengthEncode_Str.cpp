#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_RLEN 50

using namespace std;
char* encode(char* str)
{
    int len = strlen(str);
    char* dest = (char*)malloc(sizeof(char)*(len*2 + 1));
    char count[MAX_RLEN];

    int i, j=0, k;

    int rLen;

    for(i = 0; i < len; i++)
    {
        dest[j++] = str[i];
        rLen = 1;
        while ( i+1 < len && (str[i] == str[i+1]))
        {
            i++;
            rLen++;
        }     
        sprintf(count, "%d", rLen);
        for(k=0; *(count+k); k++, j++)
        {
            dest[j] = count[k];
        }
    }
    dest[j] = '\0';
    return dest;
}

int main()
{
    //char str[] = "sssdeefgfeggeerr"; //s3d1e2f1g1f1e1g2e2r2
    char str[] = "abcedefghijklmn";
    char* res = encode(str);    
    printf("Encoded Str: %s\n", res);
    return 0;
}
