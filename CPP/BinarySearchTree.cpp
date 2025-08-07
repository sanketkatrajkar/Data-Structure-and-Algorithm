#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* rchild;
    struct node* lchild;
};

typedef struct node NODE;
typedef struct node* PNODE;

class BST
{
private:
    PNODE root;

public:
    BST()
    {
        root = NULL;
    }

    void Insert(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->lchild = NULL;
        newn->rchild = NULL;

        if (root == NULL)
        {
            root = newn;
            return;
        }

        PNODE temp = root;

        while (true)
        {
            if (no == temp->data)
            {
                cout << "Duplicate element not allowed: " << no << "\n";
                delete newn;
                break;
            }
            else if (no < temp->data)
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else // no > temp->data
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
        }
    }

    void Inorder()
    {
        InorderHelper(root);
        cout << "\n";
    }

    void InorderHelper(PNODE temp)
    {
        if (temp != NULL)
        {
            InorderHelper(temp->lchild);
            cout << temp->data << "\t";
            InorderHelper(temp->rchild);
        }
    }

    bool Search(int no)
    {
        PNODE temp = root;

        while (temp != NULL)
        {
            if (no == temp->data)
            {
                return true;
            }
            else if (no < temp->data)
            {
                temp = temp->lchild;
            }
            else
            {
                temp = temp->rchild;
            }
        }
        return false;
    }
};

int main()
{
    BST obj;
    obj.Insert(30);
    obj.Insert(20);
    obj.Insert(40);
    obj.Insert(10);

    cout << "Inorder traversal:\n";
    obj.Inorder();

    int iSearch = 10;
    if (obj.Search(iSearch))
    {
        cout << "Element " << iSearch << " is present\n";
    }
    else
    {
        cout << "Element " << iSearch << " is not present\n";
    }

    return 0;
}
