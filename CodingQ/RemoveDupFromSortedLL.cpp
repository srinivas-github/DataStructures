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
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = (*headRef);
    (*headRef) = temp;
}

void printLL(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

void removeDups(struct Node* head)
{
    struct Node* current = head;
    struct Node* next_next;

    if (current == NULL);
        return;

    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
   }
}

int main()
{
    struct Node* head = NULL;
    push(&head, 8);
    push(&head, 7);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 5);
    push(&head, 4);
    push(&head, 2);
    printLL(head);
    removeDups(head);
    printLL(head);
    return 0;
}
