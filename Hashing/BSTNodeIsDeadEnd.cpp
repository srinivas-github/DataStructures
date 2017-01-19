#include <unordered_set>
#include <iostream>

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


struct Node* insert(struct Node* root, int key)
{
    if (root== NULL)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
    
}

void storeNodes(struct Node* root, std::unordered_set<int>& all_nodes, std::unordered_set<int>& leaf_nodes)
{
    if (root == NULL)
        return ;

    all_nodes.insert(root->data);

    //insert leaf nodes data in leaf_nodes
    if (root->left == NULL && root->right == NULL)
    {
        leaf_nodes.insert(root->data);
        return ;
    }

    //recursive call
    storeNodes(root->left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}

bool isDeadEnd(struct Node* root)
{
    if (root == NULL)
        return false;

    std::unordered_set<int> all_nodes;
    std::unordered_set<int> leaf_nodes;
    all_nodes.insert(0);

    storeNodes(root, all_nodes, leaf_nodes);

    for (auto i = leaf_nodes.begin(); i != leaf_nodes.end(); i++)
    {
        int x = (*i);
        if (all_nodes.find(x+1) != all_nodes.end() &&
            all_nodes.find(x-1) != all_nodes.end())
            return true;
    }
    return false;
}


int main()
{
    struct Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 4);

    if (isDeadEnd(root) )
        std::cout<<"Yes\n";
    else
        std::cout<<"No\n";
    return 0;
}
