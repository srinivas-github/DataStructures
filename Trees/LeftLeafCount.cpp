#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* getNewNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return NULL;
}

bool isLeaf(struct Node* root)
{
    if (root == NULL)
        return false;
    if ((root->left == NULL) && (root->right == NULL))
        return true;
    return false;
}

int leftLeafCount(struct Node* root)
{
    int res = 0;
    if (root != NULL)
    {
        if ( isLeaf(root->left))
	    res += root->left->data;
	else
	    res += leftLeafCount(root->left);
	res += leftLeafCount(root->right);
    }
    return res;
}

int main()
{
    struct Node* root = getNewNode(2);
    root->left = getNewNode(3);
    root->right = getNewNode(4);
    root->left->left = getNewNode(5);
    root->right->left = getNewNode(6);

    printf("Left leaf count: %d\n", leftLeafCount(root));
    return 0;
}

