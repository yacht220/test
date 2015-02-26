#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

struct Node 
{
  Node *left;
  Node *right;
  int num;
};

typedef Node* PNode;

void insertBST(PNode* root, int value)
{
    PNode* ptrNode = NULL;

    if(NULL == *root)
    {
        *root = (PNode)malloc(sizeof(Node));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->num = value;
    }
    else
    {
        ptrNode = root;
        while(NULL != *ptrNode)
        {
            if(value < (*ptrNode)->num)
            {
                ptrNode = &(*ptrNode)->left;
            }
            else
            {
                ptrNode = &(*ptrNode)->right;
            }
        }
        
        *ptrNode = (PNode)malloc(sizeof(Node));
        (*ptrNode)->left = NULL;
        (*ptrNode)->right = NULL;
        (*ptrNode)->num = value;
    }   
}

void createBST(PNode *t)
{        
    printf("Create binary search tree.\n");
    int array[ARRAY_SIZE] = {5,2,1,4,7,8,3,6,9,10};
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        insertBST(t, array[i]);
    }
}  

int findNthMaxImp(Node *root, int &n)
{
    static int sResult = 0;
    if(root)
    {
        findNthMaxImp(root->right, n);  
        printf("%d, ", root->num);
        n--;
        if(n == 0)      
        {
            sResult = root->num;
        }
        findNthMaxImp(root->left, n);
    }
    return sResult;
}

int findNthMaxNumber(Node *root, int N)
{
    printf("Traverse BST with order right->parent->left.\n");
    return findNthMaxImp(root, N);
}


int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("usage: binary_search_tree.exe <nth_max_num_index>\n");
        printf("       <nth_max_num_index> - 1...%d\n", ARRAY_SIZE);
        return -1;
    }
    char* inputNthMaxIndexChar = argv[1];
    int nthMax = atoi(inputNthMaxIndexChar);
    PNode root = NULL;
    int result = 0;
    
    if(nthMax <=0 || nthMax > ARRAY_SIZE)
    {
        printf("Please input <nth_max_num_index> with range 1...%d.\n", ARRAY_SIZE);
        return -1;
    }
    createBST(&root);
    result = findNthMaxNumber(root, nthMax);
    printf("\n\nThe %dth max number = %d", nthMax, result);
    
    return 1;
}