#include <cstdio>
#include <cstdlib>
using namespace std;

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
}

void removeLoop(struct Node* loopNode, struct Node* head)
{
    struct Node* ptr1;
    struct Node* ptr2;
    ptr1 = head;

    while (1)
    {
        ptr2 = loopNode;
        while (ptr2->next != loopNode && ptr2->next != ptr1)
            ptr2 = ptr2->next;

        if (ptr2->next == ptr1)
            break;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
}

int detectAndRemoveLoop(struct Node* head)
{
    struct Node* slowP = head;
    struct Node* fastP = head;
 
    while (slowP && fastP && fastP->next)
    {
        slowP = slowP->next;
        fastP = fastP->next->next;
        if (slowP == fastP)
        {
            removeLoop(slowP, head);
            return 1;
        }
  
    }
    return 0;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");

}
int main()
{
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    head->next->next->next->next = newNode(50);
    head->next->next->next->next->next = newNode(60);
    head->next->next->next->next->next->next = head->next->next;
   //printList(head);
    int res = detectAndRemoveLoop(head);
    printList(head);
    return 0;
}
