#include <iostream>
using namespace std;
template <class T>
class Stack
{
public:
    virtual bool IsEmpty() const=0;
    virtual bool IsFull() const=0;
    virtual T Top() const=0;
    virtual bool Push(T x)=0;
    virtual bool Pop()=0;
    virtual void Clear()=0;

};
template <class T>
class SeqStack:public Stack<T>
{
public :
    SeqStack(int mSize);
    ~SeqStack(){delete []s;}
    bool IsEmpty() const {return top==-1;}
    bool IsFull() const {return top== maxTop;}
    T Top() const;
    bool Push(T x);
    bool Pop();
    void Clear(){top=-1;}
private:
    int top;
    int maxTop;
    T *s;
};
template <class T>
SeqStack<T>::SeqStack(int mSize)
{
    maxTop=mSize-1;
    s=new T[mSize];
    top=-1;
}
template <class  T>
T SeqStack<T>::Top()const
{
    if(IsEmpty())
    {
        cout<<"Empty"<<endl;
        return false;
    }
    return s[top];
}
template <class T>
bool SeqStack<T>::Push(T x)
{
    if(IsFull())
    {
        cout<<"Overflow"<<endl;
        return false ;
    }
    s[++top]=x;
    return true ;
}
template <class T>
bool SeqStack<T>::Pop()
{
   if(IsEmpty())
   {
       cout<<"Underflow"<<endl;
       return false ;
   }
   top--;
   return true;
}

template <class T>
class Queue
{
public:
    virtual bool IsEmpty() const=0;
    virtual bool IsFull() const=0;
    virtual T Front() const=0;
    virtual bool EnQueue(T x)=0;
    virtual bool DeQueue()=0;
    virtual bool Clear()=0;
};
template <class T>
class SeqQueue:public Queue<T>
{
public:
    SeqQueue(int mSize);
    ~SeqQueue(){delete []q;}
    bool IsEmpty() const{return rear==front;}
    bool IsFull() const{return (rear+1)%maxSize==front;}
    T Front() const;
    bool EnQueue(T x);
    bool DeQueue();
    bool Clear(){rear=rear=0;}
private:
    int front,rear;
    int maxSize;
    T *q;
};
template <class T>
SeqQueue<T>::SeqQueue(int mSize)
{
    maxSize=mSize;
    q=new  T[maxSize];
    front=rear=0;
}
template <class T>
T SeqQueue<T>::Front()const
{
    T x;
    if(IsEmpty())
    {
        cout<<"empty"<<endl;
        return false;
    }
    x=q[(front+1)%maxSize];
    return x;
}
template <class T>
bool SeqQueue<T>::EnQueue(T x)
{
    if(IsFull())
    {
        cout<<"Full"<<endl;
        return false;
    }
    q[(rear=(rear+1)%maxSize)]=x;
    return true;
}
template <class T>
bool SeqQueue<T>::DeQueue()
{
    if(IsEmpty())
    {
        cout<<"Underflow"<<endl;
        return false;
    }
    front=(front+1)%maxSize;
    return true;
}
template <class T>
void Reverse(SeqStack<T>& s)
{
    SeqQueue<T> q(20);
    while (!s.IsEmpty())
    {
        q.EnQueue(s.Top());
        s.Pop();
    }
    while(!q.IsEmpty())
    {
        s.Push(q.Front());
        q.DeQueue();
    }
}
int main()
{
    SeqStack<int> Al(10);
    int a;
    for(int i=0;i<10;i++)
    {
        cin>>a;
        Al.Push(a);
    }
    Reverse(Al);
    for(int i=0;i<10;i++)
    {
        cout<<Al.Top()<<endl;
        Al.Pop();
    }
    return 0;
}
