#include<iostream>
#include<stdlib.h>

using namespace std;

class Queue
{
    private: int rear;
    private: int front;
    private: int iCnt;
    private: int iSize;
    private: int *arr;

    public: Queue(int Size)
    {
        iSize = Size;
        arr = new int[iSize];
        rear = front = 0;
        iCnt = 0;
    }

    public: int Count()
    {
        return iCnt;
    }

    public: void Display()
    {
        int i = 0;

        for(i = front; i < rear; i++)
        {
            cout<<"|"<<arr[i]<<"|"<<"\t";
        }

        cout<<"\n";
    }

    public: void Enqueue(int iNo)
    {
        if(rear == iSize)
        {
            cout<<"Queue is full !\n";
            return;
        }
        else 
        {
            arr[rear] = iNo;
            rear++;
            iCnt++;
        }
    }

    public: int Dequeue()
    {
        int iElement = 0;

        if(rear == front)
        {
            cout<<"Queue is empty !\n";
            return iElement;
        }
        else
        {
            iElement = arr[0];
            for(int i = 0; i < rear - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            rear--;
            iCnt--;
        }

        return iElement;
    }

};

int main()
{
    Queue qobj(4);
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