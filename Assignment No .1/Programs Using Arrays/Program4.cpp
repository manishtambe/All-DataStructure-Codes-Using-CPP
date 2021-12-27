#include<iostream>

using namespace std;

void Strrev(char Arr[50])
{
    
    int iStart =0;
    char temp = '\0';
    int iEnd = 0;

    if(Arr == NULL)
    {
        return;
    }
    else
    {
        
        while(Arr[iEnd] != '\0')
        {
            iEnd++;
        }

        iEnd--;
    
        while(iStart < iEnd)
        {
            temp = Arr[iStart];
            Arr[iStart] = Arr[iEnd];
            Arr[iEnd] = temp;

            iStart++;
            iEnd--;
        }
    }
}

int main()
{
    char arr[50];
    char brr[50];
    int iRet = 0;

    cout<<"Enter The First String = \n";
    cin.getline(arr,50);
   
    Strrev(arr);

    cout<<"The New String After An Concatenation = "<<arr;
    
    return 0;
}