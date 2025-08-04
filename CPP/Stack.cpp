#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

class StackX
{
private:
    struct node *first;
    int iCount;

public:
    StackX();        
    void push(int no);      
    int pop();               
    void Display(); 
    int Count();             
};

StackX::StackX()
{
    first = NULL;
    iCount = 0;
}

void StackX :: push(int no)
{
    struct node *newn = new node();

    newn-> data = no;
    newn -> next = NULL;

    // first = newn;

    newn -> next = first;
    first = newn;

    iCount++;
}

int StackX :: pop()
{
    struct node *temp = first;
    int value = 0;

    if(first == NULL)
    {
        cout << "Unable to pop the elmenet in stack:\n" << endl;
        return -1; 
    }
    else
    {
        temp = first;
        value = temp -> data;
        
        first  = first -> next;
        delete temp;

        iCount--;
        return value;
    }

}

void StackX::Display()
{
    struct node *temp = first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |\n";
        temp = temp->next;
    }
    cout << "\n";
}

int StackX::Count()
{
    return iCount;
}

int main()
{
    StackX *sobj = new StackX();

    int iRet = 0;

    sobj->push(10);
    sobj->push(20);
    sobj->push(30);

    sobj->Display();

    iRet = sobj->Count();
    cout << "Number of elements in the stack: " << iRet << "\n";

    iRet = sobj->pop();
    cout << "Popped element is: " << iRet << "\n";

    iRet = sobj->pop();
    cout << "Popped element is: " << iRet << "\n";

    iRet = sobj->pop();
    cout << "Popped element is: " << iRet << "\n";

    sobj->Display();

    iRet = sobj->Count();
    cout << "Number of elements in the stack: " << iRet << "\n";

    delete sobj;

    return 0;
}