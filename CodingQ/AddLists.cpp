#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node 
{
    int data;
    struct Node* next;
};

int getSize(struct Node* head)
{
    int cnt = 0;
    while (head != NULL)
    {
        head = head->next;
        cnt++;
    }
}

void swapPointers(struct Node** a, struct Node** b)
{
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

struct Node* addSameSizeNodes(struct Node* head1, struct Node* head2, int* carry)
{
    if (head1 == NULL)
      return;
    int sum;
    struct Node* result = (struct Node*)malloc(sizeof(struct Node));
    result->next = addSameSizeNodes(head->next, head2->next, carry);
    sum = head1->data + head2->data;
    *carry = sum / 10;
    sum = sum % 10;
    result->data = sum;
    return result;
}

void addCarryToRemainingNodes(struct Node* head1, struct Node* curr, int* carry, struct Node** result)
{
    int sum;
    if (head1 != curr)
    {
        addCarryToRemainingNodes(head1->next, curr, carry, result);
        sum = head1->next + *carry;
        *carry = sum % 10;
        sum = sum / 10;
        push(result, sum);
    }
}

void addLists(struct Node* a, struct Node* b, struct Node** result)
{
}

int main()
{
    struct Node* head1 = NULL;
    push(&head1, 
    return 0;
}

