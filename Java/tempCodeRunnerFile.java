import java.util.*;

class ArrayX
{
    public int Arr[];
    public int iSize;
    public Boolean bFlag;


    ArrayX(int no)
    {
        // iSize = no;
        // Arr = new int[iSize];
        // bFlag = false;

        this.iSize = no;
        this.Arr = new int[iSize];
        this.bFlag = false;
    }

    void Accept(int no)