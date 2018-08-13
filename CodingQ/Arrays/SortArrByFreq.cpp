#include <stdlib.h>
#include <stdio.h>

struct BSTNode
{
    int data;
    int freq;
    struct BSTNode* left;
    struct BSTNode* right;
};

struct dataFreq
{
    int freq;
    int data;
};

struct BSTNode* newNode(int data)
{
    struct BSTNode* temp = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    temp->data = data;
    temp->freq = 1;
    temp->left = temp->right= NULL;
    return temp;
}

struct BSTNode* insert(struct BSTNode* root, int data)
{
    if (root == NULL)
        return newNode(data);
    if (root->data == data)
        root->freq += 1;
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}


int compare(const void* a, const void* b)
{
    return ( (*(const dataFreq*)b).freq - (*(const dataFreq*)a).freq );
}

void store(struct BSTNode* root, dataFreq count[], int* index)
{
    if (root == NULL)
        return ;
    store(root->left, count, index);
    
    count[(*index)].freq = root->freq;
    count[(*index)].data = root->data;
    (*index)++;
    
    store(root->right, count, index);
}

void sortByFreq(int arr[], int n)
{
    struct BSTNode* root = NULL;
    
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);
        
    dataFreq count[n];
    int index = 0;
    store(root, count, &index);
    
    qsort(count, index, sizeof(count[0]), compare);
    
    int j = 0;
    
    for (int i = 0; i < index; i++)
    {
        for (int freq = count[i].freq; freq >= 0; freq--)
        {
            arr[j++] = count[i].data;
        }
    }
}

int main()
{
    int arr[] = {2,3,2,3,4,5,2,5,5,8,6,8,8,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortByFreq(arr, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
