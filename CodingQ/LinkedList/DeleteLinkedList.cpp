#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = *head_ref;
    *head_ref = temp;
}

void printLL(struct Node* head)
{
    struct Node* temp = head;
    for (; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}
void reverse(struct Node** head_ref)
{
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    struct Node* next;
    
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void deleteList(struct Node** head_ref)
{
    struct Node* current = *head_ref;
    struct Node* next;
    
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

int main()
{
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    push(&head, 60);
    push(&head, 70);
    push(&head, 80);
    push(&head, 90);
    push(&head, 100);
    printf("List: \n");
    printLL(head);
    reverse(&head);
    printf("Reverse:\n");
    printLL(head);
    
    printf("Deleting the List:\n");
    deleteList(&head);
    printf("Deleted the List\n");
    
    return 0;
}
