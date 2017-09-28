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
    temp->next = *headRef;
    *headRef = temp;
}

void printLL(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

void deleteNode(struct Node** headRef, int pos)
{
    struct Node* temp = *headRef;
    if (*headRef == NULL)
        return ;
    if (pos == 0)
    {
        *headRef = temp->next;
        free(temp);
        return ;
    }

    int i = 0;
    for ( i = 0; temp != NULL && i < pos-1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return ;

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main()
{
    struct Node* node = NULL;
    push(&node, 7);
    push(&node, 17);
    push(&node, 3);
    push(&node, 6);
    push(&node, 10);
    push(&node, 12);
    push(&node, 4);
    push(&node, 55);
    push(&node, 8);

    printLL(node);
    deleteNode(&node, 7);
    printLL(node);

    return 0;
}
