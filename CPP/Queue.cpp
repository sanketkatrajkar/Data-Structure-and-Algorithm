#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

class QueueX
{
private:
    struct node *first;
    int iCount;

public:
    QueueX();        
    void enqueue(int no);      
    void dequeue();               
    void Display(); 
    int Count();             
};

QueueX::QueueX()
{
    first = NULL;
    iCount = 0;
}

void QueueX::enqueue(int no)
{
    struct node *newn = new node();
    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        struct node *temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

void QueueX::dequeue()
{
    if (first == NULL)
    {
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }

    struct node *temp = first;

    first = first->next;
    delete temp;
    iCount--;
}

void QueueX::Display()
{
    struct node *temp = first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }
}

int QueueX::Count()
{
    return iCount;
}

int main()
{
    QueueX *qobj = new QueueX();
    int iRet = 0;

    qobj->enqueue(51);
    qobj->enqueue(21);
    qobj->enqueue(11);
    qobj->enqueue(101);
    qobj->enqueue(71);

    qobj->Display();

    iRet = qobj->Count();
    cout << "Number of elements in the queue: " << iRet << "\n";

    qobj->dequeue();
    qobj->dequeue();
    qobj->dequeue();

    qobj->Display();

    iRet = qobj->Count();
    cout << "Number of elements in the queue: " << iRet << "\n";

    delete qobj;

    return 0;
}
