#include <iostream>
#include <conio.h>
#define TRUE 1
#define FALSE 0
using namespace std;

class Node
{
    public:

        int data;
        Node *next;
};

class sll
{
private:
    Node *head;

public:
    sll();
    void create();
    void display();
    void search(int key);
    void insert_first();
    void insert_last();
    void insert_after();
    void dele();
    ~sll();
};

sll ::sll()
{
    head = NULL;
}

sll ::~sll()
{
}

void sll ::create()
{
    Node *temp, *New;
    int flag, val;
    char ans;
    flag = TRUE;
    do
    {
        cout << "Enter the data : \n";
        cin >> val;

        New = new Node;
        New->data = val;
        New->next = NULL;

        if (New == NULL)
        {
            cout << "Unbale to allocate memory \n";
        }

        if (flag == TRUE)
        {
            head = New;
            temp = head;
            flag = FALSE;
        }
        else
        {
            temp->next = New;
            temp = temp->next;
        }

        cout << "Do you want to enter more elements : (y/n)"<< "\n";
        ans = getche();
        cout << "\n";
    } while (ans == 'y' || ans == 'Y');

    cout << "The Singly Linear Linked List created \n";
}

void sll ::display()
{
    Node *temp;
    temp = head;

    if (head == NULL)
    {
        cout << "The list is empty \n";
        // getch();

        return;
    }

    cout << "The elements of linked list are : \n";

    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
    // getch();
}

void sll ::search(int key)
{
    Node *temp;
    temp = head;
    int found = FALSE;

    if (temp == NULL)
    {
        cout << "The list is empty \n";
        // getch();
        return;
    }
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            found = TRUE;
            break;
        }
        temp = temp->next;
    }
    if (found == TRUE)
    {
        cout << "The element is present \n";
        // getch();
    }
    else
    {
        cout << "The element is not present \n";
        // getch();
    }
}

void sll ::dele()
{
    Node *temp, *prev;
    temp = head;
    int ans;

    cout << "Enter the element to be deleted : \n";
    cin >> ans;

    while (temp != NULL)
    {
        if (temp->data == ans)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "The Node not found\n";
        // getch();
        return;
    }
    else
    {
        if (head == temp)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
    }
    cout << "The Element is deleted \n";
    // getch();
}

void sll ::insert_last()
{
    Node *temp, *New;
    temp = head;
    New = new Node;
    cout << "Enter the data : \n";
    cin >> New->data;

    if (temp == NULL)
    {
        head = New;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = New;
        New->next = NULL;
        cout << "The element is inserted \n";
    }
}

void sll ::insert_first()
{
    Node *temp, *New;
    temp = head;
    New = new Node;
    cout << "Enter the data: \n";
    cin >> New->data;

    if (temp == NULL)
    {
        head = New;
    }
    else
    {
        New->next = temp;
        head = New;
        cout << "The element is inserted \n";
    }
}

void sll ::insert_after()
{
    Node *temp, *New;
    int key;
    temp = head;
    New = new Node;
    cout << "Enter the data: \n";
    cin >> New->data;
    if (temp == NULL)
    {
        head = New;
    }
    else
    {
        cout << "Enter the element after which u want to enter the data \n";
        cin >> key;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                New->next = temp->next;
                temp->next = New;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }

        cout << "The element is inserted \n";
    }
}

int main()
{
    sll sobj;

    int ch1 = 0;
    int ch2 = 0;
    int ans = 0;
    int ival1 = 0;

    while(1)
    {
        cout<<"--------------------------------------------------------------------\n";
        cout << "Program to perform various operations \n";
        cout << "1.Create\n";
        cout << "2.Display\n";
        cout << "3.Search\n";
        cout << "4.Insert an element in Linked List\n";
        cout << "5.Delete an element is Linked List\n";
        cout << "6.Quit\n";
        cout << "Choose option (1 - 6)\n";
        cout<<"--------------------------------------------------------------------\n";

        cout << "Enter ur choice : \n";
        cin >> ch1;

        switch (ch1)
        {
        case 1:
            sobj.create();
            break;

        case 2:
            sobj.display();
            break;

        case 3:
            cout << "Enter the element u want to search : \n";
            cin >> ival1;
            sobj.search(ival1);
            break;

        case 4:
            cout << "The list is : \n";
            sobj.display();
            cout << "Menu \n";
            cout << "1.Insert First \n";
            cout << "2.Insert After \n";
            cout << "3.Insert Last \n";
            cout << "Choose option ( 1 - 3) \n";
            cin >> ch2;
            switch (ch2)
            {
            case 1:
                sobj.insert_first();
                break;

            case 2:
                sobj.insert_after();
                break;

            case 3:
                sobj.insert_last();
                break;

            default:
                cout << "Invalid choice \n";
            }
            break;

        case 5:
            sobj.dele();
            break;

        case 6:
            cout<<"Exiting the application................\n";
            return 0;

        default:
            cout << "Invalid choice \n";
            break;
        }
    }

    return 0;
}