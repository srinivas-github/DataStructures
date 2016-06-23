/**
 * FullBinary tree: If all nodes have either two childs or zero
 */

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
     return temp;
 }

bool isFullBinaryTree(struct Node* root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if ( (root->left) && (root0>right) )
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);

     return false;
     
 }

int main()
{
    struct Node* root = getNewNode(10);
    root->left = getNewNode(20);
    root->right = getNewNode(30);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);

    root->right->left = getNewNode(60);
    root->right->right = getNewNode(70);
    isFullBinaryTree(root)? printf ("IS Full Binary tree\n") : printf("Not Full Binary Tree\n");
    return 0;
}

