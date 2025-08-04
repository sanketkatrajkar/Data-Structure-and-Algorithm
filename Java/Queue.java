class node 
{
    public int data;
    public node next;
};

class QueueX
{
    private node first;
    private int iCount;

    public QueueX()
    {
       this.first = null;
       this.iCount = 0;
    }

    public void enqueue(int no)   //// InsertLast 
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
           node temp = first;
          
           while(temp.next != null)
           {
             temp = temp.next;
           }

           temp.next = newn; 
       }
       iCount++;
    }

    public int  dequeue()    //Deletefirst
    {
        if(first == null)
        {
            System.out.println("Unable to dequeue in queue :");
            return -1;
        }
        else
        {
             node temp = first;

             first = first.next;
             iCount--;
             return temp.data;
        }
    }

    public void Display()
    {
        node temp = first;

        while(temp != null)
        {
            System.out.print("| "+temp.data+" | -");
            temp = temp.next;
        }
    }

    public int Count()
    {
        return iCount;
    }

    
}

public class Queue 
{
    public static void main(String[] args) 
    {
        QueueX sobj = new QueueX();
        int iRet = 0;

        sobj.enqueue(10);
        sobj.enqueue(20);
        sobj.enqueue(30);
        sobj.enqueue(40);
        sobj.enqueue(50);
        sobj.enqueue(60);

        sobj.Display();
        iRet = sobj.Count();

        System.out.println("Number of the element queue are :" + iRet);

        iRet = sobj.dequeue();
        System.out.println("Remove the element form queue :"+ iRet);

        iRet = sobj.dequeue();
        System.out.println("Remove the element form queue :"+ iRet);

        iRet = sobj.dequeue();
        System.out.println("Remove the element form queue :"+ iRet);

        sobj.Display();
        iRet = sobj.Count();

        System.out.println("Number of the element queue are :" + iRet);
    }
}
