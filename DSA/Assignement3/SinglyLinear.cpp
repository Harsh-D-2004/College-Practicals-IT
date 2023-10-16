#include<iostream>
using namespace std;

typedef class Node
{
    public:

        int data;
        Node *next;

        Node()
        {
            data = 0;
            next = NULL;
        }

        Node(int iValue)
        {
            data = iValue;
            next = NULL;
        }

}NODE , *PNODE;

class LinkedList
{
    public:
        int iCount;
        PNODE First;

        LinkedList()
        {
            iCount = 0;
            First = NULL;
        }

        void Display()
        {
            PNODE temp = NULL;
            temp = First;
            cout<<"The elements of LinkedList are: \n";
            for(int iCnt = 1 ; iCnt <= iCount ; iCnt++)
            {
                cout<<temp -> data<<"\t";
                temp = temp -> next;
            }
            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }  

        virtual void InsertFirst(int No) = 0;
        virtual void InsertLast(int No) = 0;
        virtual void InsertAtPos(int No , int iPos) = 0;

        virtual void DeleteFirst() = 0;
        virtual void DeleteLast() = 0;
        virtual void DeleteAtPos(int iPos) = 0;
};

class SinglyLL : public LinkedList
{
    public:
        SinglyLL();
        ~SinglyLL();

        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No , int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyLL :: SinglyLL()
{

}

SinglyLL :: ~SinglyLL()
{

}

void SinglyLL :: InsertFirst(int No)
{
    PNODE newn = new NODE(No);

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
    iCount++;
}

void SinglyLL :: InsertLast(int No)
{
    PNODE newn = new NODE(No);

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        PNODE temp = First;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

void SinglyLL :: InsertAtPos(int No , int iPos)
{
    if((iPos < 1) && (iPos > iCount + 1))
    {
        cout<<"Invalid position \n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        PNODE temp = First;
        for(int iCnt = 1 ; iCnt < iPos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }
        PNODE newn = new NODE(No);

        newn -> next = temp -> next;
        temp -> next = newn;
    }
    iCount++;
}

void SinglyLL :: DeleteFirst()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        First = First -> next;
        delete temp;
    }
    iCount--;
}

void SinglyLL :: DeleteLast()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }
    iCount--;
}

void SinglyLL :: DeleteAtPos(int iPos)
{
    if((iPos < 1) && (iPos > iCount))
    {
        cout<<"Invalid position \n";
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        for(int iCnt = 1 ; iCnt < iPos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }
        PNODE tempx = temp -> next;
        temp -> next = tempx -> next;
        delete tempx;
    }
    iCount--;
}

int main()
{
    SinglyLL obj;

    int iChoice = 1;
    int iValue = 0;
    int iPosition = 0;
    int iRet = 0;

    cout<<"Singly Linear Linked List Application \n";

    while(1)
    {
        cout<<"-------------------------------------------------\n";

        cout<<"1 : Enter Node at First Position in LL \n";
        cout<<"2 : Enter Node at Last Position in LL \n";
        cout<<"3 : Enter Node at Given Position in LL \n";
        cout<<"4 : Delete Node at First Position in LL \n";
        cout<<"5 : Delete Node at Last Position in LL \n";
        cout<<"6 : Delete Node at Given Position in LL \n";
        cout<<"7 : Display LL \n";
        cout<<"8 : Count Nodes of LL \n";
        cout<<"0 : Terminate the Application \n";

        cout<<"-------------------------------------------------\n";

        cout<<"Enter Choice : \n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the number : \n";
                cin>>iValue;
                obj.InsertFirst(iValue);
                break;

            case 2:
                cout<<"Enter the number : \n";
                cin>>iValue;
                obj.InsertLast(iValue);
                break;

            case 3:
                cout<<"Enter the number : \n";
                cin>>iValue;
                cout<<"Enter the position : \n";
                cin>>iPosition;
                obj.InsertAtPos(iValue , iPosition);
                break;

            case 4:
                obj.DeleteFirst();
                break;

            case 5:
                obj.DeleteLast();
                break;

            case 6:
                cout<<"Enter the position : \n";
                cin>>iPosition;
                obj.DeleteAtPos(iPosition);
                break;

            case 7:
                obj.Display();
                break;

            case 8:
                iRet = obj.Count();
                cout<<"The number of elements in LL are "<<iRet<<"\n";
                break;

            case 0:
                cout<<"Thank you for using application \n";
                return 0;

            default:
                cout<<"Enter valid option \n";
                break;
        }
    }
    return 0;
}