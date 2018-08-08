#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

void printLL(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

void push(struct Node** head_ref, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = (*head_ref);
    (*head_ref) = temp;
}

struct Node* sortedIntersect(struct Node* a, struct Node* b)
{
    if (a == NULL || b == NULL)
        return NULL;
    if (a->data < b->data)
        return sortedIntersect(a->next, b);
    if (a->data > b->data)
        return sortedIntersect(a, b->next);
        
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = a->data;
    temp->next = sortedIntersect(a->next, b->next);
    return temp;
}

int main()
{
    struct Node* a = NULL;
    push(&a, 9);
    push(&a, 8);
    push(&a, 7);
    push(&a, 6);
    push(&a, 5);
    
    struct Node* b  = NULL;
    push(&b, 10);
    push(&b, 9);
    push(&b, 8);
    push(&b, 6);
    struct Node* result = sortedIntersect(a, b);
    printLL(result);
    return 0;   
}
