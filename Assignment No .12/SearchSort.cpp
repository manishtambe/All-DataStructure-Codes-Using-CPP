#include<iostream>

using namespace std;

class SearchSort{
    int *Arr;
    int iSize;
    int iCnt;
    public: SearchSort(int Size)
    {
        iSize = Size;
        Arr = new int(iSize);
        iCnt = 0;
    }

    public: void InsertElements(int iNo)
    {
        if(iCnt >= iSize)
        {
            cout<<"Array is full !\n";
        }
        else
        {
            Arr[iCnt] = iNo;
            iCnt++;
        }
    }

    public: int BinarySearch(int key)
    {
        int ikey, i, j;
        i = 0;
        j = iSize - 1;
        
        ikey = (i + j) / 2;
        
        while((Arr[ikey] != key)&& (i <= j))
        {
            if(key > Arr[ikey])
            {
                i = ikey + 1;
            }
            else
            {
                
                j = ikey - 1; 
            }
            ikey = (i + j) / 2;
        }
        if(i <= j)
        {
            return ikey;
        }
        return -1;
    }

    public: void BubbleSort()
    {
        int i = 0;
        int j = 1;
        int temp = 0;
        for(i = 0; i < iSize - 1; i++)
        {
            cout<<"The "<<i + 1<<" Pass = ";
            for(j = 0; j < iSize; j++)
            {
                if(Arr[j] > Arr[j+1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;
                }
                cout<<Arr[j]<<"\t";
            }
            cout<<endl;
        }
    }

    public: void DisplayArray()
    {
        cout<<"Array Elements Are: -\n";
        for(int i = 0; i < iSize; i++)
        {
            cout<<Arr[i]<<"\t";
        }
        cout<<"\n";
    }
};

int main()
{
    int iSize = 0;
    int iNo = 0;
    int iValue = 1;
    int iValue1 = 1;
    int iChoice = 0;
    int iChoice1 = 0;
    int iRet = -1;

    cout<<"How many number of elements do you want to enter: -";
    cin>>iSize;
    SearchSort sobj = SearchSort(iSize);
    
    while(iValue != 0)
    {
        cout<<"-------------------------"<<endl;
        cout<<"1. Insert Elements"<<endl;
        cout<<"2. Exit From Application"<<endl;
        cout<<"-------------------------"<<endl;

        cout<<"Enter the choice: -";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
            {
                for(int i = 0; i < iSize; i++)
                {
                    cout<<"Enter the "<<i + 1<<" element = ";
                    cin>>iNo;
                    sobj.InsertElements(iNo);
                }
                    while(iValue1 != 0)
                    {
                        cout<<"-------------------------"<<endl;
                        cout<<"1. Binary Search"<<endl;
                        cout<<"2. Bubble Sort"<<endl;
                        cout<<"3. Display Array"<<endl;
                        cout<<"4. Exit From Application"<<endl;
                        cout<<"-------------------------"<<endl;

                        cout<<"Enter the choice: -";
                        cin>>iChoice1;

                        switch(iChoice1)
                        {
                            case 1:
                            {
                                cout<<"Enter the element to check whether it is present in array or not = ";
                                cin>>iNo;

                                iRet = sobj.BinarySearch(iNo);

                                if(iRet != -1)
                                {
                                    cout<<"The element is found at position: - "<<iRet<<endl;
                                }
                                else
                                {
                                    cout<<"Element Not Found !\n";
                                }
                            }
                            break;
                            case 2:
                            {
                                cout<<"The Sorting Of the Array As Per Pass: -"<<endl;
                                sobj.BubbleSort();
                            }
                            break;
                            case 3:
                            {
                                sobj.DisplayArray();
                            }
                            break;
                            case 4:
                            {
                                iValue1 = 0;
                                cout<<"Thank You ! For Using Our Application !"<<endl;
                            }
                            break;
                            default:
                            {
                                cout<<"Invalid Choice Has Been Entered !";
                            }
                            break;
                        }
                    }
            }
            break;
            case 2:
            {
                iValue = 0;
                cout<<"Thank You ! For Using Application\n";  
            }
            break;
            default:
            {
                cout<<"Undefined Choice Has Been Entered\n";
            }   
            break;
        }
    }
    return 0;
}