#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

//int gResult = 0;

struct Node 
{
  Node *left;
  Node *right;
  int num;
};

typedef Node* PNode;

void insertBST(PNode* root, int value)
{
    //printf("%d\n", value);
    PNode* ptrNode = NULL;
    //PNode ptrNodeTmp = NULL;
    if(NULL == *root)
    {
        //printf("hello1\n");
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
            //printf("hello2\n");
            //ptrNodeTmp = ptrNode;
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
    /*char c = getchar();  
    if(c == '#')  
    {
        *t = NULL;  
    }
    else
    {  
        *t = (PNode)malloc(sizeof(Node));  
        printf("hello1\n");
        createBST(&(*t)->left); 
        printf("hello2\n");
        (*t)->num = c;   
        printf("hello3\n");
        createBST(&(*t)->right);  
        printf("hello4\n");
    }*/

    int array[ARRAY_SIZE] = {5,2,1,4,7,8,3,6,9,10};
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        insertBST(t, array[i]);
    }
}  

int findNthMax(Node *root, int &n)
{
    static int sResult = 0;
    if(root)
    {
        findNthMax(root->right, n);  
        printf("%d\n", root->num);
        n--;
        if(n == 0)      
        {
            //printf("%dth max %d\n", nTmp, root->num);
            sResult = root->num;
        }
        findNthMax(root->left, n);
    }
    return sResult;
}

int FindNthMaxNumber(Node *root, int N)
{
    return findNthMax(root, N);
}


int main(int argc, char **argv)
{
    PNode root = NULL;
    createBST(&root);
    int nthMax = 4;
    int result = FindNthMaxNumber(root, nthMax);
    printf("%dth max %d", nthMax, result);
    
    return 1;
}