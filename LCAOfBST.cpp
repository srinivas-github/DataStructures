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

struct Node* insertNode(struct Node* root, int data)
{
    if (root == NULL)
        root = newNode(data);
    else if(root->data <= data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

struct Node* lca(struct Node* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data < n1 && root->data < n2)
        return lca(root->left, n1, n2);
    if (root->data > n1 && root->data > n2)
        return lca(root->right, n1, n2);

    return root;
}

int main()
{
    struct Node* root = NULL;
    root = insertNode(root, 20);
    root = insertNode(root, 8);
    root = insertNode(root, 22);
    root = insertNode(root, 4);
    root = insertNode(root, 12);
    root = insertNode(root, 10);
    root = insertNode(root, 14);

    int n1 = 10, n2 = 14;
    struct Node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
	     
    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
			  
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
				       
    return 0;
}
