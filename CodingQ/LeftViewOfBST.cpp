#include <cstdio>
#include <cstdlib>
#include <map>
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
    temp->left = temp->right = NULL;
    return temp;
}

void leftViewUtil(struct Node* root, int level, int* max_level)
{
    if (root == NULL)
        return ;
    if (*max_level < level)
    {
        printf("%d ", root->data);
        *max_level = level;
    }
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right,level+1, max_level);


}
void leftView(struct Node* root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}


/**
 * By Using the Map
 */
void leftViewMapUtil(struct Node* root, int level, std::map<int, int>& rMap)
{
    if (root == NULL)
        return ;
    if (rMap.find(level) == rMap.end())
        rMap[level] = root->data;

    leftViewMapUtil(root->left, level+1, rMap);
    leftViewMapUtil(root->right, level+1, rMap);

}

void leftViewMap(struct Node* root)
{
    if (root == NULL)
        return ;

    std::map<int, int> myMap;
    leftViewMapUtil(root, 1, myMap);
    std::map<int, int>::iterator itr = myMap.begin();
    for(; itr != myMap.end(); itr++)
        printf("%d ", (*itr).second);

}


int main()
{
    struct Node* root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    printf("Version1: ");
    leftView(root);
    printf("\n");
    printf("Version2: ");
    leftViewMap(root); 
    
    return 0;
}
