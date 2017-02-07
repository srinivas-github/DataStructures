#include <cstdio>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void printArr(int path[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}

void printPathRec(struct Node* node, int path[], int len)
{
    if (node == NULL)
        return ;
     path[len] = node->data;
     len++;

     if (node->left == NULL && node->right == NULL)
     {
          printArr(path, len);
     }
     else
     {
         printPathRec(node->left, path, len);
         printPathRec(node->right, path, len);
     }
}

void printPaths(struct Node* root)
{
    int path[100];
    printPathRec(root, path, 0);
}

int main()
{
    struct Node* node = newNode(10);
    node->left = newNode(8);
    node->right = newNode(2);
    node->left->left = newNode(3);
    node->left->right = newNode(5);
    node->right->left = newNode(2);
    printPaths(node);
    return 0;
 
}
