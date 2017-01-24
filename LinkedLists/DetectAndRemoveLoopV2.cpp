#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};


struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}


void removeLoop(struct Node* loopNode, struct Node* head)
{
    struct Node* ptr1;
    struct Node* ptr2;

    ptr1 = head;
    while (1)
    {
        ptr2 = loopNode;
        while (ptr2->next != loopNode && ptr2 != ptr1)
            ptr2 = ptr2->next;

        if (ptr2->next = ptr1)
            break;

        ptr1 = ptr1->next;
        
    }
    ptr2->next = NULL;
    
}

int detectAndRemoveLoop(struct Node* head)
{
    struct Node* fastPtr = head;
    struct Node* slowPtr = head;

    while (slowPtr && fastPtr && fastPtr->next)
    {
         slowPtr = slowPtr->next;
         fastPtr = fastPtr->next->next;
         if (slowPtr == fastPtr)
         {
             removeLoop(slowPtr, head);
             return 1;         
         }
    }

}

void printList(struct Node* node)
{
    struct Node* tmp = node;
    for (; tmp != NULL; tmp = tmp->next)
    {
        printf("[%d] -> ", tmp->data);
    }
    printf("[NULL]\n");
}



int main()
{

    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = head->next->next;


    //detectAndRemoveLoop(head);
    printList(head);

    
    return 0;
}
