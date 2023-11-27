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
        bool Search(PNODE Head , int No);
        int CountLeafNodes(PNODE Head);
        PNODE deleteNode(PPNODE , int);
        int CountNodes(PNODE);
        int CountParentNodes(PNODE);
        int maxDepth(PNODE);
        void mirror(PNODE);


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

bool BST :: Search(PNODE Head , int No)
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

PNODE BST :: deleteNode(PPNODE Head, int k)
{
    if (*Head == NULL)
        return *Head;

    PNODE temp = *Head;
 
    if (temp->data > k) {
        temp->Lchild = deleteNode(&temp -> Lchild, k);
        return temp;
    }
    else if (temp->data < k) {
        temp->Rchild = deleteNode(&temp->Rchild, k);
        return temp;
    }

    if (temp->Lchild == NULL) {
        PNODE temp = temp->Rchild;
        delete temp;
        return temp;
    }
    else if (temp->Rchild == NULL) {
        Node* temp = temp->Lchild;
        delete temp;
        return temp;
    }
 
    else {
 
        PNODE succParent = temp;
 
        PNODE succ = temp->Rchild;
        while (succ->Lchild != NULL) {
            succParent = succ;
            succ = succ->Lchild;
        }

        if (succParent != temp)
            succParent->Lchild = succ->Rchild;
        else
            succParent->Rchild = succ->Rchild;
 
        temp->data = succ->data;
 
        delete succ;
        return temp;
    }
}

int BST :: CountNodes(PNODE Head)
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

int BST :: CountLeafNodes(PNODE Head)
{
    static int iCnt = 0;
    if(Head != NULL)
    {
        if((Head -> Lchild == NULL) && (Head -> Rchild == NULL))
        {   
            cout<<Head->data<<"\t";
            iCnt++;
        }
        CountLeafNodes(Head -> Lchild);
        CountLeafNodes(Head -> Rchild);
    }
    return iCnt;
}

int BST :: CountParentNodes(PNODE Head)
{
    static int iCnt = 0;
    if(Head != NULL)
    {
        if((Head -> Lchild != NULL) || (Head -> Rchild != NULL))
        {
            cout<<Head->data<<"\t";
            iCnt++;
        }
        CountParentNodes(Head -> Lchild);
        CountParentNodes(Head -> Rchild);
    }
    return iCnt;
}

int BST :: maxDepth(PNODE Head)
{
    if (Head == NULL)
        return 0;

    else {
        int lDepth = maxDepth(Head->Lchild);
        int rDepth = maxDepth(Head->Rchild);
 
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void BST :: mirror(PNODE Head)
{
    if (Head == NULL)
        return;
    else {
        PNODE temp;
 
        mirror(Head->Lchild);
        mirror(Head->Rchild);
 
        temp = Head->Lchild;
        Head->Lchild = Head->Rchild;
        Head->Rchild = temp;
    }
}

int main()
{
    PNODE First = NULL;
    bool bRet = false;
    int iValue = 0;
    int iChoice = 0;
    int iRet = 0;

    BST bobj;

    while(1)
    {
        cout<<"--------------------------------------- \n";
        cout<<"1 : Insert Node \n";
        cout<<"2 : PreOrder \n";
        cout<<"3 : Post Order \n";
        cout<<"4 : InOrder \n";
        cout<<"5 : Delete Node \n";
        cout<<"6 : Mirror \n";
        cout<<"7 : Count Leaf Nodes \n";
        cout<<"8 : Count Parent Nodes \n";
        cout<<"9 : Max Height \n";
        cout<<"10 : Search \n";
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

            case 5:
                cout<<"Enter the value u want to enter : \n";
                cin>>iValue;
                bobj.deleteNode(&First , iValue);
                break;

            case 6:
                bobj.mirror(First);
                break;

            case 7:
                bobj.CountLeafNodes(First);
                break;

            case 8:
                bobj.CountParentNodes(First);
                break;

            case 9:
                iRet = bobj.maxDepth(First);
                cout<<iRet<<"\n";
                break;

            case 10:
                cout<<"Enter the value u want to enter : \n";
                cin>>iValue;
                bRet = bobj.Search(First , iValue);
                if(bRet == true){
                    cout<<"Element present \n";
                }
                else
                {
                    cout<<"Element is absent \n";
                }
                break;

            default:
                cout<<"Enter proper choice \n";
                break;
        }
    }

    return 0;
}