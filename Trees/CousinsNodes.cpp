/**
 * Given the binary Tree and the two nodes say 'a' and 'b', determine whether
 * the two nodes are cousins of each other or not.
 * Two nodes are cousins of each other if they are at same level and have different parents.
 *
 * Example
 *
 *           6
 *         /   \
 *        3     5
 *       / \   / \
 *      7   8 1   3
 * Say two node be 7 and 1, result is TRUE.
 * Say two nodes are 3 and 5, result is FALSE.
 * Say two nodes are 7 and 5, result is FALSE.
 */

#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/**
 * Recursive function to check if nodes are siblings or not
 */
int isSiblings(struct Node* root, struct Node* a, struct Node* b)
{
    if (root == NULL)
        return 0;
    return ( (root->left == a && root->right == b) ||
             (root->left == b && root->right == a) ||
	     isSiblings(root->left, a, b) ||
	     isSiblings(root->right, a,b));
}

/**
 * Recursive function to get the level of a node in Tree
 */
int level(struct Node* root, struct Node* ptr, int lev)
{
    if (root == NULL)
        return 0;
    if (root == ptr)
        return lev;

    int l = level(root->left, lev+1);
    if ( l!= 0)
        return l;
    return level(root->right, lev+1);
}

/**
 * Returns true if nodes are cousins otherwise false
 */
int isCousins(struct Node* root, struct Node* n1, struct Node* n2)
{
    if ( (level(root, n1, 1) == level(root, n2, 1)) && !isSiblings(root, n1, n2))
        return 1;
    return 0;
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    struct Node* n1 = root->left->left;
    struct Node* n2 = root->right->right;

    isCousins(root, n1, n2)?printf("Cousins\n"):printf("Not Cousins\n");
    return 0;
}

