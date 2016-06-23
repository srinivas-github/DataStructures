#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
//Level Order Traversal Demo
struct BSTNode
{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

struct BSTNode* getNewNode(int data)
{
    struct BSTNode* temp = new BSTNode();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct BSTNode* insert(struct BSTNode* root, int data)
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

int height(struct BSTNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int lH = height(root->left);
        int rH = height(root->right);
        return  ( (lH > rH) ? lH+1 : rH+1);
    }
}

void printGevenOrder(struct BSTNode* root, int level)
{
    if (root == NULL)
        return ;

    if (level == 1)
    {
        printf("%d  ", root->data);
    }
    else if (level > 1)
    {
        printGevenOrder(root->left, level-1);
        printGevenOrder(root->right, level-1);
    }
}

void printLevelOrder(struct BSTNode* root)
{
   int ht = height(root);
   for(int i = 1; i <= ht; i++)
       printGevenOrder(root, i);
}

void LevelOrder(Node *root)
{
	if(root == NULL) 
	   return;
	queue<Node*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty())
	{
		Node* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) 
		    Q.push(current->left);
		if(current->right != NULL) 
		    Q.push(current->right);
	}
}


int main()
{
    struct BSTNode* root = NULL;
    root = insert(root, 17);
    root = insert(root, 19);
    root = insert(root, 15);
    root = insert(root, 16);
    root = insert(root, 18);
    root = insert(root, 20);
    root = insert(root, 14);
    printLevelOrder(root);
    return 0;
}

