#include<iostream>

using namespace std;

int Strcmp(char Arr[50], char Brr[50])
{
    int i = 1;
    int iCnt = 0;

    if(Arr == NULL)
    {
        return i;
    }
    else if(Brr == NULL)
    {
        return i;
    }
    else
    {
        while(Arr[iCnt] != '\0')
        {
            if(Arr[iCnt] != Brr[iCnt])
            {
                i = 1;
                break;
            }
            else
            {
                i = 0;
            }
            iCnt++;
        }
    }
    return i;
}

int main()
{
    char arr[50];
    char brr[50];
    int iRet = 0;

    cout<<"Enter The First String = \n";
    cin.getline(arr,50);
    cout<<"Enter The Second String = \n";
    cin.getline(brr,50);

    iRet = Strcmp(arr,brr);

    if(iRet == 0)
    {
        cout<<"Entered strings are equal";
    }   
    else
    {
        cout<<"Entered strings are not equal";
    }
}