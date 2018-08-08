#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

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

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapPairwise(struct Node* head)
{
    struct Node* temp = head;
    
    while (temp != NULL && temp->next != NULL)
    {
        swap(&temp->data, &temp->next->data);
        temp = temp->next->next;
    }
    
    
}

int main()
{
    struct Node* head = NULL;
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("Before pairwise swap:\n");
    printLL(head);
    printf("\nAfter pairwise swap:\n");
    swapPairwise(head);
    printLL(head);
    return 0;   
}
