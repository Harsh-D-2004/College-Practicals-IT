#include <iostream>
using namespace std;

typedef struct Node
{

    struct Node *lchild;
    int data;
    struct Node *rchild;

    bool left;
    bool right;

} NODE, *PNODE;

class ThreadedBST
{
public:
    PNODE Insert(PNODE , int);
    void InOrder(PNODE);
    PNODE InOrderSuccessor(PNODE);
    void PreOrder(PNODE);
};

PNODE ThreadedBST ::Insert(PNODE Head , int data)
{

    PNODE ptr = Head;
    PNODE par = NULL;

    while (ptr != NULL)
    {

        if (data == (ptr->data))
        {

            cout << "Duplicate key \n";
            return Head;
        }

        par = ptr;

        if (data < (ptr->data))
        {

            if (ptr->left == false)
            {
                ptr = ptr->lchild;
            }

            else
            {
                break;
            }
        }
        else
        {
            if (ptr->right == false)
            {
                ptr = ptr->rchild;
            }

            else
            {
                break;
            }
        }
    }

    PNODE newn = new NODE();
    newn -> data = data;
    newn -> right = true;
    newn -> left = true;

    if(par == NULL)
    {
        Head = newn;
        newn ->lchild = NULL;
        newn ->rchild = NULL;
    }
    else if(data < (par -> data))
    {
        newn -> lchild = par -> lchild;
        newn -> rchild = par;
        par -> left = false;
        par -> lchild = newn;
    }
    else
    {
        newn -> rchild = par -> rchild;
        newn -> lchild = par;
        par -> right = false;
        par -> rchild = newn;
    }

    return Head;
}

PNODE ThreadedBST :: InOrderSuccessor(PNODE ptr){

    if(ptr -> right == true){
        return ptr -> rchild;
    }

    else
    {
        ptr = ptr -> rchild;
        
        while(ptr -> left == false){
        ptr = ptr -> lchild;
        }

    return ptr;

    }
}

void ThreadedBST :: InOrder(PNODE Head){

    if(Head == NULL)
    {
        cout<<"Tree is empty \n";
        return;
    }
    PNODE temp = Head;

    while(temp -> left == false){
        temp = temp -> lchild;
    }

    while(temp != NULL){
        cout<<temp -> data<<"\t";
        temp = InOrderSuccessor(temp);
    }
}

void ThreadedBST :: PreOrder(PNODE Head)
{
    PNODE curr = Head;

    while(curr!=NULL)
    {
        cout<<curr -> data<<"\t";

        if(curr->left == false)
            curr=curr->lchild;

        else if(curr->right== true)
            curr=curr->rchild;

        else
        {
            while(curr != NULL && curr -> right == true)      
                curr=curr->rchild;

            if(curr != NULL)                           
                curr = curr -> rchild;
        }
    }
}

int main()
{
    PNODE Head = NULL;
    int iChoice = 0;
    int iValue;

    ThreadedBST bobj;

    while(1)
    {
        cout<<"--------------------------------------- \n";
        cout<<"1 : Insert Node \n";
        // cout<<"2 : PreOrder \n";
        cout<<"3 : InOrder \n";
        cout<<"4 : Exit \n";
        cout<<"---------------------------------------- \n";

        cout<<"Enter Option : \n";
        cin>>iChoice;

        switch(iChoice){

            case 1:
                cout<<"Enter the value u want to enter : \n";
                cin>>iValue;
                Head = bobj.Insert(Head , iValue);
                break;

            case 2:
                bobj.PreOrder(Head);
                cout<<"\n";
                break;

            case 3:
                bobj.InOrder(Head);
                cout<<"\n";
                break;
            
            case 4:
                return -1;


            default:
                cout<<"Enter proper choice \n";
                break;
        }
    }



    return 0;
}