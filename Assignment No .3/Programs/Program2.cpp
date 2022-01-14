#include<iostream>
#include<stdlib.h>

using namespace std;

struct SMATRIX {
    int iRow;
    int iCol;
    int iValue;
};

typedef struct SMATRIX sm; 

class SparseMatrix
{
    private: int iRow;
    private: int iCol;
    private: int k;
    private: int **arr;
    private: int *iTotal;
    private: int *iIndex;
    private: SMATRIX* sm;
    private: SMATRIX* sm1;
    private: SMATRIX* result;

    public: SparseMatrix(int iRows, int iCols)  // O(n)
    {
        iRow = iRows;
        iCol = iCols;
        
        arr = new int*[iRow];
        for(int i = 0; i < iRow; i++)
        {
            arr[i] = new int[iCol];
        }

        sm = new SMATRIX[iRow*iCol];
        sm1 = new SMATRIX[iRow*iCol];

        sm[0].iRow = iRow;
        sm[0].iCol = iCol;
        sm1[0].iRow = iRow;
        sm1[0].iCol = iCol;

        iTotal = new int[sm[0].iCol];
        iIndex = new int[(sm[0].iCol)+1];
        result = new SMATRIX[iRow * iCol];

        k = 1;
    
    }

    public: ~SparseMatrix() // O(n)
    {
        int i = 0;
        for(int i = 0; i < iRow; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        delete[] sm;
        delete[] sm1;
        delete[] result;
        delete[] iTotal;
        delete[] iIndex;
    }

    public: void AcceptArray()  // O(n * m)
    {
        int iElements = 0;
        
        for(int i = 0 ; i < iRow; i++)
        {
            for(int j = 0; j < iCol; j++)
            {
                cout<<"Enter The element at "<<i<<" row & "<<j<<" column in array=\n";
                cin>>iElements;
                arr[i][j] = iElements;
            }
        }
    }

    public: void DisplayMatrix()
    {
        cout<<"Entered elements are = \n";  // O(n *m)
        for(int i = 0 ; i < iRow; i++)
        {
            for(int j = 0; j < iCol; j++)
            {
                cout<<arr[i][j]<<"\t";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    public: void ConvertConven()    // O(n*m)
    {
        int temp = 0;

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
    }

    public: void DisplayConven()    // O(n)
    {
        cout<<"Sparse Matrix Representation of Conventional Matrix = \n";
        cout<<"Row\tColumns\tValues\n";
        for(int i = 0; i < k; i++)
        {
            cout<<sm[i].iRow<<"\t";
            cout<<sm[i].iCol<<"\t";
            cout<<sm[i].iValue<<"\t\n";
        }
    }

    public: void CalculateSimTrans()    // O(n)
    {
        int temp = 0; 

        sm1[0].iValue = sm[0].iValue;

        for(int i = 1; i < k; i++)
        {
            sm1[i].iRow = sm[i].iCol;
            sm1[i].iCol = sm[i].iRow; 
            sm1[i].iValue = sm[i].iValue;
        }
    }

    public: void DisplaySimpleTrans()   // O(n)
    {
        cout<<"Simple Transpose of sparse Matrix Before Swapping = \n";
        for(int i = 0; i < k; i++)
        {
            cout<<sm1[i].iRow<<"\t";
            cout<<sm1[i].iCol<<"\t";
            cout<<sm1[i].iValue<<"\t\n";
        }
    }

    public: void CalculateSimSwapTrans()    // O(n * m)
    {
        int temp = 0;

        for(int i = 1; i < k - 1; i++)
        {
            for(int j = 1; j < k-1-i; j++)
            {
                if(sm1[j].iRow > sm1[j+1].iRow)
                {
                    iRow = sm1[j].iRow;
                    iCol = sm1[j].iCol;
                    temp = sm1[j].iValue;

                    sm1[j].iRow = sm1[j+1].iRow;
                    sm1[j].iCol = sm1[j+1].iCol;
                    sm1[j].iValue = sm1[j+1].iValue;

                    sm1[j+1].iRow = iRow;
                    sm1[j+1].iCol = iCol;
                    sm1[j+1].iValue = temp;
                }
            }
        }
    }

    public: void DisplaySimSwapTrans()   // O(n)
    {
        cout<<"Simple Transpose of sparse Matrix in sorted manner = \n";
        for(int i = 0; i < k; i++)
        {
            cout<<sm1[i].iRow<<"\t";
            cout<<sm1[i].iCol<<"\t";
            cout<<sm1[i].iValue<<"\t\n";
        }
    }

    public: void ConvertFastTran()  //  O(n + m)
    {
        int Col = 0;
        int Loc = 0;

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
    }

    public: void DisplayFastTras()  //  O(n)
    {
        cout<<"Fast Transpose sparse Matrix in sorted manner = \n";
        for(int i = 0; i <= sm[0].iValue; i++)
        {
            cout<<result[i].iRow<<"\t";
            cout<<result[i].iCol<<"\t";
            cout<<result[i].iValue<<"\t\n";
        }
    }
};

int main()
{
    int iRow = 0;
    int iCol = 0;

    cout<<"Enter the number of rows = \n";
    cin>>iRow;
    cout<<"Enter the number of columns = \n";
    cin>>iCol;

    SparseMatrix sobj(iRow, iCol);
    sobj.AcceptArray();
    sobj.DisplayMatrix();
    sobj.ConvertConven();
    sobj.DisplayConven();
    sobj.CalculateSimTrans();
    sobj.DisplaySimpleTrans();
    sobj.CalculateSimSwapTrans();
    sobj.DisplaySimSwapTrans();
    sobj.ConvertFastTran();
    sobj.DisplayFastTras();
    sobj.~SparseMatrix();
    
    return 0;
}
