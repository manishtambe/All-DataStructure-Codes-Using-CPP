#include<iostream>

using namespace std;

struct node{
    struct node * next;
    int degree;
    int value;
    struct node * prev;
};

typedef node NODE;
typedef node *PNODE;
typedef node ** PPNODE;

void InsertElement(PPNODE Head, int degree, int value)
{
    PNODE newn = new NODE;
    newn -> prev = NULL;
    newn -> degree = degree;
    newn -> value = value;
    newn -> next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE temp = *Head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        (temp) -> next = newn;
        newn -> prev = temp;
    }
}

void Display(PNODE Head)
{
    if(Head == NULL)
    {
        return;
    }
    else
    {
        PNODE temp = Head;
        while(temp != NULL)
        {
            cout<<"|"<<temp -> degree<<"|"<<temp -> value<<"| ->";
            temp = temp -> next;
        }
        cout<<" NULL\n\n";
    }
}

int Count(PNODE Head)
{
    int iCount = 0;

    if(Head == NULL)
    {
        return 0;
    }
    else
    {
        PNODE temp = Head;

        while(temp != NULL)
        {
            iCount++;
            temp = temp -> next;
        }

        return iCount;
    }
}

void Addition(PNODE Head1, PNODE Head2, PPNODE Head3)
{
    int iSize1 = Count(Head1);
    int iSize2 = Count(Head2);
    int iSize3 = Count(*Head3);
    int iTemp = 0;
    int iTemp1 = 0;
    PNODE temp = Head1;
    PNODE temp1 = Head2;
    PNODE temp2 = *Head3;

    if(iSize1 >= iSize2)
    {
        iTemp = iSize1;
    }
    else
    {
        iTemp = iSize2;
    }

    while((temp != NULL) && (temp1 != NULL))
    {
        if(Head1 == NULL && Head2 == NULL)
        {
            return;
        }
        else if(Head1 == NULL && Head2 != NULL)
        {
            InsertElement(Head3, temp1->degree, temp1->value);
            temp1 = temp1 -> next;
        } 
        else if(Head1 != NULL && Head2 == NULL)
        {
            InsertElement(Head3, temp->degree, temp->value);
            temp = temp -> next;
        }
        else
        {
            if(temp ->degree == temp1 ->degree)
            {
                iTemp1 = temp ->value + temp1 -> value;
                InsertElement(Head3, temp->degree, iTemp1);
                temp = temp -> next;
                temp1 = temp1 -> next;
            }
            else if(temp ->degree > temp1 -> degree)
            {
                InsertElement(Head3, temp -> degree, temp -> value);
                temp = temp -> next;
            }
            else if(temp1 ->degree > temp -> degree)
            {
                InsertElement(Head3, temp1 -> degree, temp1 -> value);
                temp1 = temp1 -> next;
            }
        }
    }

    if(*Head3 == NULL)
    {
        return;
    }
    else
    {
        PNODE temp = *Head3;
        while(temp != NULL)
        {
            cout<<"|"<<temp -> degree<<"|"<<temp -> value<<"| ->";
            temp = temp -> next;
        }
        cout<<" NULL\n\n";
    }
}

void AdditionMul(PPNODE Head3, PPNODE Head4)
{
    PNODE temp1 = *Head3;
    PNODE temp2 = *Head3;
    PNODE temp3 = NULL;
    temp2 = temp2 -> next;
    int value= 0;

    while(temp1 != NULL)
    {
        value = temp1 -> value;
        while (temp2 != NULL)
        {
            if(temp1 -> degree == temp2 -> degree)
            {
                value = value + temp2 -> value;
                PNODE store = temp2 -> prev;
                if(temp2 -> next != NULL)
                {
                    store -> next = temp2 -> next;
                    store -> next -> prev = store;
                }
            }
            temp2 = temp2 -> next;
        }

        InsertElement(Head4, temp1->degree, value);
        temp3 = *Head3;
        if(temp3 != NULL)
        {
            (*Head3) = (*Head3) -> next;
            delete(temp3);
            temp2 = *Head3;
            temp1 = *Head3;
            if(temp2 != NULL)
            {
                temp2 = temp2 -> next;
            }
        }
        value = 0;
    }
}

