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
    private: int iSize1;
    private: int iSize2;
    private: int i;
    private: int j;
    private: int k;

    public: Polynomial(int size)
    {
        p1 = new p[size];
        p2 = new p[size];
        p3 = new p[size];
        iSize1 = 0;
        i = 0;
        j = 0;
        k = 0;
    }

    public: ~Polynomial()
    {
        delete[] p1,p2,p3;
    }

    public: void CreatePoly()
    {
        double Coeff = 0.0;
        int Expo = 0;
        cout<<"Enter the number of terms you have in your first polynomial = \n";
        cin>>iSize1;
        for(i = 0; i < iSize1; i++)
        {
            cout<<"Enter the coefficient of the "<<i+1<<" term=\n";
            cin>>Coeff;
            cout<<"Enter the exponent of the "<<i+1<<" term=\n";
            cin>>Expo;

            p1[i].Coeff = Coeff;
            p1[i].Expo = Expo;
        }

        cout<<"Enter the number of terms you have in your Second polynomial = \n";
        cin>>iSize2;
        for(i = 0; i < iSize2; i++)
        {
            cout<<"Enter the coefficient of the "<<i+1<<" term=\n";
            cin>>Coeff;
            cout<<"Enter the exponent of the "<<i+1<<" term=\n";
            cin>>Expo;

            p2[i].Coeff = Coeff;
            p2[i].Expo = Expo;
        }
    }

    public: void AddPoly()
    {
        i = 0;
        
        if(iSize1 == 0)
        {
            cout<<"Insufficient Polynomial Expressions For Addition\n";
            return;
        }
        else if(iSize2 == 0)
        {
            cout<<"Insufficient Polynomial Expressions For Addition\n";
            return;
        }
        else
        {
            while(( i < iSize1)&&(j < iSize2))
            {
            if(p1[i].Expo == p2[j].Expo)
            {
                p3[k].Coeff = p1[i].Coeff + p2[j].Coeff;
                p3[k].Expo = p1[i].Expo; 
                    i++;
                    j++;
                    k++;
            }
            else if(p1[i].Expo > p2[j].Expo)
            {
                p3[k].Coeff = p1[i].Coeff;
                p3[k].Expo = p1[i].Expo;
                i++;
                k++;
            }
            else if(p2[j].Expo > p1[i].Expo)
            {
                p3[k].Coeff = p2[j].Coeff;
                p3[k].Expo = p2[j].Expo;
                j++;
                k++;
            }
            }
            
            if(i < iSize1)
            {
                while(i != iSize1)
                {
                    p3[k].Coeff = p1[i].Coeff;
                    p3[k].Expo = p1[i].Expo;
                    i++;
                    k++;
                }
            }
            else if(j < iSize2)
            {
                while(j != iSize2)
                {
                    p3[k].Coeff = p2[j].Coeff;
                    p3[k].Expo = p2[j].Expo;
                    i++;
                    k++;
                }
            }
            iSize1 = 0;
            iSize2 = 0;
        }
    }

    public: void DisplayPoly()
    {
        if(k != 0)
        {
            cout<<"The Addition Of The Polynomial is = \n";
            for(i = 0; i < k ;i++)
            {
                cout<<"|";
                cout<<p3[i].Coeff;
                cout<<"|";
                cout<<p3[i].Expo;
                cout<<"|";
                cout<<"\t";
            }
            cout<<"\n";
            iSize1 = 0;
            iSize2 = 0;
            i = 0;
            j = 0;
            k = 0;
        }
        else
        {
            cout<<"The Addition Of The Polynomial is = "<<k<<"\n";
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
        cout<<"2 : Add An Polynomials\n";
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
                pobj.AddPoly();
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