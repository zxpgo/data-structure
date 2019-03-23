#include <iostream>
using namespace std;
const int mSize=20;
template <class T>
class SeqQueue
{
public:
    SeqQueue(int msize);
    ~SeqQueue(){delete [] q;}
    bool IsEmpty() const {return front1 == rear;}
    bool IsFull() const {return (rear+1)%maxSize==front1;}
    bool Front(T &x) const;
    bool EnQueue(T x);
    bool DeQueue();
    void Clear(){front1=rear=0;}
private:
    int front1,rear;
    int maxSize;
    T *q;
};
template <class T>
SeqQueue<T>::SeqQueue(int msize)
{
    maxSize=msize;
    q=new T[maxSize];
    front1=rear=0;
}
template <class T>
bool SeqQueue<T>::Front(T &x) const
{
    if(IsEmpty())
    {
        cout<<"empty"<<endl;
        return false;
    }
    x=q[(front1+1)%maxSize];
    return true;
}
template <class T>
bool SeqQueue<T>::EnQueue(T x)
{
    if(IsFull())
    {
        cout<<"Full"<<endl;
        return false;
    }
    q[(rear=(rear+1)% maxSize)]=x;
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
    front1=(front1+1)%maxSize;
    return true;
}