void Multiplication(PNODE Head1, PNODE Head2, PPNODE Head3, PPNODE Head4)
{
    int iSize1 = Count(Head1);
    int iSize2 = Count(Head2);
    int iSize3 = Count(*Head3);
    int iTemp = 0;
    int iTemp1 = 0;
    PNODE temp = Head1;
    PNODE temp1 = Head2;

    if(iSize1 >= iSize2)
    {
        iTemp = iSize1;
    }
    else
    {
        iTemp = iSize2;
    }

    
        if(Head1 == NULL && Head2 == NULL)
        {
            return;
        }
        else if(Head1 == NULL && Head2 != NULL)
        {
            InsertElement(Head3, temp1->degree, temp1->value);
            temp1 = temp1 -> next;
        } 
        else if(Head1 != NULL && Head2 == NULL)
        {
            InsertElement(Head3, temp->degree, temp->value);
            temp = temp -> next;
        }
        else
        {
            while(temp != NULL)
            {
                while(temp1 != NULL)
                {
                    int degree, value;
                    
                    value = temp -> value * temp1 -> value;
                    degree = temp ->degree + temp1 ->degree;

                    InsertElement(Head3, degree, value);

                    temp1 = temp1 -> next;
                }
                temp1 = Head2;
                temp = temp -> next;
            }
            temp = Head1;
            AdditionMul(Head3, Head4);
        }

    if(*Head4 == NULL)
    {
        return;
    }
    else
    {
        PNODE temp = *Head4;
        while(temp != NULL)
        {
            cout<<"|"<<temp -> degree<<"|"<<temp -> value<<"| ->";
            temp = temp -> next;
        }
        cout<<" NULL\n\n";
    }
}

void Clear(PPNODE Head1, PPNODE Head2, PPNODE Head3, PPNODE Head4)
{
    *Head1 = NULL;
    *Head2 = NULL;
    *Head3 = NULL;
    *Head4 = NULL;
}

int main()
{
    PNODE Head1 = NULL;
    PNODE Head2 = NULL;
    PNODE Head3 = NULL;
    PNODE Head4 = NULL;
    InsertElement(&Head1, 7, 15);
    InsertElement(&Head1, 5, 13);
    InsertElement(&Head1, 2, 10);
    InsertElement(&Head1, 1, 9);
    InsertElement(&Head1, 0, 5);
    
    InsertElement(&Head2, 3, 9);
    InsertElement(&Head2, 2, 13);
    InsertElement(&Head2, 0, 6);
    
    cout<<"The First Polynomial Equation: -\n";
    Display(Head1);
    cout<<"The Second Polynomial Equation: -\n";
    Display(Head2);

    cout<<"The Addition Of Above Polynomial Equationa is: -\n";
    Addition(Head1, Head2, &Head3);

    Clear(&Head1, &Head2, &Head3, &Head4);

    InsertElement(&Head1, 0, 5);
    InsertElement(&Head1, 1, 2);
    InsertElement(&Head1, 3, 9);
    InsertElement(&Head1, 5, 3);
    
    InsertElement(&Head2, 0, 3);
    InsertElement(&Head2, 2, 1);
    InsertElement(&Head2, 4, 2);

    cout<<"The First Polynomial Equation: -\n";
    Display(Head1);
    cout<<"The Second Polynomial Equation: -\n";
    Display(Head2);

    cout<<"The Multiplication Of Above Polynomial Equationa is: -\n";
    Multiplication(Head1,Head2, &Head3, &Head4);

    Clear(&Head1, &Head2, &Head3, &Head4);

    return 0;

}