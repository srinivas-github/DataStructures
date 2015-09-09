#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* getNewNode(int data)
{
    struct Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int data)
{
    if (node == NULL)
    {
        node = getNewNode(data);
    }
    else if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
    return node;
}

void mirrorTree(struct Node* node)
{
    if (node == NULL)
    {
        return ;
    }
    else
    {
        struct Node* temp;
        mirrorTree(node->left);
        mirrorTree(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}        

void inOrder(struct Node* node)
{
    if (node == NULL)
        return ;

    inOrder(node->left);
    printf("%d", node->data);
    inOrder(node->right);
}

int main()
{
    struct Node* root = NULL;
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 11);
    root = insert(root, 3);

    inOrder(root);
    mirrorTree(root);
    inOrder(root);
    return 0;
}

     
