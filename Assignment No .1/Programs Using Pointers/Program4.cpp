#include<iostream>

using namespace std;

void Strrev(char *Arr)
{
    
    char *End = NULL;
    char temp = '\0';
    
    End = Arr;

    if(Arr == NULL)
    {
        return;
    }
    else
    {
        
        while(*End != '\0')
        {
            End++; 
        }

        End--;
    
        while(Arr < End)
        {
            temp = *Arr;
            *Arr = *End;
            *End = temp;

            Arr++;
            End--;
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