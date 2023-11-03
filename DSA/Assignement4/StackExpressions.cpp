#include<iostream>
using namespace std;

typedef class Node
{
    public:

        char data;
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
        void Push(char); //InsertLast
        char Pop();      //DeleteLast
        char TopElement();
        void Display();
        int Count();
        int Precedence(char);
        void InfixToPostfix(string);
        char InfixToPrefix(string);
        int isOperand(char);
        bool isEmpty();
};

Stack :: Stack()
{
    First = NULL;
    iCount = 0;
}

void Stack :: Push(char cdata)     //Insertlast()
{
    PNODE newn = new NODE(cdata);
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

char Stack :: Pop()     //DeleteLast()
{
    PNODE temp = NULL;
    char cValue = '\0';

    if(First == NULL)
    {
        cout<<"Stack is empty \n";
        return '\0';
    }
    else if(First -> next == NULL)
    {
        cValue = First -> data;
        delete First;
    }
    else
    {
        temp = First;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        cValue = temp -> next -> data;
        delete temp -> next;
        temp -> next = NULL;
    }
    iCount--;
    return cValue;
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

char Stack :: TopElement()
{
    if(First == NULL)
    {
        return '\0';
    }
    else
    {
        return First -> data;
    }
}

int Stack :: Count()
{
    return iCount;
}

void Stack :: InfixToPostfix(string InfixExp)
{   
    Stack obj;

    string PostfixExp = new char(sizeof(InfixExp));
    int i = 0 , j = 0;

    for(i = 0 ; i < InfixExp.length() ; )
    {
        if(!isOperand(InfixExp[i]))
        {
            PostfixExp[j] = InfixExp[i];
            i++;
            j++;
        }
        else if(isOperand(InfixExp[i]))
        {   
            if(Precedence(InfixExp[i]) > Precedence(obj.TopElement()) || obj.First == NULL)
            {
                obj.Push(InfixExp[i]);
                i++;
            }
            else
            {
                PostfixExp[j] = obj.Pop();
                j++;
            }
        }

    }
    cout<<PostfixExp<<"\n";
    while(obj.iCount != 0)
    {   
        char c = obj.Pop();
        PostfixExp[j] = c;
        j++;
    }
    cout<<PostfixExp<<"\n";
}

int Stack :: Precedence(char cValue)
{
    if(cValue == '*' || cValue == '/')
    {
        return 3;
    }
    else if(cValue == '+' || cValue == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

bool Stack :: isEmpty()
{
    if(First == NULL)
    {
        return 1;
    }
    return 0;
}

int Stack :: isOperand(char cValue)
{
    if(cValue == '+' || cValue == '/' || cValue == '-' || cValue == '*')
    {
        return 1;
    }
    return 0;
}

int main()
{
    Stack obj;
    
    int iChoice = 1;
    char cValue = 0;
    char cRet = '\0';
    string InfixExp = "((x+(y*z))-w)";

    // cout<<"-----------------------------------------------\n";
    // cout<<"Dynamic implementation of stack \n";
    // cout<<"-----------------------------------------------\n";

    // while(iChoice != 0)
    // {
    //     cout<<"-----------------------------------------------\n";

    //     cout<<"Please enetr the option : \n";

    //     cout<<"1 : Push element into stack\n";
    //     cout<<"2 : Pop element from stack\n";
    //     cout<<"3 : Display elements from stack\n";
    //     cout<<"4 : Count elements from stack\n";
    //     cout<<"5 : Show top element from stack\n";
    //     cout<<"6 : Convert Infix to PostFix\n";
    //     cout<<"0 : Terminate the application\n";

    //     cout<<"-----------------------------------------------\n";

    //     cout<<"Please enter the option : \n";
    //     cin>>iChoice;

    //     switch(iChoice)
    //     {
    //         case 1:
    //             cout<<"Enter the element that you want to push : \n";
    //             cin>>cValue;
    //             obj.Push(cValue);
    //             break;
            
    //         case 2:
    //             cRet = obj.Pop();
    //             if(cRet != '\0')
    //             {
    //                 cout<<"Popped element from stack is : "<<cRet<<"\n";
    //             }
    //             break;

    //         case 3:
    //             obj.Display();
    //             break;
            
    //         case 4:
    //             cout<<"The number of elements is : "<<obj.Count()<<"\n";
    //             break;

    //         case 5:
    //             cout<<"The top element is : "<<obj.TopElement()<<"\n";
    //             break;

    //         case 6:
    //             // InfixExp = "((x+(y*z))-w)";
    //             obj.InfixToPostfix(InfixExp);
    //             break;
            
    //         case 0:
    //             cout<<"Thankyou for using application \n";
    //             break;

    //         default:
    //             cout<<"Enter valid option \n";
    //             break;
    //     }
    // }

    obj.InfixToPostfix(InfixExp);

    return 0;
}