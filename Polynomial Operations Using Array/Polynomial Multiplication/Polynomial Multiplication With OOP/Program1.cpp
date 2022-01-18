#include<iostream>

using namespace std;

struct POLY{
    double Coeff;
    int Expo;
};

typedef struct POLY p;

class Polynomial{
    
    private: p* p1;
    private: p* p2;
    private: p* p3;
    private: p* p4;
    int iSize1;
    int iSize2;
    int i;
    int j;
    int k;
    int l;

    public: Polynomial(int size)
    {
        p1 = new p[size];
        p2 = new p[size];
        p3 = new p[size];
        p4 = new p[size];
        iSize1 = 0;
        iSize2 = 0;
        i = 0;
        j = 0;
        k = 0;
        l = 0;
    }

    public: ~Polynomial()
    {
        delete[] p1, p2, p3, p4;
    }

    public: void CreatePoly()
    {
        int iCoeff = 0;
        int iExpo = 0;

        cout<<"Enter the number of the terms present in the first polynomial =\n";
        cin>>iSize1;

        for(i = 0; i < iSize1; i++)
        {
            cout<<"Enter the coefficient of the "<<i + 1<<" term = \n";
            cin>>iCoeff;
            cout<<"Enter the exponetial of the "<<i + 1<<" term = \n";
            cin>>iExpo;

            p1[i].Coeff = iCoeff;
            p1[i].Expo = iExpo;

        }

        cout<<"Enter the number of the terms present in the second polynomial =\n";
        cin>>iSize2;

        for(i = 0; i < iSize2; i++)
        {
            cout<<"Enter the coefficient of the "<<i + 1<<" term = \n";
            cin>>iCoeff;
            cout<<"Enter the exponetial of the "<<i + 1<<" term = \n";
            cin>>iExpo;

            p2[i].Coeff = iCoeff;
            p2[i].Expo = iExpo;

        }
    }

    public: void MulPoly()
    {
        int f = 1;
        int p3Expoi = 0;
        int p3Expoj = 0;
        double dAddCoeff = 0.0;
        if(iSize1 == 0)
        {
            cout<<"Insufficient Polynomial Expressions For Multiplication\n";
            return;
        }
        else if(iSize2 == 0)
        {
            cout<<"Insufficient Polynomial Expressions For Multiplication\n";
            return;
        }
        else
        {
            for(j = 0; j < iSize2; j++)
            {
                for(i = 0; i < iSize1; i++)
                {
                    p3[k].Coeff = p1[i].Coeff * p2[j].Coeff;
                    p3[k].Expo = p1[i].Expo + p2[j].Expo; 
                    k++;
                }
            }
            i = 0;
            while(i < k)
            {
                j = 1+i;
                while(j < k)
                {
                    p3Expoi = p3[i].Expo;
                    p3Expoj = p3[j].Expo;
                    if(p3Expoi == p3Expoj)
                    {
                        dAddCoeff = (double)(p3[i].Coeff) + (double)(p3[j].Coeff);
                        p3[i].Coeff = dAddCoeff;
                        p3[j].Coeff = -1-f;
                        p3[j].Expo = -1-f;
                        f++;
                    }
                    j++;
                } 
                if(p3[i].Expo >= 0)
                {
                    p4[l].Coeff = p3[i].Coeff;
                    p4[l].Expo = p3[i].Expo;
                    l++;
                }
                i++;
            }
            iSize1 = 0;
            iSize2 = 0;
        }
    }

    public: void DisplayPoly()
    {
        if(l != 0)
        {
            cout<<"The array containing an final polynomial multiplication = \n";
            for(i = 0; i < l; i++)
            {
                cout<<"|";
                cout<<p4[i].Coeff;
                cout<<"|";
                cout<<p4[i].Expo; 
                cout<<"|\t";
            }
            cout<<"\n";
            iSize1 = 0;
            iSize2 = 0;
            i = 0;
            j = 0;
            k = 0;
            l = 0;
        }
        else
        {
            cout<<"The Multiplication Of The Polynomial is = "<<k<<"\n";
        }
    }

};

int main()
{
    Polynomial pobj = Polynomial(100);
    int iValue = 0;
    int iChoice = 1;

    while(iChoice != 0)
    {
        cout<<"-------------------------\n";
        cout<<"1 : Create An Polynomial\n";
        cout<<"2 : Multiply An Polynomials\n";
        cout<<"3 : Display Addition\n";
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
                cout<<"In case 2\n";
                pobj.MulPoly();
                break;
            case 3:
                pobj.DisplayPoly();
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