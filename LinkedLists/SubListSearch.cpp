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
}

bool findSubList(struct Node* first, struct Node* second)
{
    struct Node* ptr1 = first;
    struct Node* ptr2 = second;

    if (first == NULL && second == NULL)
        return true;

    if (first == NULL || first != NULL && second == NULL)
        return false;
    

    while (second != NULL)
    {
        ptr2 = second;
        while (ptr1 != NULL)
        {
            if (ptr2 == NULL)
                return false;
            else if (ptr1->data == ptr2->data)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else
                break;
        }
        if (ptr1 == NULL)
            return true;

        ptr1 = first;
        second = second->next;

    }
    return false;

}


void printList(struct Node* head)
{
    struct Node* tmp = head;
    for(; tmp != NULL; tmp = tmp->next)
    {
        printf("[%d] ->", tmp->data);
    }
    printf("[NULL]\n");
}

int main()
{
    struct Node* first = newNode(1);
    first->next = newNode(2);
    first->next->next = newNode(3);
    first->next->next->next = newNode(4);

    struct Node* second = newNode(1);
    second->next = newNode(2);
    second->next->next = newNode(1);
    second->next->next->next = newNode(2);
    second->next->next->next->next = newNode(3);
    second->next->next->next->next->next = newNode(4);

    printList(first);
    printList(second);

    if (findSubList(first, second))
        printf("List Found\n");
    else printf("Not Found\n");

    return 0;
}
