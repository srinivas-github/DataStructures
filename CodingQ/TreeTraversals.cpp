#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

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

struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
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

void preOrder(struct Node* root)
{
    if (root == NULL)
        return ;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node* root)
{
    if (root == NULL)
        return ;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct Node* root)
{
   if (root == NULL)
        return ;

   postOrder(root->left);
   postOrder(root->right);
   printf("%d ", root->data);
}

void levelOrder(struct Node* root)
{
    if (root == NULL)
        return ;

    std::queue<Node*> Q;
    Q.push(root);
    while (!Q.empty())
    {
         Node* curr = Q.front();
         Q.pop();
         printf("%d ", curr->data);
         if (curr->left != NULL)
             Q.push(curr->left);
         if (curr->right != NULL)
             Q.push(curr->right);
    }

}

int height(struct Node* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lH = height(root->left);
        int rH = height(root->right);
        return ( (lH > rH) ? lH+1 :rH+1);
    }
 
}

void printGivenOrder(struct Node* root, int level)
{
    if (root == NULL)
        return ;
    if (level == 1)
       printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenOrder(root->left, level-1);
        printGivenOrder(root->right, level-1);
    }
}

void printLevelOrder(struct Node* root)
{
    int h = height(root);
    for (int i = 0; i <= h; i++)
        printGivenOrder(root, i); 
}


int main()
{
    struct Node* root = NULL;
    root = insert(root, 19);
    root = insert(root, 15);
    root = insert(root, 23);
    root = insert(root, 18);
    root = insert(root, 17);
    root = insert(root, 14);
    root = insert(root, 20);
    root = insert(root, 22);
    root = insert(root, 25);
    
    printf("preOrder:\n");
    preOrder(root);
    printf("\n");

    printf("inOrder:\n");
    inOrder(root);
    printf("\n");

    printf("postOrder:\n");
    postOrder(root);
    printf("\n");

    printf("Level Order: \n");
    levelOrder(root);
    printf("\n");

    printf("print GivenOrder:\n");
    printLevelOrder(root);
    printf("\n");
    return 0;
}
