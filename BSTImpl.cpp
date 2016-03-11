#include <iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* getNewNode(int data);
BstNode* insert(BstNode* root, int data);
bool search(int data, BstNode* root);
int maxHeight(BstNode* root);

/**
 * driver function to test
 */


int main()
{
    BstNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 12);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 5);

    if (search(15, root))
    {
        std::cout<<"Found the data...."<<std::endl;
    }
    int maxH = maxHeight(root);
    std::cout<<"Max Height is:"<<maxH<<"\n";
	   
    return 0;
}

/**
 * Creata a new node
 */

BstNode* getNewNode(int data)
{
    BstNode* temp = new BstNode();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/**
 insert node
 */
BstNode* insert(BstNode* root, int data)
{
    if ( root == NULL)
    {
        root = getNewNode(data);
    }
    else if ( data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(int data, BstNode* root)
{
    if ( root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if ( data < root->data)
        return search(data, root->left);
    else 
        return search(data, root->right);
}

int maxHeight(BstNode* root)
{
    if (root == NULL)
        return 0;

    int leftH = maxHeight(root->left);
    int rightH = maxHeight(root->right);
    return (leftH > rightH ) ? leftH+1:rightH+1;
}
