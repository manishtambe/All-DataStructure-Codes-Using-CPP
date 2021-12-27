#include<iostream>

using namespace std;

int Strlen(char Arr[50])
{
    int iCnt = 0;

    if(Arr == NULL)
    {
        return iCnt;
    }
    else
    {
       while(Arr[iCnt] != '\0')
       {
           cout<<Arr[iCnt];
           iCnt++;
       }
    }

    return iCnt;
}

int main()
{
    char arr[50];
    int iRet = 0;
    cout<<"Enter The String To Count The Length = \n";
    cin.getline(arr,50);
    
    iRet = Strlen(arr);
    
    cout<<"The length of the string is = "<<iRet;
}