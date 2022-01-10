#include<iostream>
#include<string>

using namespace std;

struct Emp{
    int iId;
    long long int iMob;
    string sName;
    double dSalary;
};

typedef struct Emp Em;

class Employee{
    private: Em* emp; 
    private: int iCnt;
    private: int isize;
    public: Employee(int size)
    {
        isize = size;
        emp = new Em[isize];
        iCnt = 0;
    }

    public: ~Employee()
    {
        delete[] emp;
    }

    public: void SortRecord(int iCnt)
    {
        int i = 0;
        int j = 0;
        string sName = "";
        int iId = 0;
        long long int iMob = 0L;
        double dSalary = 0.0;

        if(iCnt != 0)
        {
            for(i = 0; i < iCnt-1 ; i++)
            {
                for(j = 0; j < iCnt-i-1 ; j++)
                {
                    if(emp[j].iId > emp[j+1].iId )
                    {
                        iId = emp[j+1].iId;
                        sName = emp[j+1].sName;
                        iMob = emp[j+1].iMob;
                        dSalary = emp[j+1].dSalary;

                        emp[j+1].iId = emp[j].iId;
                        emp[j+1].sName = emp[j].sName;
                        emp[j+1].iMob = emp[j].iMob;
                        emp[j+1].dSalary = emp[j].dSalary;

                        emp[j].iId = iId;
                        emp[j].sName = sName;
                        emp[j].iMob = iMob;
                        emp[j].dSalary = dSalary;
                    }
                }
            }
        }
        else
        {
            return;
        }
    }

    public: int SearchRecord(int iElement)
    {
        int iLow = 0;
        int iHigh = 0;
        int iMid = 0;
        int iFlag = -1;

        iHigh = iCnt;
        if(iCnt == 0)
        {
            return iFlag;
        }
        else
        {
            SortRecord(iCnt);

            while(iLow <= iHigh)
            {
                iMid = ((iLow + iHigh) / 2);

                if(emp[iMid].iId == iElement)
                {
                    iFlag = iMid;
                    cout<<"iFlag Value = "<<iFlag<<"\n";
                    break;
                }
                else if(iElement > emp[iMid].iId)
                {
                    iLow = iMid + 1;
                }
                else if(iElement < emp[iMid].iId)
                {
                    iHigh = iMid - 1;
                }
            }
        }
        return iFlag;
    }

    public: int AddRecord(int id,long long int imob,string Name,double Salary, int iSize)
    {
        int  i = 0;
        int iRet = 0;

        iRet = SearchRecord(id);

        if(iSize > isize)
        {
            return 1;
        }
        else
        {
            if(iRet == -1)
            {
                emp[iCnt].iId = id;
                emp[iCnt].iMob = imob;
                emp[iCnt].sName = Name;
                emp[iCnt].dSalary = Salary; 
                iCnt++;
            }
            else
            {
                return 0;
            }
            iRet = -1;
        }
    }

    public: int DeleteRecord(int iElement)
    {
        int iRet = 0;
        int i = 0;

        iRet = SearchRecord(iElement);

        if(iRet != -1)
        {
            for(i = iRet; i < iCnt; i++)
            {
                emp[i].iId = emp[i+1].iId;
                emp[i].iMob = emp[i+1].iMob;
                emp[i].sName = emp[i+1].sName;
                emp[i].dSalary = emp[i+1].dSalary; 
            }
            iCnt--;
            iRet = -2;
        }
        else
        {
            iRet = -1;
        }

        return iRet;
    }

    public: void Display()
    {
        int j = 0;
        if(iCnt == 0)
        {
            return;
        }
        else
        {
            SortRecord(iCnt);
            for(j = 0; j < iCnt; j++)
            {
                cout<<"\n-----------Employee Details----------\n";
                cout<<"Employee Id: - "<<emp[j].iId<<"\n";
                cout<<"Employee Mobile No: - "<<emp[j].iMob<<"\n";
                cout<<"Employee Name: - "<<emp[j].sName<<"\n";
                cout<<"Employee Salary: -"<<emp[j].dSalary<<"\n";
                cout<<"---------------------------------------\n\n";
            }
        }
    }
};

int main()
{
    int id = 0;
    int iSize = 0;
    long long int imob = 0L;
    int i = 0;
    char Name[20];
    double Salary = 0.0;
    int iChoice = 1;
    int iValue = 0;
    int iElement = 0;
    int iRet = 0;
    Employee eobj(100);

    while(iChoice != 0)
    {
        cout<<"---------------------------------------\n";
        cout<<"|Welcome To Employee Management System|\n";
        cout<<"---------------------------------------\n";
        cout<<"      1. Add employee record\n";
        cout<<"      2. Delete employee record\n";
        cout<<"      3. Search employee record\n";
        cout<<"      4. Display employee record\n";
        cout<<"      5. Exit from application\n";
        cout<<"---------------------------------------\n";
        cout<<"Enter the choice = \n";
        cin>>iChoice;
        switch(iChoice)
        {
            case 1:
                cout<<"How many number of records do you want to enter = \n";
                cin>>iSize;
                for(i = 0; i < iSize; i++)
                {
                    cout<<"Enter the id of the "<<i + 1<<" employee: -\n";
                    cin>>id;
                    if(id <= 0)
                    {
                        cout<<"User id should be greater than '0'\n";
                        break;
                    }
                    else
                    {
                        cout<<"Enter the mobile no of the "<<i + 1<<" employee: -\n";
                        cin>>imob;
                        fflush(stdin);
                        cout<<"Enter the name of the "<<i + 1<<" employee: -\n";
                        cin.getline(Name,20);
                        cout<<"Enter the salary of the "<<i + 1<<" employee: -\n";
                        cin>>Salary;
                        iRet = eobj.AddRecord(id,imob,Name,Salary,iSize);
                        if(iRet == 0)
                        {
                            cout<<"Duplicate id Found Please Entered Different Employee id\n";
                            break;
                        }
                        else if(iRet == 1)
                        {
                            cout<<"Database is full !\n";
                            break;
                        }
                        else
                        {
                            cout<<"Record inserted successfully !\n";
                        }
                    }
                }
            break;   
            case 2:
                cout<<"Enter the element that you want to delete From The database = \n";
                cin>>iElement;
                
                iRet = eobj.DeleteRecord(iElement);

                if(iRet == -2)
                {
                    cout<<"Record deleted successfully !\n";
                }
                else if(iRet == -1)
                {
                    cout<<"No record Ware Found To Delete\n";
                }
            break;
            case 3:

                cout<<"Enter the employee id to search the record = \n";
                cin>>iElement;

                iRet = eobj.SearchRecord(iElement);

                if(iRet != -1)
                {
                    cout<<"The entered record is present in the database -\n";
                }
                else
                {
                    cout<<"The entered record is not present in the database\n";
                }

            break;
            case 4:
                eobj.Display();
            break;
            case 5:
                cout<<"Thank you for using our application !\n";
                eobj.~Employee();
                iChoice = 0;
            break;
            default:
                cout<<"Invalid Choice !\n";
            break;
        }
    }
    return 0;
}