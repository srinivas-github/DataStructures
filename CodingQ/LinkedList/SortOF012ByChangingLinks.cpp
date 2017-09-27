#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* getNewNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printL(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]-> ", temp->data);
    printf("[NULL]\n");
}

struct Node* Sort012(struct Node* head)
{
    if ( head == NULL || head->next == NULL)
        return NULL ;

    struct Node* zeroD = getNewNode(0);
    struct Node* oneD = getNewNode(0);
    struct Node* twoD = getNewNode(0);

    struct Node* zero = zeroD;
    struct Node* one  = oneD;
    struct Node* two = twoD;

    struct Node* curr = head;

    while (curr)
    {
        if (curr->data == 0)
        {
            zero->next  = curr;
            zero = zero->next;
            curr = curr->next;
        }
        else if (curr->data == 1)
        {
            one->next = curr;
            one  = one->next;
            curr = curr->next;
        }
        else
        {
            two->next = curr;
            two = two->next;
            curr = curr->next;
        }
    }
    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL;

    head = zeroD->next;
    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
}
 

int main()
{
    struct Node* head = NULL;
    head = getNewNode(2);
    head->next = getNewNode(0);
    head->next->next = getNewNode(1);
    head->next->next->next = getNewNode(0);
    head->next->next->next->next = getNewNode(2);
    printL(head);
    head = Sort012(head);
    printL(head);
    return 0;
    
}
