#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (*first == NULL)
    {
        *first = *last = newn;
        newn->next = newn;
        newn->prev = newn;
    }
    else
    {
        newn->next = *first;
        newn->prev = *last;

        (*first)->prev = newn;
        (*last)->next = newn;
        *first = newn;
    }
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (*first == NULL)
    {
        *first = *last = newn;
        newn->next = newn;
        newn->prev = newn;
    }
    else
    {
        newn->next = *first;
        newn->prev = *last;

        (*last)->next = newn;
        (*first)->prev = newn;
        *last = newn;
    }
}

int Count(PNODE first, PNODE last)
{
    if (first == NULL)
    {
        return 0;
    }

    int count = 0;
    PNODE temp = first;

    do
    {
        count++;
        temp = temp->next;
    } while (temp != first);

    return count;
}

void Display(PNODE first, PNODE last)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    PNODE temp = first;

    do
    {
        printf("| %d | <=> ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("\n");
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    int size = Count(*first, *last);

    if (pos < 1 || pos > size + 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        InsertFirst(first, last, no);
    }
    else if (pos == size + 1)
    {
        InsertLast(first, last, no);
    }
    else
    {
        PNODE temp = *first;
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    if (*first == NULL)
    {
        return;
    }
    else if (*first == *last)
    {
        free(*first);
        *first = *last = NULL;
    }
    else
    {
        PNODE temp = *first;

        *first = (*first)->next;
        (*first)->prev = *last;
        (*last)->next = *first;
        
        free(temp);
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    if (*first == NULL)
    {
        return;
    }
    else if (*first == *last)
    {
        free(*first);
        *first = *last = NULL;
    }
    else
    {
        PNODE temp = *last;
        *last = (*last)->prev;
        (*last)->next = *first;
        (*first)->prev = *last;
        free(temp);
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    int size = Count(*first, *last);

    if (pos < 1 || pos > size)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if (pos == size)
    {
        DeleteLast(first, last);
    }
    else
    {
        PNODE temp = *first;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        PNODE target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        free(target);
    }
}


int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head, &tail, 30);
    InsertFirst(&head, &tail, 20);
    InsertFirst(&head, &tail, 10);

    InsertLast(&head, &tail, 40);
    InsertLast(&head, &tail, 50);

    Display(head, tail);
    printf("Count: %d\n", Count(head, tail));

    InsertAtPos(&head, &tail, 25, 3);
    Display(head, tail);

    DeleteFirst(&head, &tail);
    Display(head, tail);

    DeleteLast(&head, &tail);
    Display(head, tail);

    DeleteAtPos(&head, &tail, 3);
    Display(head, tail);

    return 0;
}
