#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Accept(int *Arr, int iSize)
{
    int i = 0;
    printf("Enter the element of array :\n");

    for(i = 0; i < iSize; i++)
    {
        scanf("%d",&Arr[i]);
    } 
}

void Display(int *Arr, int iSize)
{
    int i = 0;
    printf("Element of Array are :\n");

    for(i = 0; i < iSize; i++)
    {
        printf("%d \t",Arr[i]);
    } 
    printf("\n");
}

bool BinarySearch(int *Arr, int iSize, int no)
{
    int low = 0;
    int high = iSize - 1;
    bool bFlag = false;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(Arr[mid] == no)
        {
            return true;
        }
        else if(Arr[mid] < no)
        {
            low = mid + 1;
        }
        else if(Arr[mid] < no)
        {
            high = mid - 1;
        }
    }

    return false;
}

int main()
{
    int *Arr = NULL;
    int iSize = 0;
    bool bRet = false;

    printf("Enter the size of array :\n");
    scanf("%d",&iSize);

    Arr = (int *)malloc(iSize * sizeof(int));

    Accept(Arr,iSize);
       
    Display(Arr, iSize);

    bRet = BinarySearch(Arr,iSize,5);
    if(bRet == true)
    {
        printf("Element is Present\n");
    }
    else
    {
        printf("Element not Present\n");
    }

    free(Arr);
    
    return 0;
}