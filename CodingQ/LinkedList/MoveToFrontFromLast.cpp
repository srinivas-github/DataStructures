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

void moveToFront(struct Node** head_ref)
{
    struct Node* last;
    struct Node* secLast;
    
    if( (*head_ref) == NULL|| (*head_ref)->next == NULL)
        return ;
    last = *head_ref;
    
    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
    
    secLast->next = NULL;
    last->next = (*head_ref);
    (*head_ref) = last;
}

int main()
{
    struct Node* head = NULL;
    push(&head, 60);
    push(&head, 40);
    push(&head, 60);
    push(&head, 40);
    push(&head, 20);
    push(&head, 10);
    push(&head, 60);
    push(&head, 10);
    push(&head, 20);
    printf("Before moving last to head:\n");
    printLL(head);
    printf("\nAfter moving last to head:\n");
    moveToFront(&head);
    printLL(head);
    return 0;   
}
