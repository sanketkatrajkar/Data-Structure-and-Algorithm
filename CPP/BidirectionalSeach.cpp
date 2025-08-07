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

        bool Bidirectional(int no)
        {
            int iStart = 0;
            int iEnd = iSize - 1;
            bool bFlag = false;

            for(iStart = 0, iEnd = iSize; iStart <= iEnd; iStart++, iEnd--)
            {
                if(Arr[iStart] == no || Arr[iEnd] == no)
                {
                    bFlag = true;
                    break;
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

    bRet = aobj.Bidirectional(30);

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