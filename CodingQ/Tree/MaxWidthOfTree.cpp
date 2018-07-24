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
    temp->left= temp->right = NULL;
    return temp;
}

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int height(struct Node* root)
{
    if (root == NULL)
        return 0;
    return 1 + max( height(root->left), height(root->right));
}

int getWidth(struct Node* root, int level)
{
    if (root == NULL)
        return 0;
    if ( level == 1)
        return 1;
    else if ( level > 1)
        return getWidth(root->left, level-1) + getWidth(root->right, level-1);
}

int getMaxWidth(struct Node* root)
{
    int maxwidth = 0;
    int width;
    int i, h;
    
    h = height(root);
    
    for( i = 1; i <= h; i++)
    {
        width = getWidth(root, i);
        if ( width > maxwidth)
            maxwidth = width;
    }
    return maxwidth;
}

int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(14);
    root->left->right = newNode(16);
    root->left->left = newNode(18);
    
    root->right->left = newNode(20);
    root->right->right = newNode(22);
    
    root->right->right->right = newNode(24);
    
    printf("Max Width: %d\n", getMaxWidth(root));
    return 0;
}
