#include <cstdio>
#include <cstdlib>
#define bool int
struct Node
{
    char data;
    struct Node* next;
};

void push(struct Node** headRef, char data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Stack overflow\n");
        return ;
    }
 
    temp->data = data;
    temp->next = *headRef;
    *headRef  = temp;
}

int pop(struct Node** topRef)
{
    char res;
    struct Node* top;
    if (*topRef == NULL)
        return -1;
    else
    {
        top = *topRef;
        res = top->data;
        *topRef = top->next;
        free(top);
        return res;
    }
}

bool isMatchingPair(char c1, char c2)
{
    printf("Received: %c - %c\n", c1, c2);

    if (c1 == '{' && c2 == '}')
        return 1;
    else if (c1 == '[' && c2 == ']')
        return 1;
    else if (c1 == '(' && c2 == ')')
        return 1;
    else 
        return 0;
}

bool areParenthesisBalanced(char exp[])
{
    int i  = 0;
    struct Node* stack = NULL;

    while (exp[i])
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(' )
        {
            push(&stack, exp[i]);
        }
        if (exp[i] = '}' || exp[i] == ']' || exp[i] == ')' )
        {
            if (stack == NULL)
            {
                printf("Reached here2..\n");
                return 0;
            }
            else if (!isMatchingPair(pop(&stack), exp[i]))
            {
               printf("Reached here3...\n");
               return 0;
            }
        }
        i++;
    }
    if (stack == NULL)
    {
        printf("Reahjed here\n");
        return 1;
    }
    else
        return 0;
}

int main()
{
    char exp[100] = "[]";
    if (areParenthesisBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
