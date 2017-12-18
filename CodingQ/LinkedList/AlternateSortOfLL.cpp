/**
 * Given a linked list containing n nodes. The problem is to rearrange the
 * nodes of the list in such a way that the data in first node is first minimum,
 * second node is first maximum, third node is second minimum, fourth node is
 * second maximum and so on.
 *
 * Examples:
 *
 * Input : list: 4->1->3->5->2
 * Output : 1->5->2->4->3
 *
 * Input : list: 10->9->8->7->6->5
 * Output : 5->10->6->9->7->8
 * Steps:
 * 1. Sort the LL (MergeSort can be used)
 * 2. Split the list into Front and Back (FronbackSplit)
 * 3. Reverse the Back List
 * 4. Finally, Merge the Front and back Alternatively
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
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void FrontBackSplit(struct Node* head, struct Node** frontRef, struct Node** backRef)
{
    struct Node* slow;
    struct Node* fast;

    if ( head == NULL || head->next == NULL)
    {
        *frontRef = head;
        *backRef = NULL;
    }
    else
    {
        slow = head;
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
struct Node* sortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void MergeSort(struct Node** headRef)
{
    struct Node* a;
    struct Node* b;
    struct Node* head = *headRef;

    if ( head == NULL || head->next == NULL)
        return ;

    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef = sortedMerge(a, b);
}

void reverseLL(struct Node** headRef)
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
    *headRef = prev;
}

void alternateMerge(struct Node* head1, struct Node* head2)
{
    struct Node* p;
    struct Node* q;

    while ( head1 != NULL && head2 != NULL )
    {
        p = head1->next;
        head1->next = head2;
        head1 = p;

        q = head2->next;
        head2->next = head1;
        head2 = q;
    }
}

struct Node* alternateSortOfLL(struct Node* head)
{
    MergeSort(&head);
    struct Node* front;
    struct Node* back;
    FrontBackSplit(head, &front, &back);
    reverseLL(&back);
    alternateMerge(front, back);

    return front;
}

void printLL(struct Node* head)
{
    struct Node* tmp = head;
    for(; tmp != NULL; tmp = tmp->next)
        printf("[%d]->", tmp->data);
}

int main()
{
    struct Node* head = getNode(10);
    head->next = getNode(9);
    head->next->next = getNode(8);
    head->next->next->next = getNode(7);
    head->next->next->next->next = getNode(6);
    head->next->next->next->next->next = getNode(5);

    printf("Original List...\n");
    printLL(head);
    head = alternateSortOfLL(head);
    printf("After Alternate Sort...\n");
    printLL(head);
    return 0;
}
