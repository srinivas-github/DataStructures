/**
 * Compare two strings represented as linked lists
 * Example:
 * 1. I/P: s->r->i->n->i->v->a->s
 *         s->r->i->n->i->v->a->t
 *    O/P: -1
 *
 * 2. I/P: s->r->i->n->i->v->a->s
 *         s->r->i->n->i->v->a
 *    O/P: 1
 *
 * 3. I/P: s->r->i->n->i->v->a->s
 *         s->r->i->n->i->v->a->s
 *    O/P: 0
 */

#include <cstdio>
#include <cstdlib>
using namespace std;


struct Node
{
    char c;
    struct Node* next;
};

struct Node* newNode(char c)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->c = c;
    temp->next = NULL;
    return temp;
}

int compareLists(struct Node* list1, struct Node* list2)
{
    while (list1 && list2 && list1->c == list2->c)
    {
        list1 = list1->next;
        list2 = list2->next;
    }

    if (list1 && list2)
    {
        return (list1->c > list2->c) ? 1:-1;
    }

    if (list1 && !list2)
        return 1;
    if (list2 && !list1)
        return -1;

    return 0;
}

int main()
{
    struct Node* l1 = NULL;
    l1 = newNode('s');
    l1->next = newNode('r');
    l1->next->next = newNode('i');
    l1->next->next->next = newNode('n');
    l1->next->next->next->next = newNode('i');

    struct Node* l2 = NULL;
    l2 = newNode('s');
    l2->next = newNode('r');
    l2->next->next = newNode('i');
    l2->next->next->next = newNode('n');
    l2->next->next->next->next = newNode('u');

    int res = compareLists(l1, l2);
    if ( res == 0)
        printf("Lists are equal...\n");
    else if (res == 1)
        printf("L1 is greater than L2\n");
    else
        printf("L1 is less than L2\n");
 
    return 0;
}
