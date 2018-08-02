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
int height(struct Node* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lH =  height(root->left);
        int rH =  height(root->right);
        
        return (lH > rH) ? lH + 1 : rH+1;
    }
}

void printGivenLevel(struct Node* root, int level, int ltr)
{
    if (root == NULL)
        return ;
    if (level == 1)
        printf("%d ", root->data);
    else if(level > 1)
    {
        if (ltr)
        {
            printGivenLevel(root->left, level-1, ltr);
            printGivenLevel(root->right, level-1, ltr);
        }
        else
        {
            printGivenLevel(root->right, level-1, ltr);
            printGivenLevel(root->left, level-1, ltr);
        }
    }
}

void printSpiralForm(struct Node* root)
{
    if (root == NULL)
        return ;
    int h = height(root);
    bool ltr = false;
    
    for ( int i = 1; i <=h; i++)
    {
        printGivenLevel(root, i, ltr);
        ltr = !ltr;
    }
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->right->right->right = newNode(9);
    
    printSpiralForm(root);
    
    return 0;
}
