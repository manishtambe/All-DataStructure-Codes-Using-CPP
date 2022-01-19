#include<iostream>
#include<stdlib.h>

using namespace std;

class Stack{
    private: int *arr;
    private: int Size;
    private: int iCnt;
    private: int head;

    public: Stack(int iSize)
    {
        Size = iSize;
        arr = new int[Size];
        iCnt = 0;
        head = -1;
    }

    public: void Display()
    {
        int i = 0;

        for(i = head; i >= 0; i--)
        {
            cout<<"|"<<arr[i]<<"|\n";
        }
    }

    public: int Count()
    {
        return iCnt;
    }

    public: void Push(int iNo)
    {
        if(head == Size - 1)
        {
            cout<<"Stack is overflow !\n";
        }
        else
        {
            head = head + 1;
            arr[head] = iNo;
            iCnt++;
        }
    } 

    public: int Pop()
    {
        int iElement = 0;

        if(head == -1)
        {
            cout<<"Stack is underflow !\n";
        }
        else
        {
            iElement = arr[head];
            head = head - 1;
            iCnt--;
        }

        return iElement;
    }
};

int main()
{
    int iRet = 0;
    int iChoice = 1;
    int iValue = 0;
    int iNo = 0;

    cout<<"Enter the size of the stack = \n";
    cin>>iNo;

    Stack sobj(iNo);
    
    while(iChoice != 0)
    {
        cout<<"|-----------------------------------|\n";
        cout<<"|---------Stack Applicaton----------|\n";
        cout<<"|-----------------------------------|\n";
        cout<<" 1 : Push element in the stack\n";
        cout<<" 2 : Pop element from the stack\n";
        cout<<" 3 : Display elements from the stack\n";
        cout<<" 4 : Count elements from the stack\n";
        cout<<" 5 : Exit from the application\n";
        cout<<"-----------------------------------\n";
        cout<<"Enter the choice: - \n";
        cin>>iValue;
        switch(iValue)
        {
            case 1:
                cout<<"Enter the element that you want to push in the stack = \n";
                cin>>iNo;
                sobj.Push(iNo);
            break;
                
            case 2:
                iRet = sobj.Pop();
                cout<<"The poped element is = "<<iRet<<"\n";
            break;

            case 3:
                cout<<"The elements present in the stack are : -\n";
                sobj.Display();
            break;

            case 4:
                iRet = sobj.Count();
                cout<<"The total elements present in the stack are = "<<iRet<<"\n";
            break;
            
            case 5:
                cout<<"Thank you for using an stack application\n";
                iChoice = 0;
            break;

            default:
                cout<<"Invalid choice has been encountered !\n";
            break;
        }
    }
    return 0;
}