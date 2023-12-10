# include<iostream>
using namespace std;

typedef class Node{
    public:

        Node * left;
        int data;
        Node * right;

} NODE , *PNODE;

class BST
{

    public:
        PNODE Insert(PNODE , int);
        void preorder(PNODE);
        PNODE Delete(PNODE , int);
        PNODE helper(PNODE);
        PNODE findLastRight(PNODE);
    
};

PNODE BST :: Insert(PNODE Head , int no)
{
    PNODE newn = NULL;
    PNODE temp = Head;
    newn = new NODE();

    newn -> data = no;
    newn -> left = NULL;
    newn -> right = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(1)
        {
            if(no == temp -> data)
            {
                printf("Duplicate element : Unable to Insert \n");
                free(newn);
                break;
            }
            else if(no > temp -> data)
            {
                if(temp -> right == NULL)
                {
                    temp -> right = newn;
                    break;
                }
                temp = temp -> right;
            }
            else if(no < temp -> data)
            {
                if(temp -> left == NULL)
                {
                    temp -> left = newn;
                    break;
                }
                temp = temp -> left;
            }
        }
    }

    return Head;
}

void BST :: preorder(PNODE Head)
{
    if(Head != NULL)
    {
        cout<<Head -> data<<"\t";
        preorder(Head -> left);
        preorder(Head -> right);
    }
}

PNODE BST::Delete(PNODE Head, int k)
{
    if(Head == NULL)
    {
        return Head;
    }
    else if(Head -> data == k)
    {
        return helper(Head);
    }

    PNODE temp = Head;

    while(Head != NULL)
    {
        if(k < Head -> data)
        {
            if(Head -> left != NULL && Head -> left -> data == k)
            {
                Head -> left = helper(Head -> left);
            }
            else
            {
                Head  = Head -> left;
            }
        }
        else if(k > Head -> data)
        {
            if(Head -> right != NULL && Head -> right -> data == k)
            {
                Head -> right = helper(Head -> right);
            }
            else
            {
                Head  = Head -> right;
            }
        }
    }

    return temp;
}

PNODE BST::helper(PNODE Head)
{
    if(Head -> left == NULL)
    {
        return Head -> right;
    }
    else if(Head -> right == NULL)
    {
        return Head -> left;
    }
    else
    {
        PNODE rcon = Head -> right;
        PNODE lcon = findLastRight(Head -> left);
        lcon -> right = rcon;
        return Head -> left;
    }
}

PNODE BST::findLastRight(PNODE Head)
{
    if(Head -> right == NULL)
    {
        return Head;
    }
    return findLastRight(Head -> right);
}

int main()
{   
    PNODE Head = NULL;

    BST bobj;

    Head = bobj.Insert(Head , 11);
    Head = bobj.Insert(Head , 22);
    Head = bobj.Insert(Head , 10);

    bobj.preorder(Head);
    bobj.Delete(Head , 10);
    bobj.preorder(Head);

    return 0;
}