#include <cstdio>
#include <cstdlib>
using namespace std;

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

void display(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
 
}

void insertAtMid(struct Node** headRef, int x)
{
    if (*headRef == NULL)
        *headRef = getNode(x);
    else
    {
        struct Node* newNode = getNode(x);
        struct Node* ptr = *headRef;
        int len = 0;
        while (ptr != NULL)
        {
            len++;
            ptr = ptr->next;
        }
        int count = (len % 2)==0?(len/2):(len+1)/2;
        ptr = *headRef;
        while (count-- > 1)
            ptr = ptr->next;

        newNode->next = ptr->next;
        ptr->next = newNode;
    }    
}

void insertAtMid_V2(struct Node** headRef, int x)
{
    if (*headRef == NULL)
        *headRef = getNode(x);
    else
    {
        struct Node* newNode = getNode(x);
        struct Node* slowPtr = (*headRef);
        struct Node* fastPtr = (*headRef)->next;
        while (fastPtr && fastPtr->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        newNode->next = slowPtr->next;
        slowPtr->next = newNode;
    }

}
int main()
{
    struct Node* head = NULL;
    head = getNode(1);
    head->next = getNode(2);
    head->next->next = getNode(3);
    head->next->next->next = getNode(4);
    head->next->next->next->next = getNode(5);
    head->next->next->next->next->next = getNode(6);
    head->next->next->next->next->next->next  = getNode(7);
    head->next->next->next->next->next->next->next = getNode(8);
    display(head);
    //insertAtMid(&head, 100);
    insertAtMid_V2(&head, 100);
    display(head);
    
    return 0;
}
