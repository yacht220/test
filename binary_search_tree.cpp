#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node 
{
  Node *left;
  Node *right;
  char num;
};

typedef Node* PNode;

void createBST(PNode *t)
{        
    char c = getchar();  
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
    }  
}  

void reverseMidorder(Node *root)
{
    if(root)
    {
        reverseMidorder(root->right);        
        printf("%c\n",root->num);
        reverseMidorder(root->left);
    }
}

int main(int argc, char **argv)
{
    PNode root;
    createBST(&root);
    reverseMidorder(root);
    
    return 1;
}