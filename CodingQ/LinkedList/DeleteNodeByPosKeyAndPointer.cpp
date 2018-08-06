#include <cstdio>
#include <cstdlib>

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

void deleteNodeByPos(struct Node** head_ref, int position)
{
    if (*head_ref == NULL)
        return;
    struct Node* temp = *head_ref;
    
    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return ;
    }
    
    for (int  i = 0; temp != NULL && i < position-1; i++)
        temp = temp->next;
    
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void deleteNodeByKey(struct Node** head_ref, int key)
{
    struct Node* temp = *head_ref;
    struct Node* prev;
    
    if ( temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return ;
    }
    
    while ( temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL)
        return ;
    prev->next = temp->next;
    free(temp);
     
}
void deleteNodeByGivenPointer(struct Node* nodePtr)
{
    struct Node* temp = nodePtr->next;
    nodePtr->data = temp->data;
    nodePtr->next = temp->next;
    free(temp);
    
}

void printLL(struct Node* head)
{
    struct Node* temp = head;
    for (; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}
int main()
{
    struct Node* head = NULL;
    push(&head, 100);
    push(&head, 90);
    push(&head, 80);
    push(&head, 70);
    push(&head, 60);
    push(&head, 50);
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);
    printf("Before:\n");
    printLL(head);
    
    int pos = 0;
    deleteNodeByPos(&head, pos);
    printf("After: \n");
    printLL(head);
    
    printf("deleteNodeByKey:\n");
    deleteNodeByKey(&head, 80);
    printLL(head);
    
    printf("deleteNodeByGivenPointer:\n");
    deleteNodeByGivenPointer(head->next->next);
    printLL(head);
    return 0;
    
}
