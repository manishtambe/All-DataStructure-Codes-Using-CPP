#include<iostream>
#include<string>

using namespace std;

struct node{
    int iId;
    string sName;
    long long int iMob;
    double dSalary;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class Employee{
    private: PNODE first;
    private: int iSize;

    public: Employee()
    {
        first = NULL;
        iSize = 0;
    }

    public: int Display()
    {
        PNODE temp = first;
        int flag = -1;
        if(temp != NULL)
        {
            while(temp != NULL)
            {
                cout<<"\n-----------Employee Details----------\n";
                cout<<"Employee Id: - "<<temp -> iId<<"\n";
                cout<<"Employee Mobile No: - "<<temp -> iMob<<"\n";
                cout<<"Employee Name: - "<<temp -> sName<<"\n";
                cout<<"Employee Salary: -"<<temp -> dSalary<<"\n";
                cout<<"---------------------------------------\n\n";
                temp = temp -> next;
            }
            flag = 0;
        }
        return flag;
    }

    public: int Count()
    {
        return iSize;
    }

    public: NODE* SearchRecord(int iId)
    {
        int flag = -1;
        PNODE temp = first;

        if(iSize == 0)
        {
            return NULL;
        }
        else
        {
            while(temp != NULL)
            {
                if(temp -> iId == iId)
                {
                    flag = 1;
                    break;
                }
                temp = temp -> next;
            }
        }

        if(flag == -1)
        {
            return NULL;
        }
        else
        {
            return temp;
        }
    }

    public: int InsertFirst(int iId, long long int iMob, string sName, double dSalary)
    {
        int flag = -1;
        PNODE newn = new NODE;
        newn -> next = NULL;
        newn -> iId = iId;
        newn -> iMob = iMob;
        newn -> sName = sName;
        newn -> dSalary = dSalary;

        PNODE temp = SearchRecord(iId);

        if(temp == NULL)
        {
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
            flag = 0;
        }
        return flag;
    }

    public: int InsertLast(int iId, long long int iMob, string sName, double dSalary)
    {
        int flag = -1;
        PNODE newn = new NODE;
        newn -> next = NULL;
        newn -> iId = iId;
        newn -> iMob = iMob;
        newn -> sName = sName;
        newn -> dSalary = dSalary;

        PNODE temp = SearchRecord(iId);

        if(temp == NULL)
        {
            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                PNODE temp = first;
                
                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }
                
                temp -> next = newn;
            }
            iSize++;
            flag = 0;
        }
        return flag;
    }

    public: int DeleteFirst()
    {
        int flag = -1;

        if(first == NULL)
        {
            return flag;
        }
        else if(first -> next == NULL)
        {
            delete(first);
            first = NULL;
            flag = 0;
        }
        else 
        {
            PNODE temp = first;
            first = first -> next;
            delete(temp);
            flag = 0;
        }
        iSize--;
        return flag;
    }

    public: int DeleteLast()
    {
        int flag = -1;

        if(first == NULL)
        {
            return flag;
        }
        else if(first -> next == NULL)
        {
            delete(first);
            first = NULL;
            flag = 0;
        }
        else
        {
            PNODE temp = first;

            while(temp -> next -> next != NULL)
            {
                temp = temp -> next;
            }

            delete(temp -> next);
            temp -> next = NULL;
            flag = 0;
        }
        iSize--;
        return flag;
    }

    public: int InsertAtPos(int iPos,int iId, long long int iMob, string sName, double dSalary)
    {
        int flag = -1;
        PNODE temp = SearchRecord(iId);

        if((iPos < 1) || (iPos > (iSize + 1)))
        {
            return flag;
        }
        else if(iPos == 1)
        {
            flag = InsertFirst(iId, iMob, sName, dSalary);
        }
        else if(iPos == (iSize + 1))
        {
            flag = InsertLast(iId, iMob, sName, dSalary);
        }
        else
        {
            if(temp == NULL)
            {
                PNODE temp = first;
                int i = 0;
                PNODE newn = new NODE;
                newn -> next = NULL;
                newn -> iId = iId;
                newn -> iMob = iMob;
                newn -> sName = sName;
                newn -> dSalary = dSalary; 
            
                for(i = 1; i < iPos - 1; i++)
                {
                    temp = temp -> next;
                }

                newn -> next = temp-> next;
                temp -> next = newn;

                iSize++;
                flag = 0;
            }
        }
        return flag;
    }
    public: int DeleteAtPos(int iPos)
    {
        int flag = -1;

        if((iPos < 1)||(iPos > iSize))
        {
            return flag;
        }
        else if(iPos == 1)
        {
            flag = DeleteFirst();
        }
        else if(iPos == iSize)
        {
            flag = DeleteLast();
        }
        else
        {
            PNODE temp = first;
            PNODE Target = NULL;
            int i = 0;

            for(i = 1; i < iPos-1; i++)
            {
                temp = temp -> next;
            }

            Target = temp -> next;
            temp -> next = Target -> next;
            delete(Target);

            iSize--;
            flag = 0;
        }
        return flag;
    }

    public: int ModifyRecord(int iId, long long int iMob, string sName, double dSalary)
    {
        int flag = -1;
        PNODE temp = SearchRecord(iId);
        
        if(temp != NULL)
        {
            temp -> iMob = iMob;
            temp -> sName = sName;
            temp -> dSalary = dSalary;
            flag = 0; 
        }

        return flag;
    }
};


