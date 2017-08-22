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

void rightViewUtil(struct Node* root, int level, int* max_level)
{
    if (root == NULL)
        return ;
    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }

    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);
}
void rightView(struct Node* root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->left->left = newNode(30);
    root->left->right = newNode(40);

    root->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);
    rightView(root);

    return 0;
}
