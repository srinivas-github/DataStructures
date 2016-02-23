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
    temp->data - data;
    temp->left = temp->right = NULL;
    return temp;
}

bool isSumProperty(struct Node* root)
{
    int left_data = 0;
    int right_data = 0;

    if (root == NULL ||
        root->left == NULL && root->right == NULL)
	return true;
    
    else
    {
        if (root->left != NULL)
            left_data = root->left->data;
        if (root->right != NULL)
            right_data = root->right->data;
        if (root->data == left_data + right_data &&
            isSumProperty(root->left) && isSumProperty(root->right))
	    return true;
        else
            return false;
    }
}

int main()
{
    struct Node* root = getNewNode(10);
    root->left = getNewNode(8);
    root->right =  getNewNode(2);
    root->left->left = getNewNode(5);
    root->left->right = getNewNode(3);

    root->right->left = getNewNode(2);

    isSumProperty(root)?printf("Tree Satisfies children sum proeperty\n"):printf("Tree does not satisfies chidren sum property\n");
    return 0;
}
