#include "stack.h"
#include <iostream>
template <class T>
class SeqStack : public Stack<T>
{
public :
    SeqStack(int mSize);
    ~SeqStack(){delete []s;}
    bool IsEmpty() const {return top==-1;}
    bool IsFull() const {return top== maxTop;}
    bool Top(T &x) const;
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
bool SeqStack<T>::Top(T &x)const
{
    if(IsEmpty())
    {
        return false;
    }
    x=s[top];
    return true;
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
