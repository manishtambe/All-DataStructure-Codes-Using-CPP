#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
    int Data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;


class Queue{
    private: PNODE first;
    private: int iSize;

    public: Queue()
    {
        first = NULL;
        iSize = 0;
    }

    public: void Display()
    {
        PNODE temp = first;
        while(temp != NULL)
        {
            cout<<"|"<<temp -> Data<<"|->";
            temp = temp -> next;
        }
        cout<<"\n";
    }

    public: int Count()
    {
        return iSize;
    }

    public: void Enqueue(int iNo)
    {
        PNODE temp = first;
        PNODE newn = new NODE;
        newn -> Data = iNo;
        newn -> next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newn;
        }
        iSize++;
    }

    public: int Dequeue()
    {
        int iRet = 0;
        PNODE temp = first;

        if(temp == NULL)
        {
            cout<<"Queue is empty !\n";
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
    Queue qobj;
    int iRet = 0;
    int iChoice = 1;
    int iValue = 0;
    int iNo = 0;

    while(iChoice != 0)
    {
        cout<<"|-----------------------------------|\n";
        cout<<"|---------Queue Applicaton----------|\n";
        cout<<"|-----------------------------------|\n";
        cout<<" 1 : Enqueue element in the queue\n";
        cout<<" 2 : Dequeue element from the queue\n";
        cout<<" 3 : Display elements from the queue\n";
        cout<<" 4 : Count elements from the queue\n";
        cout<<" 5 : Exit from the application\n";
        cout<<"|----------------------------------|\n";
        cout<<"Enter the choice: - \n";
        cin>>iValue;
        switch(iValue)
        {
            case 1:
                cout<<"Enter the element that you want to push in the queue = \n";
                cin>>iNo;
                qobj.Enqueue(iNo);
                cout<<"Element has been added successfully !\n";
            break;
                
            case 2:
                iRet = qobj.Dequeue();
                cout<<"The deleted element is = "<<iRet<<"\n";
            break;

            case 3:
                cout<<"The elements present in the queue are : -\n";
                qobj.Display();
            break;

            case 4:
                iRet = qobj.Count();
                cout<<"The total elements present in the queue are = "<<iRet<<"\n";
            break;
            
            case 5:
                cout<<"Thank you for using an queue application\n";
                iChoice = 0;
            break;

            default:
                cout<<"Invalid choice has been encountered !\n";
            break;
        }
    }
    return 0;
}