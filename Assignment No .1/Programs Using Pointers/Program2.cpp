#include<iostream>

using namespace std;

int Strcmp(char *Arr, char *Brr)
{
    int i = 1;

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
        while(*Arr != '\0')
        {
            if(*Arr != *Brr)
            {
                i = 1;
                break;
            }
            else
            {
                i = 0;
            }
            Arr++;
            Brr++;
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