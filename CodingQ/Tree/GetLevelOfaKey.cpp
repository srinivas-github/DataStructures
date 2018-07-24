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

int getLevelUtil(struct Node* root, int data, int level)
{
    if ( root == NULL)
        return 0;
    if (root->data == data)
        return level;
        
    int downLevel = getLevelUtil(root->left, data, level+1);
    if ( downLevel != 0)
        return downLevel;
    downLevel = getLevelUtil(root->right, data, level+1);
    return downLevel;
}

int getLevel(struct Node* root, int data)
{
    return getLevelUtil(root, data, 1);
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
    int key = 22;
    printf("Key: %d, Level: %d\n", key, getLevel(root, key));
    return 0;
}
