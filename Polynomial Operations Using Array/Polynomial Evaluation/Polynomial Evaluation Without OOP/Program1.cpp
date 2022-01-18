#include<iostream>

using namespace std;

#define MaxSize 100

struct POLY{
    double Coeff;
    int Expo;
};

typedef struct POLY p;

p p1[MaxSize];

int main()
{
    int iSize = 0;
    int Add = 0;
    int y = 0;
    int i = 0;
    int x = 1; 
    int j = 0;
    int iCoeff = 0;
    int iExpo = 0;

    cout<<"Enter the number of term you have in polynomial = \n";
    cin>>iSize;

    for(i = 0; i < iSize; i++)
    {
        cout<<"Enter an coefficinet of the "<<i + 1<<" term = \n";
        cin>>iCoeff;
        cout<<"Enter an exponent of the "<<i + 1<<" term = \n";
        cin>>iExpo;

        p1[i].Coeff = iCoeff;
        p1[i].Expo = iExpo;

    }

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
    
    cout<<"Enter the value of the 'x' from the polynomial expression = \n";
    cin>>x;

    y = x;

    for(i = 0; i < iSize; i++)
    {
        iExpo = p1[i].Expo;

        if(iExpo != 0)
        {
            for(j = 0; j < iExpo - 1; j++)
            {
                x = x * y;
            }
            iCoeff = (int)p1[i].Coeff;
            Add = Add + x * iCoeff;
            x = y;
        }
        else if(iExpo == 0)
        {
            Add = Add + (int)p1[i].Coeff;
        }
    }
    
    cout<<"After the evaluating the polynomial the answer is = "<<Add<<"\n";

    return 0;
}

