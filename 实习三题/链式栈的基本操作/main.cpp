#include <iostream>
#include "linkedstack.h"
#include "complex.h"
using namespace std;

int main()
{
    LinkedStack<Complex> al;
    Complex a(0,0);
    for(int i=0;i<10;i++)
    {
        Complex x(i,i+1);
        al.Push(x);
    }
    for(int i=0;i<10;i++)
    {
        al.Top(a);
        a.Output();
        al.Pop();
    }
    return 0;
}
