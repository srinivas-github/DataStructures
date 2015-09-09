#include <iostream>
#include <queue>
using namespace std;

typedef struct Node
{
    char data;
    Node *left;
    Node *right;
}BSTNode;

//PreOrder
void preOrder(BSTNode *root)
{
    if (root == NULL)
        return ;
    std::cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}

//InOrder
void inOrder(BSTNode *root)
{
    if (root == NULL)
        return ;

    inOrder(root->left);
    std::cout<<root->data;
    inOrder(root->right);
}

//Postorder
void postOrder(BSTNode *root)
{
    if (root == NULL)
        return ;

    postOrder(root->left);
    postOrder(root->right);
    std::cout<<root->data;
}

// Function to print Nodes in a binary tree in Level order
void LevelOrder(BSTNode *root)
{
    if(root == NULL) return;
    queue<BSTNode*> Q;
    Q.push(root);
    //while there is at least one discovered node
    while(!Q.empty())
    {
        BSTNode* current = Q.front();
        Q.pop(); // removing the element at front
        std::cout<<current->data<<" ";
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
    }
}

BSTNode* insert(BSTNode *root, char data)
{
    if (root == NULL)
    {
        root = new BSTNode();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int main()
{
    BSTNode *root = NULL;
    root = insert(root, 'M');
    root = insert(root, 'B');
    root = insert(root, 'Q');
    root = insert(root, 'Z');
    root = insert(root, 'A');
    root = insert(root, 'C');

    std::cout<<"PreOrder:";
    preOrder(root);
    std::cout<<"\nInOrder:";
    inOrder(root);
    std::cout<<"\nPostorder:";
    postOrder(root);
    std::cout<<"\n level Order:";
    LevelOrder(root);
    std::cout<<"\n";
    return 1; 
}

