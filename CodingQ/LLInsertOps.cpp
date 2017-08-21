#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** headRef, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data= data;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void insertAfter(struct Node* prev_node, int data)
{
    if (prev_node ==  NULL)
       return ;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}

void append(struct Node** headRef, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node* last = *headRef;
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return ;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}

void printLL(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL ; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

int main()
{
    struct Node* head = NULL;
    append(&head, 10);
    push(&head, 9);
    push(&head, 8);
    append(&head, 11);
    insertAfter(head->next, 1);
    printLL(head);
    return 0;
}
