#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;

        ArrayX(int no)
        {
            iSize = no;
            Arr = new int[iSize];
            Sorted = true;
        }

        ~ArrayX()
        {
            delete []Arr;
        }

        void Accept()
        {
            cout<<"Enter "<<iSize<<" elements : \n";
            
            int i =0;                      

            for(i = 0; i < iSize;i++)
            {
                cout<<"Enter the element no : "<<i+1<<"\n";
                cin>>Arr[i];

                // if((i > 0) && (Sorted == true))
                // {
                //     if(Arr[i] < Arr[i-1])
                //     {
                //         Sorted = false;
                //     }
                // }
            }
        }

        void Display()
        {
            cout<<"Elements of the array are : \n";
            
            int i = 0;

            for(i = 0; i < iSize; i++)
            {
                cout<<Arr[i]<<"\t";
            }
            cout<<"\n";
        }

        bool BinarySearch(int no)
        {
            int iMid = 0, iEnd = 0, iStart = 0;

            bool bFlag = false; 
            iEnd = iSize - 1;
           

            while (iStart <= iEnd)
            {
                iMid = iStart + (iEnd - iStart) / 2;
                
                if(Arr[iMid] == no)
                {
                    bFlag = true;
                    break;
                }
                else if(no < Arr[iMid])
                {
                    iEnd = iMid - 1;
                }
                else if(no > Arr[iMid])
                {
                    iStart = iMid + 1;
                }
            }
            
            return bFlag; 
        }
};

int main()
{
    int iLength = 0 , iValue = 0;
    bool bRet = false;

    cout<<"Enter the size of array : \n";
    cin>>iLength;

    ArrayX *aobj = new ArrayX(iLength);

    aobj->Accept();

    aobj->Display();

    cout << "Enter the element that you want to search : \n";
    cin >> iValue;

    bRet = aobj -> BinarySearch(iValue);

    if(bRet == true)
    {
        cout <<"Element is present \n";
    }
    else 
    {
        cout <<"Element in not present\n";
    }

    delete aobj;
    
    return 0;
}