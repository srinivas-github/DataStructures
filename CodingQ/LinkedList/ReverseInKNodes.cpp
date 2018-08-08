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

struct Node* reverseInKnodes(struct Node* head, int k)
{
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int count = 0;
    
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    
    if (next != NULL)
        head->next = reverseInKnodes(next, k);
    return prev;
}

int main()
{
    struct Node* a = NULL;
    push(&a, 7);
    push(&a, 8);
    push(&a, 9);
    push(&a, 4);
    push(&a, 5);
    push(&a, 6);
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    int k  = 3;
    printf("Before:\n");
    printLL(a);
    struct Node* result = reverseInKnodes(a, k);
    printf("\nAfter: \n");
    printLL(result);
    return 0;   
}
