#include <iostream>

struct Node
{
    int key;
    struct Node* right;
    struct Node* left;
};

struct Node* newNode(int data)
{
    struct Node* temp = new Node();
    temp->key = data;
    temp->right = temp->left = NULL;
    return temp;
}

bool isMirror(struct Node* root1, struct Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 && root2 && root1->key == root2->key)
        return isMirror(root1->left, root2->right) &&
	       isMirror(root1->right, root2->left);

    return false;
}

bool isSymmetric(struct Node* root)
{
    return isMirror(root, root);
}

int main()
{
     Node *root        = newNode(1);
     root->left        = newNode(2);
     root->right       = newNode(2);
     root->left->left  = newNode(3);
     root->left->right = newNode(4);
     root->right->left  = newNode(4);
     root->right->right = newNode(3);

     std::cout<<isSymmetric(root)<<"\n";

    return 0;
}
