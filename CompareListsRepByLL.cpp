#include <cstdio>
#include <cstdlib>
#include <iostream>
struct Node
{
    char c;
    struct Node* next;
};

void push(struct Node** head_ref, char c)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->c = c;
    temp->next = (*head_ref);
    (*head_ref) = temp;
}

int compare(struct Node* l1, struct Node* l2)
{
    while(l1 && l2 && l1->c == l2->c)
    {
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 && l2)
        return (l1->c > l2->c)?1:-1;
    if (l1 && !l2)
        return 1;;
    if (l2 && !l1)
        return -1;
    return 0;
}

int main()
{
    struct Node* h1 = NULL;
    push(&h1, 'm');
    push(&h1, 'a');
    push(&h1, 'd');
    push(&h1, 'a'); 
    push(&h1, 'm');

    struct Node* h2 = NULL;
    push(&h2, 'm');
    push(&h2, 'a');
    push(&h2, 'd');
    push(&h2, 'a');
    push(&h2, 'm');
    std::cout<<compare(h1, h2)<<"\n";
    return 0;
}

