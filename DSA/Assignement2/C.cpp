#include<iostream>
using namespace std;

struct QueueNode
{   
    int front;
    int back;
    int iSize;
    int * Arr;
    int iCount;

    QueueNode()
    {
        front = -1;
        back = -1;
        iCount = 0;
        iSize = 5;
        Arr = new int[iSize];
    }
};

class Queuex{

    private:
        QueueNode q;

    public:
        void Enqueue(int val);
        void Dequeue();
        void isEmpty();
        void isFull();
        void Count();
        void Display();
};

void Queuex :: Enqueue(int val)
{   
    if((q.front == 0 && q.back == q.iSize - 1) || (q.front == q.back + 1))
    {   
        cout<<"Overflow";
        return;
    }
    else
    {
        q.back = (q.back + 1) % q.iSize;
    }
    q.Arr[q.back] = val;
}

void Queuex :: Dequeue()
{
    if((q.front == -1 && q.back == -1) || (q.front == q.back))
    {
        cout<<"queue is empty \n";
    }
    else
    {
        q.Arr[q.back] = -1;
        q.back = q.back - 1;
        if(q.back == -1)
        {
            q.back = q.iSize - 1;
        }
    }
}

void Queuex :: Display()
{   

    for(int i = q.front ; i != q.back ; i = (i + 1) % q.iSize)
    {
        cout<<q.Arr[i]<<"\t";
    }
    cout<<"\n";
}

int main()
{   
    Queuex qobj;

    qobj.Enqueue(11);
    qobj.Enqueue(22);
    qobj.Enqueue(33);
    qobj.Enqueue(33);
    qobj.Enqueue(33);
    qobj.Enqueue(33);

    qobj.Display();


    return 0;
}

