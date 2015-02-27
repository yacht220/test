/*
 * BST Utility
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utility.h"

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
