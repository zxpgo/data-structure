#include<iostream>
using namespace std;
class Complex
{
public:
    Complex()
    {
        real=0;
        image=0;
    }
    Complex(int a,int b)
    {
        real=a;
        image=b;
    }
    void Output()
    {
        if(image<0.0)
            cout<<"("<<real<<image<<"i)"<<endl;
        else
            cout<<"("<<real<<"+"<<image<<"i)"<<endl;
    }
private:
    int real;
    int image;
};
