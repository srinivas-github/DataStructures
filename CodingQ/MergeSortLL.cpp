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
    for(; temp != NULL ; temp = temp->next)
    {
        printf("[%d]->", temp->data);
    }
    printf("[NULL]\n");
}

void fronBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef)
{
    struct Node* fast;
    struct Node* slow;

    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow =source;
        fast = source->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;
    if (a == NULL)
        return b;
    else if ( b == NULL)
        return a;

    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}

void MergeSort(struct Node** headRef)
{
    struct Node* head = (*headRef);
    struct Node* a;
    struct Node* b;

    if (head == NULL || head->next == NULL)
        return ;

    fronBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a,b);    
}

void removeDups(struct Node* head)
{
    struct Node* current = head;
    struct Node* next_next;

    if (current == NULL)
        return ;

    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
 
}
int main()
{
   struct Node* head = NULL;
   push(&head, 6);
   push(&head, 3);
   push(&head, 6);
   push(&head, 8);
   push(&head, 8);
   push(&head, 7);
   push(&head, 3);
   push(&head, 2);
   push(&head, 2);
   push(&head, 9);
   push(&head, 1);

   printLL(head);
   MergeSort(&head);
   printLL(head);

   removeDups(head);
   printLL(head);
   return 0;
}
