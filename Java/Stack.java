
class node 
{
    public int data;
    public node next;
    
};

class StackX 
{
    private node first;
    private int iCount;

    public StackX()
    {
       this.first = null;
       this.iCount = 0;
    }

    public void push(int no) //Insert First
    {
        node newn = null;
        newn = new node();

        newn.data = no;
        newn.next = null;
       
        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        iCount++;
    }

    public int pop()   //DeleteFirst
    {
        node temp = first;

        if(this.first == null)
        {
            System.out.println("Unbale to pop the element :");
            return -1;
        }
        else
        {
           first = first.next;
            iCount--;
            return temp.data;
        }
    }

    public void Display()
    {
        node temp = null;
        temp = first;

        while(temp != null)
        {
            System.out.println("| "+temp.data+" |");
            temp = temp.next;
        }
        // System.out.println("NUll");
    }

    public int Count()
    {
        return iCount;
    }


}
public class Stack
{
    public static void main (String args[])
    {
       StackX sobj = new StackX();
       int iRet = 0;

       sobj.push(11);
       sobj.push(12);
       sobj.push(13);
       sobj.push(14);
       sobj.push(15);

       sobj.pop();
       sobj.pop();

       sobj.Display();
       iRet = sobj.Count();
       System.out.println("Number of the Element in the stack :"+ iRet);
    }
}