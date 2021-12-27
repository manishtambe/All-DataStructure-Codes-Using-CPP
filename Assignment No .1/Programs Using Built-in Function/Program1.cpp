#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char Arr[50];
    char Brr[50];
    int iValue = 1;
    int iAns = 0;
    int iChoice = 0;

    while (iValue != 0)
    {
        cout<<"-------------String Operations-------------\n";
        cout<<"1 : Find length of the string\n";
        cout<<"2 : Copy one string into another string\n";
        cout<<"3 : Concatinate two strings\n";
        cout<<"4 : Compare two strings\n";
        cout<<"5 : Reverse string\n";
        cout<<"6 : Exit from application\n";
        cout<<"-------------------------------------------\n";
        cout<<"Enter a choice = \n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter string to count length = \n";
                cin>>Arr;
                iAns = strlen(Arr);
                cout<<"The length of the string is = "<<iAns<<"\n";
                break;
            case 2:
                cout<<"Enter string to copy in another string = \n";
                cin>>Arr;
                strcpy(Brr,Arr);
                cout<<"The copy of the string is = "<<Brr<<"\n";
                break;
            case 3:
                cout<<"Enter first string = \n";
                cin>>Arr;
                cout<<"Enter second string = \n";
                cin>>Brr;
                strcat(Arr,Brr);
                cout<<"After concatination string is = "<<Arr<<"\n";
                break;
            case 4:
                cout<<"Enter first string = \n";
                cin>>Arr;
                cout<<"Enter second string = \n";
                cin>>Brr;
                iAns = strcmp(Arr,Brr);
                if(iAns == 0)
                {
                    cout<<"Entered strings are same\n";
                }
                else
                {
                    cout<<"Entered strings are not same\n";
                }
                break;
            case 5:
                cout<<"Enter string to arrange it in reverse order = \n";
                cin>>Arr;
                strrev(Arr);
                cout<<"After revercing string is = "<<Arr<<"\n";
                break;
            case 6:
                cout<<"Thank You For Using Application!";
                iValue = 0;
                break;
            default:
                cout<<"Incorrect choice has been entered";
                break;
        }
    }
    return 0;
}