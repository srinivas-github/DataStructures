#include <cstdio>
#include <cstdlib>
#include <map>
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
    temp->left = temp->right = NULL;
    return temp;
}

void getVerticalOrder(struct Node* root, int hd, std::map<int, std::vector<int> > &rMap)
{
    if (root == NULL)
        return ;
    rMap[hd].push_back(root->data);
    getVerticalOrder(root->left, hd-1, rMap);
    getVerticalOrder(root->right, hd+1, rMap);
}
void printVerticalOrder(struct Node* root)
{
   int hd = 0;
   std::map<int, std::vector<int> > m;
   getVerticalOrder(root, hd, m);
   
   std::map<int, std::vector<int> >::iterator itr = m.begin();
   for(; itr != m.end(); itr++)
   {
       for(int i = 0; i < itr->second.size(); i++)
       {
           printf("%d  ", itr->second[i]);
       }
       printf("\n");
   }
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->left->right = newNode(8);
    root->right->right = newNode(7);
    root->right->right->right = newNode(9);
    printVerticalOrder(root);
    return 0;
}
