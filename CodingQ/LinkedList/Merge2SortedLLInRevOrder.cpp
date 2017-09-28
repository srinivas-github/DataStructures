/**
 * Given two linked lists sorted in increasing order. Merge them such a way that 
 * the result list is in decreasing order (reverse order).
 * Examples:
 * Input:  a: 5->10->15->40
 *         b: 2->3->20 
 * Output: res: 40->20->15->10->5->3->2
 *
 * Input:  a: NULL
 *         b: 2->3->20 
 * Output: res: 20->3->2
 *
 * Solution:
 * 1) Reverse first list .a..
 * 2) Reverse second list .b..
 * 3) Merge two reversed lists.
 * OR
 * First Merge both lists, then reverse the merged list.
 *
 * How to solve it in without reverse, O(1) auxiliary space (in-place) and only one traversal of both lists?
 */
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
}

void printLL(struct Node* head)
{
    struct Node* temp = head;
    for(; temp !=NULL; temp=temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}


struct Node* mergeRev(struct Node* a, struct Node* b)
{
   if ( a == NULL && b == NULL)
       return NULL;
   struct Node* res = NULL;
   while ( a != NULL && b!= NULL)
   {
       if (a->data <= b->data)
       {
           struct Node* temp = a->next;
           a->next = res;
           res = a;
           a = temp;
       }
       else
       {
           struct Node* temp = b->next;
           b->next = res;
           res = b;
           b = temp;
       }
   }

   while ( a != NULL)
   {
       struct Node* temp = a->next;
       a->next = res;
       res = a;
       a = temp;
   }

   while ( b != NULL)
   {
       struct Node* temp = b->next;
       b->next = res;
       res = b;
       b = temp;
   }
  
   return res; 
}

int main()
{
    struct Node* l1 = NULL;
    l1 = newNode(10);
    l1->next = newNode(15);
    l1->next->next = newNode(20);

    struct Node* l2 = newNode(5);
    l2->next = newNode(25);
    l2->next->next = newNode(35);

    struct Node* res = mergeRev(l1, l2);
    printLL(res);
    return 0;
    
}

