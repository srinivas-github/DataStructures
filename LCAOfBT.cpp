#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

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
    temp->lwft = temp->right = NULL;
    return temp;
}

bool findPath(struct Node* root, vector<int>& path, int k)
{
    if(root == NULL)
        return true;

    path.push_back(root->data);

    if (root->data == k)
        return true;


    if ( (root->left && findPath(root->left, path, k)) ||
         (root->right && findPath(root->right, path, k)) )
	 return true;

    path.pop_back();
    return false;

}

int findLCA(struct Node* root, int n1, int n2)
{
    vector<int> path1, path2;

    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;

    int i;
    for(i = 0;  i < path1.size() && i < path2.size(); i++)
    {
        if (path1[i] != path2[i])
	    break;
    }
    return path1[i-1];
}

int main()
{
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    std::cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    std::cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    std::cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    std::cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}
