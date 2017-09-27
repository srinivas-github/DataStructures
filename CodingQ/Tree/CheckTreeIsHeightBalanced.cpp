#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

int max(int a, int b)
{
    return (a >= b) ? a: b;
}

int height(struct Node* root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(struct Node* root)
{
    if (root == NULL)
        return 1;
    int lh = height(root->left);
    int rh = height(root->right);

    if ( (abs(lh-rh)) <= 1 &&
         isBalanced(root->left) &&
         isBalanced(root->right))
        return 1;
    return 0;
}

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    //root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    //root->right->right = newNode(6);

    if (isBalanced(root))
        std::cout<<"Tree balanced...\n";
    else
        std::cout<<"Tree Not balanced...\n";
    return 0;
}
