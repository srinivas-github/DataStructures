/**
 * You are given two balanced binary search trees e.g., AVL or Red Black Tree. 
 * Write a function that merges the two given balanced BSTs into a balanced binary search tree. 
 * Let there be m elements in first tree and n elements in the other tree. 
 * Your merge function should take O(m+n) time.
 * Algorithm:
 * 1) Do inorder traversal of first tree and store the traversal in one temp array arr1[]. This step takes O(m) time.
 * 2) Do inorder traversal of second tree and store the traversal in another temp array arr2[]. This step takes O(n) time.
 * 3) The arrays created in step 1 and 2 are sorted arrays. Merge the two sorted arrays into one array of size m + n. 
 *    This step takes O(m+n) time.
 * 4) Construct a balanced tree from the merged array. This step takes O(m+n) time.
 */

#include <cstdio>
#include <cstdlib>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/**
 * method to merge two sorted arrays into one.
 */
int* merge(int arr1[], int arr2[], int m, int n)
{
    /**
     * mergedArr is going to contain result
     */
    int *mergedArr =  new int[m + n];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }
    return mergedArr;
}

/**
 * A helper function that stores inorder traversal of a tree in inorder array
 */
void storeInorder(struct node* node, int inorder[], int *index_ptr)
{
    if (node == NULL)
        return ;
    storeInorder(node->left, inorder, index_ptr);
   
    inorder[*index_ptr] = node->data;
    (*index_ptr)++;

    storeInorder(node->right, inorder, index_ptr);
}

struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
/* A function that constructs Balanced Binary Search Tree from a sorted array
   See http://www.geeksforgeeks.org/archives/17138 */
struct node* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;

    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct node *root = newNode(arr[mid]);

    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =  sortedArrayToBST(arr, start, mid-1);

    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}

/**
 * This function merges two balanced BSTs with roots as root1 and root2.
 * m and n are the sizes of the trees respectively 
 */
struct node* mergeTrees(struct node *root1, struct node *root2, int m, int n)
{
    /**
     * Store inorder traversal of first tree in an array arr1[]
     */
    int *arr1 = new int[m];
    int i = 0;
    storeInorder(root1, arr1, &i);
 
    /**
     * Store inorder traversal of second tree in another array arr2[]
     */
    int *arr2 = new int[n];
    int j = 0;
    storeInorder(root2, arr2, &j);
 
    /**
     * Merge the two sorted array into one
     */
    int *mergedArr = merge(arr1, arr2, m, n);
 
    /**
     * Construct a tree from the merged array and return root of the tree
     */
    return sortedArrayToBST(mergedArr, 0, m+n-1);
}

/**
 * A utility function to print inorder traversal of a given binary tree
 */
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Driver program to test above functions*/
int main()
{
    /* Create following tree as first balanced BST
           100
          /  \
        50    300
       / \
      20  70
    */
    struct node *root1  = newNode(100);
    root1->left         = newNode(50);
    root1->right        = newNode(300);
    root1->left->left   = newNode(20);
    root1->left->right  = newNode(70);

    printInorder(root1);
 
    /* Create following tree as second balanced BST
            80
           /  \
         40   120
    */
    struct node *root2  = newNode(80);
    root2->left         = newNode(40);
    root2->right        = newNode(120);
    printInorder(root2);
 
    struct node *mergedTree = mergeTrees(root1, root2, 5, 3);
 
    printf ("Following is Inorder traversal of the merged tree \n");
    printInorder(mergedTree);
    return 0;
}
