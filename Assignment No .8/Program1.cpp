#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
    int Data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class Stack{
    private: PNODE first;
    private: int iSize;

    public: Stack()
    {
        first = NULL;
        iSize = 0;
    }

    public: void Display()
    {
        PNODE temp = first;
        cout<<"\n";
        while(temp != NULL)
        {
            cout<<"|"<<temp->Data<<"|"<<"\n";
            temp = temp -> next;
        }
        cout<<"\n";
    }

    public: int Count()
    {
        return iSize;
    }

    public: void Push(int iNo)
    {
        PNODE newn = new NODE();
        newn -> Data = iNo;
        newn -> next = NULL;

        if(first == NULL) 
        {
            first = newn;
        }
        else 
        {
            newn -> next = first;
            first = newn;
        }
        iSize++;
    }

    public: int Pop()
    {
        PNODE temp = NULL;
        temp = first;
        int iRet = 0;

        if(first == NULL)
        {
            cout<<"Stack is empty\n";
        }
        else if(first -> next == NULL) 
        {
            iRet = first -> Data;
            delete(first);
            first = NULL;
        }
        else
        {
            iRet = first -> Data;
            first = first -> next;
            delete(temp);
        }
        iSize--;
        return iRet;
    }
};

int main()
{
    Stack sobj;
    int iRet = 0;
    int iChoice = 1;
    int iValue = 0;
    int iNo = 0;

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
                cout<<"Element has been pushed successfully !\n";
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