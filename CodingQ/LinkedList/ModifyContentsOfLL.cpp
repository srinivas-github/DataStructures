#include <cstdio>
#include <cstdlib>
using namespace std;
/**
 * Modify the first half of the LL with second half of LL
 * Example: 12 -> 10 -> -8 -> 6 -> 9 -> 45 -> 5
 * O/P:     7-> -35 -> 1 -> 6 -> 9 -> 45 -> 5
 *
 * Solution:
 * 1. Split the List into two halfs
 * 2. Reverse the second half
 * 3. Update first half with second half
 * 4. reverse the second half again
 * 5. concat both the lists
 */

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** headRef, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void reverse(struct Node** headRef)
{
    struct Node* current = *headRef;
    struct Node* prev = NULL;
    struct Node* next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*headRef) = prev;
}

void frontBackSplit(struct Node* head, struct Node** frontRef, struct Node** backRef)
{
    struct Node* slow;
    struct Node* fast;

    if (head == NULL || head->next == NULL)
    {
        *frontRef = head;
        *backRef = NULL;
    }
    else
    {
        slow  = head;
        fast = head->next;
        while (fast != NULL)
        {   
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }    
        *frontRef = head;
        *backRef = slow->next;
        slow->next = NULL;
   }
}

void modifyContentsOfFirstHalf(struct Node* front, struct Node* back)
{
    while (back != NULL)
    {
        front->data = (front->data - back->data);
        front = front->next;
        back = back->next;
    }
}

struct Node* concatTwoLists(struct Node* front, struct Node* back)
{
    struct Node* head = front;
    while (front->next != NULL)
    {
        front = front->next;
    }
    front->next = back;

    return head;
}

struct Node* modifyTheList(struct Node* head)
{
    if (!head || head->next == NULL)
        return head;

    struct Node* front, *back;
    frontBackSplit(head, &front, &back);
    reverse(&back);
    modifyContentsOfFirstHalf(front, back);
    reverse(&back);
    head = concatTwoLists(front, back);
    return head;
}

void printLL(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

int main()
{
    struct Node* head = NULL;
    push(&head, 20);
    push(&head, 15);
    push(&head, -30);
    push(&head, 1);
    push(&head, 12);
    push(&head, 25);
    push(&head, 20);

    printLL(head);
    head = modifyTheList(head);
    printLL(head);
    return 0;
}
