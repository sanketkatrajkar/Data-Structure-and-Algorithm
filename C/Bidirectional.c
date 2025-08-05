#include<stdio.h>
#include<stdbool.h>

void Accept(int *Arr, int iSize)
{
    int i = 0;
    printf("Enter the element of array :\n");

    for(i = 0; i < iSize; i++)
    {
        scanf("%d ",&Arr[i]);
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

bool Bidirectional(int *Arr, int iSize, int no)
{
    int iStart = 0, iEnd = 0;
    bool bFlag = false;

    for(iStart = 0, iEnd = iSize; iStart < iEnd;iStart++, iEnd--)
    {
        if(Arr[iStart] == no || Arr[iEnd] == no)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
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

    bRet = Bidirectional(Arr,iSize,5);
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