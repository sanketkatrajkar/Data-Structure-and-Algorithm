#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = (PNODE) malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if (*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
        newn->next = newn; 
    }
    else 
    {
        newn->next = *first;
        *first = newn;
        (*last)->next = *first;
    }
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = (PNODE) malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
        newn->next = newn; 
    }
    else 
    {
       (*last) -> next = newn;
       *last = newn;
       (*last) -> next = *first;
    }
}

void InsertAtPos(PPNODE first, PPNODE last , int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCount = Count(*first, *last);

    if(pos < 1 || pos > iCount + 1)
    {
       printf("Invalide position\n");
       return;
    }

    if(pos == 1)
    {
        InsertFirst(*first , *last ,no);
    }
    else if(pos == iCount + 1)
    {
         InsertLast(first , last , no);
    }
    else
    {
        newn = (PNODE) malloc(sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;

        temp = *first;

        for(int i = 1; i < pos - 1; i++)
        {
           temp =   temp -> next; 
        }

        newn -> next = temp -> next;
        temp -> next = newn;   
    }  
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

   if(*first ==  NULL && *last == NULL)
   {
      printf("SinglyC LL empty.\n");
      return;  
   }
   else if((*first) -> next == *first)
   {
      free(*first);

      *first = NULL;
      *last = NULL; 
   }
   else
   {
        temp = *first;

        *first = (*first)->next;
        (*last)->next = *first;
        free(temp);
   } 
}

void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if (*first == NULL && *last == NULL)
    {
        printf("SinglyC LL is empty.\n");
        return;
    }
    else if ((*first)->next == *first)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        while (temp->next != *last)
        {
            temp = temp->next;
        }

        free(*last);
        *last = temp;
        (*last)->next = *first;
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    int iCount = Count(*first, *last);
    PNODE temp = *first;
    PNODE target = NULL;

    if (pos < 1 || pos > iCount)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if (pos == iCount)
    {
        DeleteLast(first, last);
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}


void Display(PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    PNODE temp = first;
    do
    {
        printf("| %d | -> ", temp->data);
        temp = temp->next;
    } while(temp != first);

    printf("\n");
}

int Count(PNODE first, PNODE last)
{
    if (first == NULL && last == NULL)
    {
        return 0;
    }

    PNODE temp = first;
    int iCount = 0;

    do
    {
        iCount++;
        temp = temp->next;
    } while (temp != first);

    return iCount;
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head, &tail, 51);
    InsertFirst(&head, &tail, 21);
    InsertFirst(&head, &tail, 11);

    InsertLast(&head, &tail, 101);
    InsertLast(&head, &tail, 121);
    InsertLast(&head, &tail, 151);

    Display(head, tail);
    iRet = Count(head,tail);

    printf("Number of the element in LL are : %d\n", iRet);

    // DeleteFirst(&head, &tail);

    // Display(head, tail);
    // iRet = Count(head,tail);

    // printf("Number of the element in LL are : %d\n", iRet);

    // DeleteLast(&head, &tail);

    // Display(head, tail);
    // iRet = Count(head,tail);

    // printf("Number of the element in LL are : %d\n", iRet);

    InsertAtPos(&head , &tail , 105, 5);
    Display(head, tail);
    iRet = Count(head,tail);

    printf("Number of the element in LL are : %d\n", iRet);

    DeleteAtPos(&head , &tail, 5);

    Display(head, tail);
    iRet = Count(head,tail);

    printf("Number of the element in LL are : %d\n", iRet);

    return 0;
}
