#include <cstdio>
#include <cstdlib>

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
void printList(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

void skipMandDelN(struct Node* head, int m ,int n)
{
    struct Node* curr = head;
    struct Node* t;

    while (curr)
    {
        for (int count = 1; count < m&& curr != NULL; count++)
            curr = curr->next;
        if (curr == NULL)
            return ;

        t = curr->next;
        for(int count = 1; count <= n&&t != NULL; count++)
        {
            struct Node* temp = t;
            t = t->next;
            free(temp);
        }
        curr->next = t;
        curr = t;
    }
}

int main()
{
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    push(&head, 60);
    push(&head, 70);
    push(&head, 80);
    push(&head, 90);
    push(&head, 100);
    printList(head);
    skipMandDelN(head, 3,3);
    printList(head);

    return 0;
}
