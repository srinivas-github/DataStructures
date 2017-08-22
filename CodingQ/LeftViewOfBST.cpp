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

void leftViewUtil(struct Node* root, int level, int* max_level)
{
    if (root == NULL)
        return ;
    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right,level+1, max_level);


}
void leftView(struct Node* root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

int main()
{
    struct Node* root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    leftView(root);
    
    return 0;
}
