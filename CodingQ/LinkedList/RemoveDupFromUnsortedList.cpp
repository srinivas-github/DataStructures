/**
 * Remove Duplicates from unsorted linked list
 * Example: 12->11->12->21->41->43->21->NULL
 * then O/P:
 * 12->11->21->41->43
 *
 * Method 1: (Using two loops and compare
 */
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

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
    for(; temp!= NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

void removeDupsV1(struct Node* head)
{
    struct Node* ptr1, *ptr2, *dup;
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
       ptr2 = ptr1;
       while (ptr2->next != NULL)
       {
           if (ptr1->data == ptr2->next->data)
           {
               dup = ptr2->next;
               ptr2->next = ptr2->next->next;
               free(dup);
           }           
           else
               ptr2 = ptr2->next;
       }
       ptr1 = ptr1->next;
    }
}

/**
 * method2: using Map
 */
void removeDupsV2(struct Node* head)
{
    struct Node* curr = head;
    struct Node* prev = NULL;
    std::map<int, int> myMap;
    while (curr != NULL)
    {
        if (myMap.find(curr->data) != myMap.end())
        {
            prev->next = curr->next;
            free(curr);
        }
        else
        {
            myMap.insert(make_pair(curr->data, curr->data));
            prev = curr;
        }
        curr = prev->next;
    }
}

int main()
{
    struct Node* head = NULL;
    push(&head, 12);
    push(&head, 11);
    push(&head, 12);
    push(&head, 21);
    push(&head, 12);
    push(&head, 43);
    push(&head, 41);
    push(&head, 43);
    push(&head, 12);

    printLL(head);
    //removeDupsV1(head);
    removeDupsV2(head);
    printLL(head);

    return 0;
}
