/**
 * Given a singly linked list, with some positive numbers (valid numbers) and zeros (invalid numbers).
 * Convert the linked list in such a way that if next valid number is same as current number, double its
 * value and replace the next number with 0. After the modification, rearrange the linked list such that
 * all 0's are shifted to the end.
 *  Example:
 *  Input : 2->2->0->4->0->8
 *  Output : 4->4->8->0->0->0
 *
 *  Input :  0->2->2->2->0->6->6->0->0->8
 *  Output : 4->2->12->8->0->0->0->0->0->0
 */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* getNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* segValidAndInvalidNum(struct Node* head)
{
    struct Node* validStart = NULL,   *validEnd = NULL;
    struct Node* invalidStart = NULL, *invalidEnd = NULL;
    struct Node* current = head;

    while (current != NULL)
    {
        int element = current->data;
        if (element != 0)
        {
            if (validStart == NULL)
            {
                validStart = current;
                validEnd = validStart;
            }
            else
            {
                validEnd->next = current;
                validEnd = validEnd->next;
            }
        }
        else
        {
            if (invalidStart == NULL)
            {
                invalidStart = current;
                invalidEnd = invalidStart;
            }
            else
            {
                invalidEnd->next = current;
                invalidEnd = invalidEnd->next;
            }
        }
        current = current->next;
    }
    if (validStart == NULL || invalidStart == NULL)
        return head;

    validEnd->next = invalidStart;
    invalidEnd->next = NULL;
    head = validStart;
    return head;
}

void printLL(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");

}

struct Node* modifyAndRearrangeList(struct Node* head)
{
    if ( head == NULL || head->next == NULL)
        return head;

    struct Node* ptr = head;
    while (ptr && ptr->next)
    {
        if ( (ptr->data == 0) ||  ( ptr->data != ptr->next->data) )
            ptr = ptr->next;
        else
        {
            ptr->data = 2 * ptr->data;
            ptr->next->data = 0;
            ptr = ptr->next->next;
        }
    }
    return segValidAndInvalidNum(head);
}
int main()
{
    struct Node* head = NULL;
    head = getNode(2);
    head->next = getNode(2);
    head->next->next = getNode(0);
    head->next->next->next = getNode(4);
    head->next->next->next->next = getNode(0);
    head->next->next->next->next->next = getNode(8);
    printLL(head);
    head = modifyAndRearrangeList(head);
    printLL(head);
    return 0;
}
