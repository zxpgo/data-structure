#include <iostream>
#include "node.h"
using namespace std;
template <class T>
class Queue
{
public:
    virtual T Front()=0;
    virtual bool IsEmpty()=0;
    virtual bool EnQueue(T x)=0;
    virtual bool DeQueue()=0;
    virtual bool Clear()=0;
};

template <class T>
class SeqQueue:public Queue<T>
{
public:
    SeqQueue(){front1=NULL;rear=NULL;}
    T Front();
    bool IsEmpty();
    bool EnQueue(T x);
    bool DeQueue();
    bool Clear();
private:
    Node<T> *front1,*rear;
};
template <class T>
bool SeqQueue<T>::Clear()
{
    front1=rear;
    return true;
}
template <class T>
bool SeqQueue<T>::IsEmpty()
{
    return front1==rear;
}
template <class T>
bool SeqQueue<T>::EnQueue(T x)
{
    Node<T> *p=new Node<T>;
    p->elements=x;
    if(front1 == NULL)
    {
        front1=p;
        rear=p;
    }
    else
    {
        rear->link=p;
        rear=p;
    }
    return true;
}
template <class T>
T SeqQueue<T>::Front()
{
    return front1->elements;
}
template <class T>
bool SeqQueue<T>::DeQueue()
{
    front1=front1->link;
    return true;
}
