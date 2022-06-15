#include<iostream>
# define max 5
using namespace std;

class CirculerQueue{
    int iSize;
    int front;
    int rear;
    int *arr;

    public: CirculerQueue(int iSize1)
    {
        iSize = iSize1;
        front = -1;
        rear = -1;
        arr = new int(iSize);
    }

    public: void Enqueue(int iNo)
    {
        cout<<iNo;
        if((front == -1) && (rear == -1))
        {
            front = 0;
            rear = 0;
            arr[rear] = iNo;
        }
        else if((rear + 1) % iSize == front)
        {
            cout<<"Order Acceptance Status - Full\n";
        }
        else
        {
            rear = (rear + 1) % iSize;
            arr[rear] = iNo;
        }
    }

    public: void Dequeue()
    {
        if((front == -1)&&(rear == -1))
        {
            cout<<"No order to place !\n";
        }
        else if(front == rear)
        {
            cout<<"The Placed Order is: -"<<arr[front]<<endl;
            front = -1;
            rear = -1;
        }
        else
        {
            cout<<"The Placed Order is: -"<<arr[front]<<endl;
            front = (front + 1) % iSize;
        }
    }

    public: void Display()
    {
        int i = front;
        if((front == -1) && (rear == -1))
        {
            cout<<"Nothing to show ! No Orders To Show !"<<endl;
        }
        else
        {
            while(i != rear)
            {
                cout<<"|"<<arr[i]<<"| -";
                i = (i + 1) % iSize;
            }
            cout<<"|"<<arr[i]<<"|\n";
        }
    }
};

int main()
{
    int iSize = 0;
    int iNo = 0;
    int iChoice = 0;
    int iValue = 1;
    cout<<"Enter the total number of orders: -";
    cin>>iSize;
    CirculerQueue cobj = CirculerQueue(iSize);

    while(iValue != 0)
    {
        cout<<"-------------------"<<endl;
        cout<<"1. Accept Order"<<endl;
        cout<<"2. Place Order"<<endl;
        cout<<"3. Display Orders"<<endl;
        cout<<"4. Exit Application"<<endl;
        cout<<"-------------------"<<endl;

        cout<<"Enter the choice: -";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
            {
                cout<<"Enter the order no: -";
                cin>> iNo;
                cout<<iNo;
                cobj.Enqueue(iNo);
            }
            break;

            case 2:
            {
                cobj.Dequeue();
            }
            break;

            case 3:
            {
                cobj.Display();
            }
            break;

            case 4:
            {
		cout<<"Thank You ! Visit Again !\n;
                iValue = 0;
            }
            break;

            default:
            {
                cout<<"Invalid Choice Has Been Entered !"<<endl;
            }
            break;
        }
    }
    return 0;
}
