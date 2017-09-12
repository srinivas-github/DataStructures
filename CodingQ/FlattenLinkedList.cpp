/**
 * Flattening a Linked List
 * Given a linked list where every node represents a linked list and contains two pointers of its type:
 * (i) Pointer to next node in the main list (we call it right pointer in below code)
 * (ii) Pointer to a linked list where this node is head (we call it down pointer in below code).
 * All linked lists are sorted. See the following example
 *
 *      5 -> 10 -> 19 -> 28
 *      |    |     |     |
 *      V    V     V     V
 *      7    20    22    35
 *      |          |     |
 *      V          V     V
 *      8          50    40
 *      |                |
 *      V                V
 *      30               45
 *
 * Output: 5->7->8->10->19->20->22->28->30->35->40->45->50
 */

#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node* down;
    struct Node* right;
};

void push(struct Node** headRef, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->right = NULL;
    newNode->data = data;
    newNode->down = (*headRef);
   (*headRef) = newNode;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->down)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

struct Node* merge(struct Node* a, struct Node* b)
{
    if ( a == NULL)
        return b;
    if (b == NULL)
        return b;
    struct Node* result = NULL;
    if (a->data < b->data)
    {
        result = a;
        result->down = merge(a->down, b);
    }
    else
    {
        result = b;
        result->down = merge(a, b->down);
    }
    return result;
}
struct Node* flatten(struct Node* root)
{
    if (root == NULL || root->right == NULL)
        return root;
    return merge(root, flatten(root->right));
}

int main()
{
    struct Node* root =NULL;

    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );
 
    push( &( root->right ), 20 );
    push( &( root->right ), 10 );
 
    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );
 
    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );
    root = flatten(root);
    printList(root);
    return 0;
}
