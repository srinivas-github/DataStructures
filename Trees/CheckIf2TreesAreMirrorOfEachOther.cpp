/**
 * Given two Binary Trees, write a function that returns true if two trees
 * are mirror of each other, else false.
 *
 * For two trees 'a' and 'b' to be mirror images, the following
 * three conditions must be true:
 * 1. Their root node's key must be same
 * 2. Left subtree of root of 'a' and right subtree root of 'b' are mirror.
 * 3. Right subtree of 'a' and left subtree of 'b' are mirror.
 */
#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
}


int areMirror(struct Node* a, struct Node* b)
{
    if (a == NULL && b == NULL)
        return 1;
    if (a == NULL || b == NULL)
        return NULL;

    return (a->data == b->data) &&
            areMirror(a->left, b->right) &&
	    areMirror(a->right, b->left);
}

int main()
{
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left  = newNode(4);
    a->left->right = newNode(5);

    b->left = newNode(3);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(4);

    areMirror(a, b)? printf("Yes") : printf("No");
    
    return 0;
}
