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

void rightViewUtil(struct Node* root, int level, int* max_level)
{
    if (root == NULL)
        return ;
    if (*max_level < level)
    {
        printf("%d ", root->data);
        *max_level = level;
    }

    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);
}
void rightView(struct Node* root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

void rightViewUtilMap(struct Node* root, int level, std::map<int, int>& rMap)
{
    if (root == NULL)
        return ;
    if (rMap.find(level) == rMap.end())
        rMap[level] = root->data;

     rightViewUtilMap(root->right, level+1, rMap);
     rightViewUtilMap(root->left, level+1, rMap);
}

void rightViewMap(struct Node* root)
{
    if (root == NULL)
        return ;

    std::map<int, int> myMap;
    rightViewUtilMap(root, 1, myMap);

    std::map<int, int>::iterator itr = myMap.begin();
    for(; itr != myMap.end(); itr++)
        printf("%d ", (*itr).second);
}

int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->left->left = newNode(30);
    root->left->right = newNode(40);

    root->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);

    printf("Version1: ");
    rightView(root);
    printf("Version2: ");
    rightViewMap(root);
    printf("\n");

    return 0;
}
