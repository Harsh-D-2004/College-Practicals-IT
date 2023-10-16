#include<iostream>
using namespace std;

typedef class Node
{
    public:

        int data;
        Node *next;

        Node(int iValue)
        {
            data = iValue;
            next = NULL;
        }
}NODE , *PNODE;

class Stack
{
    private:    
        PNODE First;
        int iCount;
    
    public:
        Stack();
        void Push(int iNo); //InsertLast
        int Pop();      //DeleteLast
        void Display();
        int Count();
};

Stack :: Stack()
{
    First = NULL;
    iCount = 0;
}

void Stack :: Push(int iNo)     //Insertlast()
{
    PNODE newn = new NODE(iNo);
    PNODE temp = NULL;
    temp = First;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

int Stack :: Pop()     //DeleteLast()
{
    PNODE temp = NULL;
    int iValue = 0;

    if(First == NULL)
    {
        cout<<"Stack is empty \n";
        return -1;
    }
    else if(First -> next == NULL)
    {
        iValue = First -> data;
        delete First;
    }
    else
    {
        temp = First;

        while(temp -> next -> next)
        {
            temp = temp -> next;
        }
        iValue = temp -> next -> data;
        delete temp -> next;
        temp -> next = NULL;
    }
    iCount--;
    return iValue;
}

void Stack :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty \n";
        return;
    }

    cout<<"Elements of stack are : \n";

    PNODE temp = First;

    for(int iCnt = 1 ; iCnt <= iCount ; iCnt++)
    {
        cout<<temp -> data<<"\n";
        temp = temp -> next;
    }
}

int Stack :: Count()
{
    return iCount;
}

int main()
{
    Stack obj;
    
    int iChoice = 1;
    int iValue = 0;
    int iRet = 0;

    cout<<"-----------------------------------------------\n";
    cout<<"Dynamic implementation of stack \n";
    cout<<"-----------------------------------------------\n";

    while(iChoice != 0)
    {
        cout<<"-----------------------------------------------\n";

        cout<<"Please enetr the option : \n";

        cout<<"1 : Push element into stack\n";
        cout<<"2 : Pop element from stack\n";
        cout<<"3 : Display elements from stack\n";
        cout<<"4 : Count elements from stack\n";
        cout<<"0 : Terminate the application\n";

        cout<<"-----------------------------------------------\n";

        cout<<"Please enter the option : \n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the element that you want to push : \n";
                cin>>iValue;
                obj.Push(iValue);
                break;
            
            case 2:
                iRet = obj.Pop();
                if(iRet != -1)
                {
                    cout<<"Popped element from stack is : "<<iRet<<"\n";
                }
                break;

            case 3:
                obj.Display();
                break;
            
            case 4:
                cout<<"The number of elements is : "<<obj.Count()<<"\n";
                break;
            
            case 0:
                cout<<"Thankyou for using application \n";
                break;

            default:
                cout<<"Enter valid option \n";
                break;
        }
    }
    return 0;
}