int main()
{
    Employee emp;
    PNODE pRet = NULL;
    int iRet = 0;
    int iChoice = 1;
    int iValue = 0;
    int iElement = 0;
    char Name[20];
    int id = 0;
    int iPos = 0;
    long long int imob = 0L;
    double Salary = 0.0;

    while(iChoice != 0)
    {
        cout<<"|------Employee Management Systems-----|\n";
        cout<<" 1 : Insert Record at first position \n";
        cout<<" 2 : Insert Record at last position \n";
        cout<<" 3 : Insert Record at Desire position \n";
        cout<<" 4 : Delete Record From first position \n";
        cout<<" 5 : Delete Record From Last position \n";
        cout<<" 6 : Delete Record From Desire position \n";
        cout<<" 7 : Display All Records\n";
        cout<<" 8 : Display Perticular Record\n";
        cout<<" 9 : Count Records\n";
        cout<<"10 : Search Record\n";
        cout<<"11 : Modify Records\n";
        cout<<"12 : Exit From The Application\n";
        cout<<"|--------------------------------------|\n";
        cout<<"Enter The Choice = \n";
        cin>>iValue;
        
        switch (iValue)
        {
        case 1:
            cout<<"Enter the id of the employee: -\n";
            cin>>id;
            if(id <= 0)
            {
                cout<<"User id should be greater than '0'\n";
                break;
            }
            else
            {
                cout<<"Enter the mobile no of the employee: -\n";
                cin>>imob;
                fflush(stdin);
                cout<<"Enter the name of the employee: -\n";
                cin.getline(Name,20);
                cout<<"Enter the salary of the employee: -\n";
                cin>>Salary;
                iRet = emp.InsertFirst(id,imob,Name,Salary);
                if(iRet == -1)
                {
                    cout<<"Duplicate id found please enter different employee id\n";
                    break;
                }
                else if(iRet == 0)
                {
                    cout<<"Record inserted successfully !\n";
                    break;
                }
            }
            break;
        case 2:
            cout<<"Enter the id of the employee: -\n";
            cin>>id;
            if(id <= 0)
            {
                cout<<"User id should be greater than '0'\n";
                break;
            }
            else
            {
                cout<<"Enter the mobile no of the employee: -\n";
                cin>>imob;
                fflush(stdin);
                cout<<"Enter the name of the employee: -\n";
                cin.getline(Name,20);
                cout<<"Enter the salary of the employee: -\n";
                cin>>Salary;
                iRet = emp.InsertLast(id,imob,Name,Salary);
                if(iRet == -1)
                {
                    cout<<"Duplicate id found please enter different employee id\n";
                    break;
                }
                else if(iRet == 0)
                {
                    cout<<"Record inserted successfully !\n";
                    break;
                }
            }
            break;
        case 3:
            cout<<"Enter the position on which you want to enter the record = \n";
            cin>>iPos;
            cout<<"Enter the id of the employee: -\n";
            cin>>id;
            if(id <= 0)
            {
                cout<<"User id should be greater than '0'\n";
                break;
            }
            else
            {
                cout<<"Enter the mobile no of the employee: -\n";
                cin>>imob;
                fflush(stdin);
                cout<<"Enter the name of the employee: -\n";
                cin.getline(Name,20);
                cout<<"Enter the salary of the employee: -\n";
                cin>>Salary;
                iRet = emp.InsertAtPos(iPos,id,imob,Name,Salary);
                if(iRet == -1)
                {
                    cout<<"Duplicate id found please enter different employee id\n";
                    break;
                }
                else if(iRet == 0)
                {
                    cout<<"Record inserted successfully !\n";
                    break;
                }
            }
            break;
        case 4:
            iRet = emp.DeleteFirst();

            if(iRet == -1)
            {
                cout<<"Error while deleting an record\n";
            }
            else if(iRet == 0)
            {
                cout<<"Record deleted successfully !\n";
            }
            break;
        case 5:
            iRet = emp.DeleteLast();

            if(iRet == -1)
            {
                cout<<"Error while deleting an record\n";
            }
            else if(iRet == 0)
            {
                cout<<"Record deleted successfully !\n";
            }
            break;
        case 6:
            cout<<"Enter the record position to delete record =\n";
            cin>>iElement;
            iRet = emp.DeleteAtPos(iElement);

            if(iRet == -1)
            {
                cout<<"Error while deleting an record\n";
            }
            else if(iRet == 0)
            {
                cout<<"Record deleted successfully !\n";
            }
            break;
        case 7:
            cout<<"All the records present in the database are : - \n";
            iRet = emp.Display();
            if(iRet == -1)
            {
                cout<<"Records not found to display !\n";
            }
            break;
        case 8:
            cout<<"Enter the employee id to display its record =\n";
            cin>>iElement;

            pRet = emp.SearchRecord(iElement);

            if(pRet != NULL)
            {
                cout<<"\n-----------Employee Details----------\n";
                cout<<"Employee Id: - "<<pRet -> iId<<"\n";
                cout<<"Employee Mobile No: - "<<pRet -> iMob<<"\n";
                cout<<"Employee Name: - "<<pRet -> sName<<"\n";
                cout<<"Employee Salary: -"<<pRet -> dSalary<<"\n";
                cout<<"---------------------------------------\n\n";
            }
            else
            {
                 cout<<"The record is not present in the database\n";
            }
            break;
        case 9:
            iRet = emp.Count();
            cout<<"The total number of records present in the database are = "<<iRet<<"\n";
            break;
        case 10:
            cout<<"Enter the employee id to check whether its record present in the database =\n";
            cin>>iElement;

            pRet = emp.SearchRecord(iElement);

            if(pRet != NULL)
            {
                cout<<"The record is present in the database\n";
            }
            else
            {
                 cout<<"The record is not present in the database\n";
            }
            break;
        case 11:
            cout<<"Enter the id of the employee of which you want to update details: -\n";
            cin>>id;
            if(id <= 0)
            {
                cout<<"User id should be greater than '0'\n";
                break;
            }
            else
            {
                cout<<"Enter the new mobile no of the employee to update: -\n";
                cin>>imob;
                fflush(stdin);
                cout<<"Enter the new name of the employee to update: -\n";
                cin.getline(Name,20);
                cout<<"Enter the new salary of the employee to update: -\n";
                cin>>Salary;
                iRet = emp.ModifyRecord(id,imob,Name,Salary);
                if(iRet == -1)
                {
                    cout<<"Unable to modify record\n";
                    break;
                }
                else if(iRet == 0)
                {
                    cout<<"Record Modified successfully !\n";
                    break;
                }
            }
            break;
        case 12:
            cout<<"Thank You ! for using our application\n";
            iChoice = 0;
            break;
        default:
            cout<<"Undefined choice has been entered !\n";
            break;
        }
    }
    return 0;
}


