#include<iostream>

using namespace std;

void Strcpy(char *Arr, char *Brr)
{
    int iCnt = 0;

    if(Arr == NULL)
    {
        return;
    }
    else
    {
        while(*Arr != '\0')
        {
           *Brr = *Arr;
           Arr++;
           Brr++;
        }
        *Brr = '\0';
    }
}

int main()
{
    char arr[50];
    char brr[50];
    int iRet = 0;

    cout<<"Enter The First String To Create Copy Of It In Second= \n";
    cin.getline(arr,50);
   
    Strcpy(arr,brr);

    cout<<"The Copy Of The Entered String is = "<<brr;
    
    return 0;
}