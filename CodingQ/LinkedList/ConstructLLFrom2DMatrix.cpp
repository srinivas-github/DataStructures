/**
 * Given a matrix. Convert it into a linked list matrix such that 
 * each node is connected to its next right and down node.
 * Example:
 *   Input : 2D matrix 
 *     1 2 3
 *     4 5 6
 *     7 8 9
 *   Output :
 *     1 -> 2 -> 3 -> NULL
 *     |    |    |
 *     v    v    v
 *     4 -> 5 -> 6 -> NULL
 *     |    |    |
 *     v    v    v
 *     7 -> 8 -> 9 -> NULL
 *     |    |    |
 *     v    v    v
 *     NULL NULL NULL
 */
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node* down;
    struct Node* right;
};

void display(struct Node* head)
{
    struct Node* ptrR;
    struct Node* ptrD = head;

    while (ptrD)
    {
        ptrR = ptrD;
        while (ptrR)
        {
            printf("%d ", ptrR->data);
            ptrR = ptrR->right;
        }
        printf("\n");
        ptrD = ptrD->down;
    }

}

struct Node* constructLL(int arr[][3], int i, int j, int m, int n)
{
    if (i > n-1 || j > m-1)
        return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = arr[i][j];
    temp->right = constructLL(arr, i, j+1, m, n);
    temp->down =  constructLL(arr, i+1, j, m, n);
    return temp;
    
}

int main()
{
    int arr[][3] = {
                     {1,2,3},
                     {4,5,6},
                     {7,8,9}
                   };
    int m = 3, n =3;
    struct Node* head = constructLL(arr, 0,0,m, n);
    display(head);
    return 0;
}
