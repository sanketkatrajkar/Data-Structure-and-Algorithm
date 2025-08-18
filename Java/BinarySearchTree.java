
class node
{
    public int data;
    public node lchild;
    public node rchild;
}

class BST
{
    private node first;
    private int iCount;

    public BST()
    {
        first = null;
        iCount = 0;
    }

    public void Insert(int no)
    {
        node newn = null;
        newn = new node();

        newn.data = no;
        newn.lchild = null;
        newn.rchild = null;

        if(first.data == no)
        {
           System.out.println("Unable to Insert element doublycate elemente ");
           return;
        }

        if(first == null)
        {
            
        }
    }

}

class BinarySearchTree
{
    public static void main(String A[])
    {

    }
}