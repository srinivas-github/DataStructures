#include <iostream>
#include <cstdio>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

//Method to find the minimum in the tree

BSTNode* findMin(BSTNode* root)
{
    while( root->left != NULL)
        root = root->left;
    return root;
}

/**
 * function to delete a node
 */

BSTNode* deleteNode(BSTNode* root, int data)
{
    if (root == NULL)
        return NULL;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        // case 1: No Child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // case 2: One child
        else if (root->left == NULL)
        {
            struct BSTNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            struct BSTNode* temp = root;
            root = root->left;
            delete temp;
        }
        //case 3: Two Childs
        else
        {
            struct BSTNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
       
    return root;
}

void inOrder(BSTNode* root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d", root->data);
    inOrder(root->right);
}

BSTNode* insert(BSTNode* root, int data)
{
    if (root == NULL)
    {
        root = new BSTNode();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int main()
{
    BSTNode* root = NULL;
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 11);
    root = insert(root, 1);
    
    printf("InOrder, before deleting:\n");
    inOrder(root);
    root = deleteNode(root, 1);
    printf("InOrder, after deleting:\n");
    inOrder(root);
    return 0;
}
