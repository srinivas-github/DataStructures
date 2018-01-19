
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

void swap(struct Node** a, struct Node** b)
{
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void inOrder(struct Node* root)
{
    if (root == NULL)
        return ;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void swapEveryKLevelUtil(struct Node* root, int level, int k)
{
    if (root == NULL || root->left == NULL || root->right == NULL)
        return ;
    if ( (level +1 ) % k == 0)
        swap(&root->left, &root->right);
    
    swapEveryKLevelUtil(root->left, level+1, k);
    swapEveryKLevelUtil(root->right, level+1, k);
} 
void swapEveryKLevel(struct Node* root, int k)
{
    swapEveryKLevelUtil(root, 1, k);
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    
    root->left->left = newNode(4);
    root->right->right = newNode(8);
    root->right->left = newNode(7);
    
    int k = 2;
    std::cout<<"Before swap nodes:\n";
    inOrder(root);
    
    std::cout<<"\nAfter swap nodes\n";
    swapEveryKLevel(root, k);
    inOrder(root);
    return 0;
}
