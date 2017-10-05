/**
 * Rotate a Linked List
 * Given a singly linked list, rotate the linked list counter-clockwise by k nodes.
 * Where k is a given positive integer. 
 * For example, if the given linked list is 10->20->30->40->50->60 and k is 4, then
 * list should be modified to 50->60->10->20->30->40. 
 * Assume that k is smaller than the count of nodes in linked list.
 *
 * Solution:
 * 1. Change next of kth node to NULL, 
 * 2. next of last node to previous head node, 
 * 3. and finally change head to (k+1)th node. 
 * So we need to get hold of three nodes: kth node, (k+1)th node and last node.
 */

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
