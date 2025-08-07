#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

        ArrayX(int no)
        {
            iSize = no;
            Arr = new int[iSize];
        }

        ~ArrayX()
        {
            delete []Arr;
        }

        void Accept()
        {
            cout<<"Enter the elements : \n";
            
            int i =0;

            for(i = 0; i < iSize;i++)
            {
                cin>>Arr[i];
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
            int ilow = 0;
            int ihigh = iSize - 1;
            bool bFlag = false;

            while(ilow <= ihigh)
            {
                int mid = ilow + (ihigh - ilow) / 2;

                if(Arr[mid] == no)
                {
                    bFlag = true;
                    break;
                }
                else if(Arr[mid] > no)
                {
                    ilow = mid + 1;
                }
                else if(Arr[mid] < no)
                {
                    ihigh = mid - 1;
                }
            }

            return bFlag;

        }
};

int main()
{
    ArrayX aobj(5);
    bool bRet = false;

    aobj.Accept();

    aobj.Display();

    bRet = aobj.BinarySearch(30);

    if(bRet == true)
    {
        cout<<"Element is present\n";
    }
    else
    {
        cout<<"Element is not present\n";
    }

    return 0;
}