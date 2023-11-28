 
#include <iostream>  
using namespace std ;  
  
typedef class node   
{  
    public:  
        char info ;  
        node* l ;  
        node* r ;  
        node* nxt = NULL ;  

        node ( char c )  
        {  
            this->info = c ;  
            l = NULL ;  
            r = NULL ;  
        }  

        node()  
        {  
            l = NULL ;  
            r = NULL ;  
        }  

} NODE , *PNODE;  

class Stack   
{  
    PNODE head = NULL ;  
  
    public:  
        void push ( PNODE ) ;  
        PNODE pop() ;  

} ;    
  
void Stack::push( PNODE x )  
{  
    if ( head == NULL )   
    {  
        head = x ;  
    }  

    else   
    {  
        x->nxt = head ;  
        head = x ;  
    }  
}  
node* Stack::pop()  
{  
    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        PNODE p = head ;  
        head = head->nxt ;  
        return p ;  
    }
}  

class tree   
{  
    public:  

        void inorder(PNODE);
        void preorder(PNODE);
        void postorder(PNODE);
};

void tree :: inorder ( PNODE x )  
{   
    // if ( x == NULL )  
    //     return ;  

    if(x != NULL)  
    {  
        inorder ( x->l ) ;  
        cout << x->info << " " ;  
        inorder ( x->r ) ;  
    }  
}  

void tree :: preorder ( PNODE x )
{
    // if ( x == NULL )  
    //     return ;  
    if(x != NULL)
    {  
        cout << x->info << " " ;  
        inorder ( x->l ) ;  
        inorder ( x->r ) ;  
    } 
}  

void tree :: postorder ( PNODE x )
{
    // if ( x == NULL )  
    //     return ;  
    if(x != NULL)   
    {  
        inorder ( x->l ) ;  
        inorder ( x->r ) ;  
        cout << x->info << " " ;  
    } 
}

int main()  
{  
    string str = "" ;  
    cout<<"Enter a postfix expression \n"; 
    cin>>str;

    Stack sobj ;  
    tree tobj ;  
    PNODE p, q, ret;  
    int n = str.length() ;  
    for ( int i = 0 ; i < n ; i++ )   
    {  
          
  
        if ( str[ i ] == '+' || str[ i ] == '-' || str[ i ] == '*' || str[ i ] == '/' || str[ i ] == '^')   
        {  
            ret = new node( str[i] ) ;  
            p = sobj.pop() ;  
            q = sobj.pop() ;  
            ret->l = q ;  
            ret->r = p ;  
            sobj.push(ret) ;  
        }  
        else   
        {  
            ret = new node( str[ i ] ) ;  
            sobj.push(ret) ;  
        }  
    }  
    cout << " The Inorder Traversal of Expression Tree:  \n" ;  
    tobj.inorder(ret) ;  
    cout<<"\n";

    cout << " The preorder Traversal of Expression Tree: \n" ;  
    tobj.preorder(ret);
    cout<<"\n";

    cout << " The postorder Traversal of Expression Tree: \n" ;  
    tobj.postorder(ret);
    cout<<"\n";

    return 0 ;  
}  