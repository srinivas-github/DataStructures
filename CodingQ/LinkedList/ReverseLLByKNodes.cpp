/**
 * Given pointer to the head node of a linked list and a number K, the task is
 * to reverse the first K nodes of the linked list.
 * Example:
 * Input : 1->2->3->4->5->6->7->8->9->10->NULL
 *         k = 3
 * Output :3->2->1->4->5->6->7->8->9->10->NULL
 *
 * Input :10->18->20->25->35->NULL
 *        k = 2
 * Output :18->10->20->25->35->NULL
 * Solution:
 * 1. Traverse List to till k-th node.
 * 2. Break the LL in two parts from k-th point
 * 3. Reverse the first half.
 * 4. Join the lists
 */

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
    temp->next = (*head_ref);
    (*head_ref) = temp;
}
void printLL(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

void reverseKNodes(struct Node** head_ref, int k)
{
    struct Node* temp = *head_ref;
    int count = 1;
    while (count < k)
    {
        temp = temp->next;
        count++;
    }
    struct Node* joint_point = temp->next;
    temp->next = NULL;

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

    current = *head_ref;
    while (current->next != NULL)
        current = current->next;

    current->next = joint_point;

}
int main()
{
    struct Node* head = NULL;
    int k = 3;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printLL(head);
    reverseKNodes(&head, k);
    printLL(head);
    return 0;
}
