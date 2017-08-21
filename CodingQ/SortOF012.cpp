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

void SortOf012(struct Node* head)
{
    struct Node* ptr = head;
    int count[3] = {0,0,0};
    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }

    ptr = head;
    int i =0;
    while (ptr != NULL)
    {
        if (count[i] == 0)
        {
            ++i;
        }
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}


int main()
{
    struct Node* head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 0);
    push(&head, 1);
    push(&head, 2);
    push(&head, 2);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 0);
    printLL(head);
    SortOf012(head);
    printLL(head);
    return 0;
}
