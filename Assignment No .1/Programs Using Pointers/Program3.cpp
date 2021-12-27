#include<iostream>

using namespace std;

void Strcat(char *Arr, char *Brr)
{
    int iCnt = 0;

    if(Arr == NULL)
    {
        return;
    }
    else if(Brr == NULL)
    {
        return;
    }
    else
    {
        while(*Arr != '\0')
        {
            Arr++;
        }

        while(*Brr != '\0')
        {
            *Arr = *Brr;
            Arr++;
            Brr++;
        }
        *Arr = '\0';
    }
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

    Strcat(arr,brr);

    cout<<"The New String After An Concatination = "<<arr;
    
    return 0;
}