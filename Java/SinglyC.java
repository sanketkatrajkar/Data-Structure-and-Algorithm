// Singly Circular Linked list 

class node
{
    public int data;
    public node next;    
}

class SinglyCLL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCLL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node();

        newn.data = no;
        newn.next = null;

        if(first == null && last == null) // Contain 0 node 
        {
            first = newn;
            last = newn;

            last.next = first;
        }
        else
        {
            newn.next = first;
            first = newn;

            last.next = first;
        }

        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = new node();
        newn.data = no;
        newn.next = null;

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
            last.next = first;
        }
        else
        {
            last.next = newn;
            last = newn;
            last.next = first;
        }

        iCount++;
    }
    
    public void DeleteFirst()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
           first = null;
           last = null;
        }
        else
        {
            first = first.next;            
            last.next = first; 
        }
        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if (first == null)  
        {
            return;
        }
        else if (first == last)  
        {
            first = null;
            last = null;
        }
        else
        {
             temp = first;
    
            while (temp.next != last)  
            {
                temp = temp.next;
            }
    
            last = temp;         
            last.next = first;   
        }
    
        iCount--;
    }
    

    public void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;
        int i = 0;

        if(pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalide positon \n");
            return;
        }
        
        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {
            InsertLast(no);
        }
        else 
        {
           newn = new node();
   
           newn.data = no;
           newn.next = null;
   
           temp = first;
   
           for( i = 1; i < pos - 1; i++)
           {
               temp = temp.next;
           }

           newn.next = temp.next;
           temp.next = newn;
        }
        iCount++;
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;

        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalide positon \n");
            return;
        }
        
        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount)
        {
            DeleteLast();
        }
        else 
        {
      
           temp = first;
   
           for( iCnt = 0; iCnt < pos - 1; iCnt++)
           {
               temp = temp.next;
           }
           
           temp.next = temp.next.next;

           iCount--;
           
        }
    }
    
    public void Display()
    {
        if(first == null && last == null)
        {
            return;
        }

        node temp = null;

        temp = first;

        do 
        { 
            System.out.print("| "+temp.data+" |-> ");
            temp = temp.next;
        } while (temp != first);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

class SinglyC
{
    public static void main(String A[])
    {
        SinglyCLL sobj = new SinglyCLL();
        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);        
        sobj.InsertLast(121);

        sobj.Display();
    
        iRet = sobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        // sobj.DeleteFirst();

        // sobj.Display();
    
        // iRet = sobj.Count();

        // System.out.println("Number of elements in the LinkedList are : "+iRet);

        // sobj.DeleteLast();

        // sobj.Display();
    
        // iRet = sobj.Count();

        // System.out.println("Number of elements in the LinkedList are : "+iRet);

        sobj.InsertAtPos(105,5);

        sobj.Display();
    
        iRet = sobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        sobj.DeleteAtPos(5);

        sobj.Display();
    
        iRet = sobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);
    }
}