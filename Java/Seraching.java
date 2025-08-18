import java.util.*;

class ArrayX
{
    public int Arr[];
    public int iSize;

    ArrayX(int no)
    {
        this.iSize = no;
        this.Arr = new int[iSize];
    }

    void Accept()
    {
        Scanner aobj = new Scanner(System.in);
        System.out.println("Enter the elements of array : ");
        for(int i = 0; i < iSize; i++)
        {
            Arr[i] = aobj.nextInt();
        }
    }

    void Display()
    {
        System.out.println("Elements of the Array are : ");
        for(int i = 0; i < iSize; i++)
        {
            System.out.print(Arr[i] + "\t");
        }
        System.out.println();
    }

    boolean BinarySearch(int no)
    {
        int iStart = 0;
        int iEnd = iSize - 1;

        while(iStart <= iEnd)
        {
            int iMid = iStart + (iEnd - iStart) / 2;

            if(Arr[iMid] == no)
            {
                return true;
            }
            else if(no < Arr[iMid])
            {
                iEnd = iMid - 1;
            }
            else
            {
                iStart = iMid + 1;
            }
        }
        return false;
    }
}

class Searching
{
    public static void main(String A[])
    {
        Scanner lobj = new Scanner(System.in);

        System.out.print("Enter the size of Array : ");
        int iLength = lobj.nextInt();

        ArrayX aobj = new ArrayX(iLength);

        aobj.Accept();
        aobj.Display();

        System.out.print("Enter the element that you want to search : ");
        int iValue = lobj.nextInt();

        boolean bRet = aobj.BinarySearch(iValue);

        if(bRet)
        {
            System.out.println("Element is present");
        }
        else
        {
            System.out.println("Element is not present");
        }
    }
}
