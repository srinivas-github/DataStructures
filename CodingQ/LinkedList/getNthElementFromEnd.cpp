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

int getNthFromEnd(struct Node* head, int n)
{
    int len = 0;
    struct Node* temp = head;
    
    while ( temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    
    temp = head;
    if ( n > len)
    {
        printf("Invalid value..");
        return -1;
    }
    
    for (int i = 1; i < (len-n)+1; i++)
        temp = temp->next;
    
    return temp->data;
}
int getNthFromEnd_v2(struct Node* head, int n)
{
    struct Node* main_ptr = head;
    struct Node* ref_ptr = head;
    int count = 0;
    if (head != NULL)
    {
        while(count < n)
        {
            if (ref_ptr == NULL)
            {
                printf("Invalid count...\n");
                return -1;
            }
            ref_ptr = ref_ptr->next;
            count++;
        }
    }
    
    while (ref_ptr != NULL)
    {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }
    return main_ptr->data;
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
    int n = 4;
    printf("%dth Element from End of LL: %d \n", n, getNthFromEnd(head, n));
    printf("%dth Element from End of LL: %d \n", n, getNthFromEnd_v2(head, n));
    return 0;
}
