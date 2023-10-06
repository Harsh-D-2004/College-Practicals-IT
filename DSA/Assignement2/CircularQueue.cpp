#include<iostream>
using namespace std;

struct Queue
{
    int backindex;
    int frontindex;
    int iSize;
    int iCount;
    int Arr[];
};

class CircularQueue
{   private:
        struct Queue pobj;

    public:

        CircularQueue(int ilen)
        {
            pobj.backindex = 0;
            pobj.frontindex = 0;
            pobj.iSize = ilen;
            pobj.iCount = 0;
            pobj.Arr[pobj.iSize];
        }

        bool isFull();
        bool isEmpty();
        void Enqueue(int);
        int Dequeue();
        void Display();
        void Count();
};

bool CircularQueue :: isFull()
{
    if(((pobj.backindex + 1) % (pobj.iSize) )== pobj.frontindex)
    {
        return true;
    }

    return false;
}

bool CircularQueue :: isEmpty()
{
    if(pobj.backindex == pobj.frontindex)
    {
        return true;
    }

    return false;
}

void CircularQueue :: Enqueue(int iValue)
{	
	int i = 0;
	
	if(isFull() == true)
	{
		   cout<<"Queue Overflow \n";
		   return;
	}
	else
	{
		   pobj.backindex = ((pobj.backindex) + 1 % (pobj.iSize));
		   pobj.Arr[pobj.backindex] = iValue;
		   pobj.iCount++;
	}
    
}

int CircularQueue :: Dequeue()
{   
    int iRet = 0;

    if(isEmpty() == true)
    {
        cout<<"Queue is Empty \n";
        return -1;
    }
    else
    {
        pobj.frontindex = ((pobj.frontindex) + 1 % (pobj.iSize));
        iRet = pobj.Arr[pobj.frontindex];
        pobj.Arr[pobj.frontindex] = -1;
        pobj.iCount--;
    }

    return iRet;
}

void CircularQueue :: Display()
{	
	if(isEmpty() == true)
	{
		cout<<"The Queue is empty \n";
		return;
	}

    for(int i = pobj.frontindex ; i != pobj.backindex ; i = (i + 1) % pobj.iSize)
    {
        cout<<pobj.Arr[i]<<"\t";
    }
    cout<<"\n";
}

void CircularQueue :: Count()
{
    cout << "The number of elements are : " <<pobj.iCount<<"\n";
}


int main()
{   
    int iLen = 0;
    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;
    bool bRet = 0;

    cout<<"Enter the size of array : \n";
    cin>>iLen;

    CircularQueue cobj(4);
    
    while(1)
    {
    	cout<<"----------------------------------------------------- \n";
    	cout<<"1 : Enqueue \n";
    	cout<<"2 : Dequeue \n";
    	cout<<"3 : isEmpty \n";
    	cout<<"4 : isFull \n";
    	cout<<"5 : Display \n";
    	cout<<"6 : Count \n";
    	cout<<"7 : Exit \n";
    	cout<<"----------------------------------------------------- \n";
    	
    	cout<<"Enter the choice \n";
    	cin>>iChoice;
    	
    	switch(iChoice)
    	{
    		case 1:
    				cout<<"Enter the value u want to enter : \n";
    				cin>>iValue;
    				cobj.Enqueue(iValue);
    				break;
    				
    		case 2:
    				iRet = cobj.Dequeue();
    				if(iRet == -1)
    				{
    					cout<<"The Queue is empty \n";
    				}
    				cout<<"The Dequeued element is : "<<iRet<<"\n";
    				break;
    				
    		case 3:
    				bRet = cobj.isEmpty();
    				if(bRet == true)
    				{
    					cout<<"The queue is empty \n";
    				}
    				else
    				{
    					cout<<"The queue is not empty \n";
    				}
    				break;
    				
    		case 4:
    				bRet = cobj.isFull();
    				if(bRet == true)
    				{
    					cout<<"The queue is full \n";
    				}
    				else
    				{
    					cout<<"The queue is not full \n";
    				}
    				break;
    				
    		case 5:
    				cobj.Display();
    				break; 
    				
    		case 6:
    				cobj.Count();
    				break;
    				
    		case 7:
    				cout<<"Exiting the application.... \n";
    				return 0;
    				
    		default:
    				cout<<"Invalid Choice \n";
    				break;
    	}
    }

    return 0;
}
