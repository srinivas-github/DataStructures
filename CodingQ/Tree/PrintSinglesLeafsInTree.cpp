#include <cstdio>
#include <cstdlib>
using namespace std;

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
void printSingles(struct Node* root)
{
    if (root == NULL)
        return ;
    if (root->left != NULL && root->right != NULL)
    {
        printSingles(root->left);
        printSingles(root->right);
    }
    else if (root->right != NULL)
    {
        printf("%d ", root->data);
        printSingles(root->right);
    }
    else if (root->left != NULL)
    {
        printf("%d ", root->data);
        printSingles(root->left);
    }
  
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(6);
    printSingles(root);
    return 0;
}
