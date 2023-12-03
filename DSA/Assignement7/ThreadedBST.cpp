#include<iostream> 
using namespace std; 
  
struct Node 
{ 
    struct Node *left, *right; 
    int info; 

    bool lthread; 

    bool rthread; 
}; 

class ThreadedBST{

    public:

        struct Node * insert(struct Node * , int);
        struct Node * inorderSuccessor(struct Node *);
        void inorder(struct Node *);
};
  
struct Node * ThreadedBST :: insert(struct Node *root, int ikey) 
{ 
    Node *ptr = root; 
    Node *par = NULL; 
    while (ptr != NULL) 
    { 
        if (ikey == (ptr->info)) 
        { 
            printf("Duplicate Key !\n"); 
            return root; 
        } 
  
        par = ptr; 
  
        if (ikey < ptr->info) 
        { 
            if (ptr -> lthread == false) 
                ptr = ptr -> left; 
            else
                break; 
        } 
  
        else
        { 
            if (ptr->rthread == false) 
                ptr = ptr -> right; 
            else
                break; 
        } 
    } 
  
    Node *tmp = new Node; 
    tmp -> info = ikey; 
    tmp -> lthread = true; 
    tmp -> rthread = true; 
  
    if (par == NULL) 
    { 
        root = tmp; 
        tmp -> left = NULL; 
        tmp -> right = NULL; 
    } 
    else if (ikey < (par -> info)) 
    { 
        tmp -> left = par -> left; 
        tmp -> right = par; 
        par -> lthread = false; 
        par -> left = tmp; 
    } 
    else
    { 
        tmp -> left = par; 
        tmp -> right = par -> right; 
        par -> rthread = false; 
        par -> right = tmp; 
    } 
  
    return root; 
} 
  
struct Node *  ThreadedBST:: inorderSuccessor(struct Node *ptr) 
{ 

    if (ptr -> rthread == true) 
        return ptr->right; 
  

    ptr = ptr -> right; 
    while (ptr -> lthread == false) 
        ptr = ptr -> left; 
    return ptr; 
} 
   
void ThreadedBST:: inorder(struct Node *root) 
{ 
    if (root == NULL) 
        printf("Tree is empty"); 
  

    struct Node *ptr = root; 
    while (ptr -> lthread == false) 
        ptr = ptr -> left; 

    while (ptr != NULL) 
    { 
        printf("%d ",ptr -> info); 
        ptr = inorderSuccessor(ptr); 
    } 
} 

int main()
{
    struct Node *  Head = NULL;
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
                Head = bobj.insert(Head , iValue);
                break;

            case 3:
                bobj.inorder(Head);
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