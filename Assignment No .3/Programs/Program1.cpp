#include<iostream>
#include<stdlib.h>

using namespace std;

struct SMATRIX {
    int iRow;
    int iCol;
    int iValue;
};

typedef struct SMATRIX sm; 

// class SparseMatrix
// {
//     private: int **arr;
//     private: int iRow;
//     private: int iCol;

//     public: SparseMatrix(int iRows, int iCols)
//     {
//         iRow = iRows;
//         iCol = iCols;
//         int i = 0;
//         arr = new int*[iRow];
//         for(i = 0; i < iRow; i++)
//         {
//             arr[i] = new int[iCols];
//         }
//     }
    
//     public: ~SparseMatrix()
//     {
//         int i = 0;
//         for(int i = 0; i < iRow; i++)
//         {
//             delete[] arr[i];
//         }
//         delete[] arr;
//     }

//     public: void AcceptArray()
//     {
//         int i = 0;
//         int j = 0;
//         for(i = 0; i < iRow; i++)
//         {
//             for(j = 0 ; j < iCol; j++)
//             {

//                 arr[i][j] = 
//             }
//         }
//     }
// };

int main()
{
    int **arr;
    int k = 1;
    int iRow = 0;
    int temp = 0;
    int iCol = 0;
    int iElements = 0;
    SMATRIX* sm;
    cout<<"Enter the number of rows = \n";
    cin>>iRow;
    cout<<"Enter the number of rows = \n";
    cin>>iCol;

    arr = new int*[iRow];
    for(int i = 0; i < iRow; i++)
    {
        arr[i] = new int[iCol];
    }

    for(int i = 0 ; i < iRow; i++)
    {
        for(int j = 0; j < iCol; j++)
        {
            cout<<"Enter The element at "<<i<<" row & "<<j<<" column =\n";
            cin>>iElements;

            arr[i][j] = iElements;
        }
    }
    
    cout<<"Entered elements are = \n";
    for(int i = 0 ; i < iRow; i++)
    {
        for(int j = 0; j < iCol; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<"\n";

    sm = new SMATRIX[iRow*iCol];

    sm[0].iRow = iRow;
    sm[0].iCol = iCol;

    for(int i = 0; i < iRow; i++)
    {
        for(int j = 0; j < iCol; j++)
        {
            if(arr[i][j] != 0)
            {
                sm[k].iRow = i;
                sm[k].iCol = j;
                sm[k].iValue = arr[i][j];
                k++;
            }
        }
    }

    temp = k;
    sm[0].iValue = temp-1;

    cout<<"Sparce Matrix Representation of Conventional Matrix = \n";
    cout<<"Row\tColumns\tValues\n";
    for(int i = 0; i < k; i++)
    {
        cout<<sm[i].iRow<<"\t";
        cout<<sm[i].iCol<<"\t";
        cout<<sm[i].iValue<<"\t\n";
    }

    //Simple Transpose before swapping
    for(int i = 0; i < k; i++)
    {
        temp = sm[i].iRow;
        sm[i].iRow = sm[i].iCol;
        sm[i].iCol = temp; 
    }

    cout<<"Simple Transpose Matrix Before Swapping = \n";
    for(int i = 0; i < k; i++)
    {
        cout<<sm[i].iRow<<"\t";
        cout<<sm[i].iCol<<"\t";
        cout<<sm[i].iValue<<"\t\n";
    }

    //Simple transpose matrix in sorted manner

    for(int i = 1; i < k - 1; i++)
    {
        for(int j = 1; j < k-1-i; j++)
        {
            if(sm[j].iRow > sm[j+1].iRow)
            {
                iRow = sm[j].iRow;
                iCol = sm[j].iCol;
                temp = sm[j].iValue;

                sm[j].iRow = sm[j+1].iRow;
                sm[j].iCol = sm[j+1].iCol;
                sm[j].iValue = sm[j+1].iValue;

                sm[j+1].iRow = iRow;
                sm[j+1].iCol = iCol;
                sm[j+1].iValue = temp;
            }
        }
    }

    cout<<"Simple Transpose Matrix in sorted manner = \n";
    for(int i = 0; i < k; i++)
    {
        cout<<sm[i].iRow<<"\t";
        cout<<sm[i].iCol<<"\t";
        cout<<sm[i].iValue<<"\t\n";
    }
    
    int Col = 0;
    int Loc = 0;
    int *iTotal = new int[sm[0].iCol];
    int *iIndex = new int[(sm[0].iCol)+1];
    SMATRIX* result;
    result = new SMATRIX[iRow * iCol];

    for(int i = 0; i < sm[0].iCol; i++)
    {
        iTotal[i] = 0;
    }
    
    for(int i = 1; i <= sm[0].iValue; i++)
    {
        Col = sm[i].iCol;
        iTotal[Col]++;
    }

    iIndex[0] = 1;

    for(int i = 1; i <= sm[0].iCol; i++)
    {
        iIndex[i] = iIndex[i-1] + iTotal[i-1];
    }

    result[0].iRow = sm[0].iCol;
    result[0].iCol = sm[0].iRow;
    result[0].iValue = sm[0].iValue;

    for(int i = 1; i <= sm[0].iValue; i++)
    {
        Col = sm[i].iCol;
        Loc = iIndex[Col];
        result[Loc].iCol = sm[i].iRow;
        result[Loc].iRow = sm[i].iCol;
        result[Loc].iValue = sm[i].iValue;
        iIndex[Col]++;
    }

    cout<<"Fast Transpose Matrix in sorted manner = \n";
    for(int i = 0; i <= sm[0].iValue; i++)
    {
        cout<<result[i].iRow<<"\t";
        cout<<result[i].iCol<<"\t";
        cout<<result[i].iValue<<"\t\n";
    }
    return 0;
}