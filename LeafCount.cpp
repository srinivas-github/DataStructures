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
  temp->left = NULL;
  temp->right = NULL;
  return temp;   
}

struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);        
    }
    else if ( data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

int getLeafCount(struct Node* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
      return getLeafCount(root->left) + getLeafCount(root->right); 
}

int main()
{
    struct Node* root = NULL;
    root = insert(root, 17);
    root = insert(root, 15);
    root = insert(root, 19);
    root = insert(root, 13);
    root = insert(root, 21);
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 14);
    root = insert(root, 16);
    root = insert(root, 18);
    root = insert(root, 20);

    printf("%d is the leaf count\n", getLeafCount(root));
    return 0;
}
