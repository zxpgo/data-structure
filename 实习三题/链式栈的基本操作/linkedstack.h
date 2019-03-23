#include <iostream>
#include "stack.h"
#include "node.h"
using namespace std;
template <class T>
class LinkedStack
{
public:
    LinkedStack();
    ~LinkedStack();
    bool IsEmpty() const{return top==NULL;}
    bool Top(T &x);
    bool Push(T x);
    bool Pop();
    void Clear(){top=-1;};
private:
    Node<T>* top;
};
template <class T>
LinkedStack<T>::LinkedStack()
{
    top=NULL;
}
template <class T>
LinkedStack<T>::~LinkedStack()
{
    top=NULL;
}
template <class T>
bool LinkedStack<T>::Top(T &x)
{
    if(IsEmpty())
    {
        cout<<"UnderFlow!"<<endl;
        return false;
    }
    x=top->element;
    return true;
}
template <class T>
bool LinkedStack<T>::Push(T x)
{
    Node<T>* p=new Node<T>[1];
    p->element=x;
    if(top==NULL)
    {
        p->link=NULL;
        top=p;
    }
    else
    {
         p->link=top;
         top=p;
    }
    return true;
}
template <class T>
bool LinkedStack<T>::Pop()
{
    if(IsEmpty())
    {
        cout<<"UnderFlow!"<<endl;
        return false;
    }
    top=top->link;
    return true;
}

