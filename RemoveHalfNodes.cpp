#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

/**
 * Get the node
 */
struct Node* getNewNode(int data)
{
    struct Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* removeHalfNodes(struct Node* root)
{
    if (root == NULL)
        return NULL;

    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);
    if (root->left == NULL && root->right == NULL)
        return root;

    if (root->left == NULL)
    {
        struct Node* new_root = root->right;
        free(root);
        return new_root;
    }
    if (root->right == NULL)
    {
        struct Node* new_root = root->left;
        free(root);
        return new_root;
    }
    return root;
}

void printInOrder(struct Node* root)
{
    if (root == NULL)
        return ;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);

}
int main()
{
    struct Node* root = NULL;
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 13);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 15);
    printInOrder(root);
    root = removeHalfNodes(root);
    printf("\nAfter Removal of Half Nodes:\n");
    printInOrder(root);
    return 0;
}
