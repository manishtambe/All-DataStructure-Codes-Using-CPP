#include<iostream>

using namespace std;

#define MAXSIZE 100

typedef struct Poly{
    double Coeff;
    int Expo;
}p;

p p1[MAXSIZE],p2[MAXSIZE],p3[MAXSIZE];

int main()
{
    

    int iSize1 = 0;
    int iSize2 = 0;
    int i = 0;
    int j = 0;
    int k = 0;
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

    cout<<"The elements of the first polynomial are = \n";
    for(i = 0; i < iSize1; i++)
    {
        cout<<p1[i].Coeff;
        cout<<p1[i].Expo;
        cout<<"\t";
    }
    
    cout<<"\n";

    cout<<"The elements of the second polynomial are = \n";
    for(i = 0; i < iSize2; i++)
    {
        cout<<p2[i].Coeff;
        cout<<p2[i].Expo;
        cout<<"\t";
    }

    cout<<"\n\n";
    i = 0;

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
    return 0;
}