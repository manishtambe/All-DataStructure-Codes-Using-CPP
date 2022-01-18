#include<iostream>

using namespace std;

struct POLY{
    int Coeff;
    int Expo;
};

typedef struct POLY p;

class Polynomial{
    private: p* p1;
    private: int iSize;
    
    public: Polynomial(int size)
    {
        p1 = new p[size];
        iSize = 0;
    }

    public: ~Polynomial()
    {
        delete[] p1;
    }

    public: void CreatePoly()
    {
        int i = 0;
        int iCoeff = 0;
        int iExpo = 0;

        cout<<"Enter the number of terms that are present in the polynomial = \n";
        cin>>iSize;

        for(i = 0; i < iSize; i++)
        {
            cout<<"Enter The Coefficient of the "<<i + 1<<" term = \n";
            cin>>iCoeff;
            cout<<"Enter The Exponent of the "<<i + 1<<" term = \n";
            cin>>iExpo;

            p1[i].Coeff = iCoeff;
            p1[i].Expo = iExpo;
        }
    }

    public: void DisplayPoly()
    {
        int i = 0;
        if(iSize != 0)
        {
            cout<<"The elements from the entered polynomial is = \n";
            for(i = 0; i < iSize; i++)
            {   
                cout<<"|";
                cout<<p1[i].Coeff;
                cout<<"|";
                cout<<p1[i].Expo;
                cout<<"|";
                cout<<"\t";
            }
            cout<<"\n";
        }
        else
        {
            cout<<"There is no polynomial to display\n";
        }
    }

    public: int Evaluate(int X)
    {
        int x = 0;
        int y = 0;
        int i = 0;
        int j = 0;
        int Add = 0;
        int iExpo = 0;
        int Coeff = 0;

        x = X;

        y = x;

        if(iSize != 0)
        {
            for(i = 0; i < iSize; i++)
            {
                iExpo = p1[i].Expo; 
                if(iExpo != 0)
                {
                    for(j = 0; j < iExpo - 1; j++)
                    {
                        x = x * y;
                    }
                    Coeff = (int)p1[i].Coeff;
                    Add = Add + x * Coeff;
                    x = y;
                }
                else if(iExpo == 0)
                {
                    Coeff = (int)p1[i].Coeff;
                    Add = Add + Coeff;
                }
            }
        }
        return Add;
    }
};

int main()
{   
    Polynomial pobj = Polynomial(100);
    int iValue = 0;
    int iChoice = 1;
    int iRet = 0;
    int x = 0;

    while(iChoice != 0)
    {
        cout<<"-------------------------\n";
        cout<<"1 : Create An Polynomial\n";
        cout<<"2 : Display An Entered Polynomial\n";
        cout<<"3 : Evaluate Polynomial With value of 'x'\n";
        cout<<"4 : Exit From Application\n";
        cout<<"-------------------------\n";
        cout<<"Enter An Choice = \n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                pobj.CreatePoly();
                break;
            case 2:
                pobj.DisplayPoly();
                break;
            case 3:
                cout<<"Enter the value of the 'x' for the evaluation = \n";
                cin>>x;
                iRet = pobj.Evaluate(x);
                cout<<"After the evaluating the polynomial the answer is = "<<iRet<<"\n";
                break;
            case 4:
                cout<<"Thank You For Using Application\n";
                iChoice = 0;
                break;
            default:
                cout<<"Invalid Choice Has Been Entered!\n";
                break;
        }

    }
    pobj.~Polynomial();
    return 0;
}