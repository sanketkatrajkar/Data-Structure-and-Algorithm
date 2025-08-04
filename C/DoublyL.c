#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (*first == NULL)
    {
        *first = newn;
    }
    else
    {
        PNODE temp = *first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
}

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d | <-> ", first->data);
        first = first->next;
    }

    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

void DeleteFirst(PPNODE first)
{
    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
       PNODE temp = NULL;

       temp = *first;
       *first = (*first) -> next;
       free(temp);
       (*first) -> prev = NULL;
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp -> next != NULL)
        {
           temp = temp -> next;
        }
        
        temp -> prev -> next = NULL;
        free(temp);
    }
}

void InsertAtPos(PPNODE first, int no, int pos)
{
    int iCount = Count(*first);
    int iCnt = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    if((pos < 1) || (pos > iCount + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;
    }
}


void DeleteAtPos(PPNODE first, int pos)
{
    int iCount = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);

    if((pos < 1) || (pos > iCount))
    {
        printf("Invalide position \n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if (pos == iCount)
    {
        DeleteLast(first);
    }
    else
    {

        temp = *first;

        for(iCnt = 1; iCnt < pos - 1 ; iCnt++)
        {
            temp = temp -> next;

        }

        target = temp -> next;

        temp -> next = target -> next;
        target -> next -> prev = temp; 

        free(target);
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    InsertLast(&head, 101);
    InsertLast(&head, 121);
    InsertLast(&head, 151);

    Display(head);
    iRet = Count(head);
    printf("Number of elements in LL are: %d\n", iRet);

    // DeleteFirst(&head);
    // Display(head);
    // iRet = Count(head);
    // printf("Number of elements in LL are: %d\n", iRet);

    // DeleteLast(&head);
    // Display(head);
    // iRet = Count(head);
    // printf("Number of elements in LL are: %d\n", iRet);

    InsertAtPos(&head, 75, 5);

    Display(head);
    iRet = Count(head);
    printf("Number of elements in LL are: %d\n", iRet);

    DeleteAtPos(&head, 5);

    Display(head);
    iRet = Count(head);
    printf("Number of elements in LL are: %d\n", iRet);

    return 0;
}
