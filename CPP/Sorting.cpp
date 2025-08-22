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

                if((i > 0) && (Sorted == true))
                {
                    if(Arr[i] < Arr[i-1])
                    {
                        Sorted = false;
                    }
                }
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

        void BubbleSort(int no)
        {
            int i = 0, j = 0, temp = 0;
            bool bFlag = true;

            if(Sorted == true)
            {
                return;
            }
            
            for(i = 0; (i < iSize && bFlag == true); i++)  /// Bubble Sort
            {
                bFlag = false;

                for(j = 0; j < iSize - 1 - i; j++)      
                {
                    if(Arr[j] > Arr[j + 1])
                    {
                        temp = Arr[j];
                        Arr[j] = Arr[j + 1];
                        Arr[j + 1] = temp;

                        bFlag = true;
                    }
                }
            }
         }

            void SelectionSort(int no)   ////Selection Sort
            {
                int i = 0, j = 0, temp = 0;
                int min_index = 0;

                bool bFlag = true;
    
                if(Sorted == true)
                {
                    return;
                }
            
                for(i = 0; i < iSize; i++)    
                {
                    min_index = i;
    
                    for(j = i + 1; j < iSize; j++)
                    {
                        if(Arr[min_index] < Arr[j])
                        {
                           min_index = j; 
                        }
                    }

                    temp = Arr[min_index];
                    Arr[min_index] = Arr[i];
                    Arr[i]  = temp;
                }

                Sorted = true;
            }

            void InsertionSort(int no)
            {
                int i = 0, j = 0, selected = 0;
    
                for(i = 1; i < iSize; i++)
                {
                    for(j = i - 1,selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
                    {
                        Arr[j + 1] = Arr[j]; 
                    }
                    Arr[j + 1] = selected;
                }
            }
          
};

int main()
{
    int iLength = 0;

    cout<<"Enter the size of array : \n";
    cin>>iLength;

    ArrayX *aobj = new ArrayX(iLength);

    aobj->Accept();

    aobj->Display();

    aobj ->InsertionSort(iLength);

    cout << "Data after the sorting element \n";

    aobj->Display();

    delete aobj;
    
    return 0;
}