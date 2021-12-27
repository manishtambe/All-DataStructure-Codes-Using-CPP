#include<iostream>

using namespace std;

void Strcat(char Arr[50], char Brr[50])
{
    int iCnt = 0;
    int i = 0;
    int j = 0;

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
        while(Arr[i] != '\0')
        {
            i++;
        }

        while(Brr[j] != '\0')
        {
            Arr[i] = Brr[j];
            i++;
            j++;
        }
        Arr[i] = '\0';
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