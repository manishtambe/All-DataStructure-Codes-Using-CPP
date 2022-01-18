#include<iostream>

using namespace std;

#define MAXSIZE 100

struct POLY{
    double Coeff;
    int Expo;
};

typedef struct POLY p;

p p1[MAXSIZE];
p p2[MAXSIZE];
p p3[MAXSIZE];
p p4[MAXSIZE];

int main()
{
    double Coeff = 0.0;
    double dAddCoeff = 0.0;
    int Expo = 0;
    int p3Expoi = 0;
    int p3Expoj = 0;
    int f = 1;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int iSize1 = 0;
    int iSize2 = 0;

    cout<<"Enter the number of terms present in the first polynomial = \n";
    cin>>iSize1;

    for(i = 0; i < iSize1; i++)
    {
        cout<<"Enter the coeffient for the "<<i + 1<<" term = \n";
        cin>>Coeff;
        cout<<"Enter the exponent for the "<<i + 1<<" term = \n";
        cin>>Expo;
        p1[i].Coeff = Coeff;
        p1[i].Expo = Expo; 
    }

    cout<<"The array representation of the first polynomial is = \n";
    for(i = 0; i < iSize1; i++)
    {
        cout<<"|";
        cout<<p1[i].Coeff;
        cout<<"|";
        cout<<p1[i].Expo;
        cout<<"|";
        cout<<"\t";
    }

    cout<<"\n\n";

    cout<<"Enter the number of terms present in the second polynomial = \n";
    cin>>iSize2;

    for(i = 0; i < iSize2; i++)
    {
        cout<<"Enter the coeffient for the "<<i + 1<<" term = \n";
        cin>>Coeff;
        cout<<"Enter the exponent for the "<<i + 1<<" term = \n";
        cin>>Expo;
        p2[i].Coeff = Coeff;
        p2[i].Expo = Expo; 
    }

    cout<<"The array representation of the second polynomial is = \n";
    for(i = 0; i < iSize2; i++)
    {
        cout<<"|";
        cout<<p2[i].Coeff;
        cout<<"|";
        cout<<p2[i].Expo;
        cout<<"|";
        cout<<"\t";
    }

    cout<<"\n\n";
    i = 0;
 
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
    j = 1;
    
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

    cout<<"The array representation of the final polynomial after multiplication = \n";
    for(j = 0; j < l; j++)
    {
        cout<<"|";
        cout<<p4[j].Coeff;
        cout<<"|";
        cout<<p4[j].Expo;
        cout<<"|";
        cout<<"\t";
    }

    return 0;

}
