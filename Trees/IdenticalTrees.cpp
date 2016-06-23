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
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    t->left = t->right = NULL;
    return t;
}

bool isIdenticalTrees(struct Node* a, struct Node* b)
{
    if (a == NULL && b == NULL)
        return true;

    return (
        a->data == b->data &&
	isIdenticalTrees(a->left, b->left) &&
	isIdenticalTrees(a->right, b->right)
 
    );
    return false;
}

int main()
{
    struct Node* root1 = newNode(1);
    struct node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5); 
			 
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5); 
					  
    if(identicalTrees(root1, root2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");
    return 0;
}
