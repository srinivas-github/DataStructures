/**
 * Input: {1,2,3}
 * Examples:
 *      2
 *     / \
 *    1   3
 *
 * Input: {1,2,3,4}
 *      3
 *     / \
 *    2   4
 *   /
 *  1
 *
 * Algorithm:
 * 1) Get the middle of the array and make it root.
 * 2) Recursivley do the same for left half and right half
 *    a) Get the middle of the left half and make it left child of the root
 *    b) Get the middle of the right half and make it right child of the root
 * Added this line to demo their changes
 */
#include <cstdio>
#include <cstdlib>

struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
};

struct TNode* newNode(int data)
{
    struct TNode* node = (struct TNode*)malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

/**
 * Method that constructs BST from sorted array
 */
struct TNode* sortedArrToBST(int arr[], int start, int end)
{
    /**
     * base condition
     */
    if (start > end)
        return NULL;

   /**
    * Get the middle of the array and make it root 
    */
   int mid = (start + end)/2;
   struct TNode* root = newNode(arr[mid]);

   /**
    * Recursivley construct left subtree and make it has a left child
    */
   root->left = sortedArrToBST(arr, start, mid-1);

   /**
    * Recursivley construct right subtree and make it has a right child
    */
   root->right = sortedArrToBST(arr, mid+1, end);

   return root;
}

void preOrder(struct TNode* root)
{
    if (root == NULL)
        return ;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5,6,7};
   int sz = sizeof(arr)/sizeof(arr[0]);
   struct TNode* root = sortedArrToBST(arr, 0, sz-1);
   preOrder(root);  
   return 0;
}
