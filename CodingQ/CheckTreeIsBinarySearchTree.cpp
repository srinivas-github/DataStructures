#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

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

bool isBstUtil(struct Node* root, int min, int max)
{
    if (root == NULL)
        return 1;
    if (root->data < min || root->data > max)
        return 0;
    return isBstUtil(root->left, min, root->data-1) &&
           isBstUtil(root->right, root->data+1, max);
}
bool isBst(struct Node* root)
{
    return isBstUtil(root, INT_MIN, INT_MAX);
}
int main()
{
    struct Node* root = newNode(5);
    root->left = newNode(13);
    root->right = newNode(8);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->left->left = newNode(2);
    isBst(root) ? printf("Tree is BST\n") : printf("Not a BST\n");
    return 0;
}
