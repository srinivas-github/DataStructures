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

void printList(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

void rotateList(struct Node** headRef, int k)
{
    struct Node* current = *headRef;
    int cnt = 1;
   
    if (k ==0 )
        return ;


    while ( cnt < k && current != NULL)
    {
        current = current->next;
        cnt++;
    }

    if (current == NULL)
        return ;

    struct Node* KthNode = current;
  
    while (current->next != NULL)
        current = current->next;

    current->next = *headRef;
    *headRef = KthNode->next;
    KthNode->next = NULL;
  
}

int main()
{
    struct Node* head = NULL;
    for(int i  = 60; i>= 10; i-= 10)
        push(&head, i);
    printList(head);
    rotateList(&head, 4);
    printList(head);
    return 0;
}
