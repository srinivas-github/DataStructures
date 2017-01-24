#include <iostream>
#include <unordered_map>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void pathCountUtil(struct Node* root, std::unordered_map<int, int>& m, int pathLen)
{
    if (root == NULL)
        return ;

    if (root->left == NULL && root->right == NULL)
    {
       m[pathLen]++;
       return;
    }

    pathCountUtil(root->left, m, pathLen+1);
    pathCountUtil(root->right, m, pathLen+1);

}

void pathCounts(struct Node* root)
{
    if (root == NULL)
        return ;

    std::unordered_map<int, int> m;
    pathCountUtil(root, m, 1);

    for( auto itr = m.begin(); itr != m.end(); itr++)
    {
        std::cout<<itr->second<<" paths have length "
                 <<itr->first<<"\n";
    }
    
}

int main()
{
    struct Node* root = newNode(8);
    root->left = newNode(5);
    root->right = newNode(4);

    root->left->left = newNode(9);
    root->left->right = newNode(7);

    root->right->right = newNode(11);
    root->right->right->left = newNode(3);

    pathCounts(root);

    return 0;
}
