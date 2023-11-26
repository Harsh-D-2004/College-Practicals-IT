//Binary Search Tree

#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node * Lchild;
    struct Node * Rchild;
}NODE , *PNODE , **PPNODE;

class BST
{
    public: 
        void Insert(PPNODE , int);
        void PreOrder(PNODE);
        void PostOrder(PNODE);
        void InOrder(PNODE);
};

void BST :: Insert(PPNODE Head , int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = No;
    newn -> Lchild = NULL;
    newn -> Rchild = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(1)
        {
            if(No == temp -> data)
            {
                printf("Duplicate element : Unable to Insert \n");
                free(newn);
                break;
            }
            else if(No > temp -> data)
            {
                if(temp -> Rchild == NULL)
                {
                    temp -> Rchild = newn;
                    break;
                }
                temp = temp -> Rchild;
            }
            else if(No < temp -> data)
            {
                if(temp -> Lchild == NULL)
                {
                    temp -> Lchild = newn;
                    break;
                }
                temp = temp -> Lchild;
            }
        }
    }
}

void BST :: PreOrder(PNODE Head)
{
    if(Head != NULL)
    {
        printf("%d\t" , Head -> data);
        PreOrder(Head -> Lchild);
        PreOrder(Head -> Rchild);
    }
}

void BST :: PostOrder(PNODE Head)
{
    if(Head != NULL)
    {
        PostOrder(Head -> Lchild);
        PostOrder(Head -> Rchild);
        printf("%d\t" , Head -> data);
    }
}

void BST :: InOrder(PNODE Head)
{
    if(Head != NULL)
    {
        InOrder(Head -> Lchild);
        printf("%d\t" , Head -> data);
        InOrder(Head -> Rchild);
    }
}

bool Search(PNODE Head , int No)
{
    bool flag = false;

    if(Head == NULL)
    {
        printf("Tree is empty\n");
        return flag;
    }
    while(Head != NULL)
    {
        if(No == Head -> data)
        {
            flag = true;
            break;
        }
        else if(No > Head -> data)
        {
            Head = Head -> Rchild;
        }
        else if(No < Head -> data)
        {
            Head = Head -> Lchild;
        }
    }
    return flag;
}

int CountNodes(PNODE Head)
{
    static int iCnt = 0;
    if(Head != NULL)
    {
        iCnt++;
        CountNodes(Head -> Lchild);
        CountNodes(Head -> Rchild);
    }
    return iCnt;
}

int CountLeafNodes(PNODE Head)
{
    static int iCnt = 0;
    if(Head != NULL)
    {
        if((Head -> Lchild == NULL) && (Head -> Rchild == NULL))
        {
            iCnt++;
        }
        CountLeafNodes(Head -> Lchild);
        CountLeafNodes(Head -> Rchild);
    }
    return iCnt;
}

int CountParentNodes(PNODE Head)
{
    static int iCnt = 0;
    if(Head != NULL)
    {
        if((Head -> Lchild != NULL) || (Head -> Rchild != NULL))
        {
            iCnt++;
        }
        CountParentNodes(Head -> Lchild);
        CountParentNodes(Head -> Rchild);
    }
    return iCnt;
}

int main()
{
    PNODE First = NULL;
    bool bRet = false;
    int iValue = 0;
    int iChoice = 0;

    BST bobj;

    while(1)
    {
        cout<<"--------------------------------------- \n";
        cout<<"1 : Insert Node \n";
        cout<<"2 : PreOrder \n";
        cout<<"3 : Post Order \n";
        cout<<"4 : InOrder \n";
        cout<<"---------------------------------------- \n";

        cout<<"Enter Option : \n";
        cin>>iChoice;

        switch(iChoice){

            case 1:
                cout<<"Enter the value u want to enter : \n";
                cin>>iValue;
                bobj.Insert(&First , iValue);
                break;

            case 2:
                bobj.PreOrder(First);
                cout<<"\n";
                break;

            case 3:
                bobj.PostOrder(First);
                cout<<"\n";
                break;
            
            case 4:
                bobj.InOrder(First);
                cout<<"\n";
                break;

            default:
                cout<<"Enter proper choice \n";
                break;
        }
    }

    return 0;
}