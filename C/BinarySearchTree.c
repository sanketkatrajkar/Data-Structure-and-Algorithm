#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node 
{
    int data;
    struct node * lchild;
    struct node * rchild;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Insert(PPNODE first , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*first == NULL)
    {
       *first = newn;
    }
    else
    {
        PNODE temp = NULL;

        temp = *first;

       while (1)
       {
           if(no == temp -> data)
           {
              printf("Dublicate data Inserted : unable to insert the data \n");
              free(newn);
              break;
           }
           else if(no > temp -> data)
           {
             if( temp -> rchild == NULL)
             {
                temp -> rchild = newn;
                break;
             }
             temp = temp -> rchild;
           }
           else if(no < temp -> data)
           {
             if(temp -> lchild == NULL)
             {
                temp -> lchild = newn;
                break;
             }
             temp = temp -> lchild;
           }
       }
    }
}

void Inorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\t",first->data);
        Inorder(first->lchild);
        Inorder(first->rchild);
    }
}

void Preorder(PNODE first)
{
    if(first != NULL)
    {
        Preorder(first->lchild);
        printf("%d\t",first->data);
        Preorder(first->rchild);
    }
}

void Postorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\t",first->data);
        Postorder(first->lchild);
        Postorder(first->rchild);
    }
}

bool Search(PNODE first , int no)
{
    bool bFlag = false;

    while (first != NULL)
    {
        if(no == first->data)
        {
            bFlag = true;
            break;
        }
        else if(no > first -> rchild)
        {
            first = first ->rchild;
        }
        else if(no < first -> lchild)
        {
            first = first -> lchild;
        }

        return bFlag;
    } 
}

int Count(PNODE first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        iCount++;
        Count(first ->lchild);
        Count(first->rchild);
    }

    return iCount; 
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;
    bool bRet = false;

    Insert(&head,30);
    Insert(&head,20);
    Insert(&head,40);

    printf("Preorder Display :\n");
    Preorder(head);

    // printf("Inorder Display :\n");
    // Inorder(head);

    // printf("Postorder Display :\n");
    // Postorder(head);

    printf("\n");
    bRet = Search(head,30);
    if(bRet == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("Element is not present\n");
    }

    iRet = Count(head);

    printf("Number of element in BST is : %d" , iRet);

    return 0;
}