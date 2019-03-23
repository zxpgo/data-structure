#include "seqstack.h"
#include <math.h>
using namespace std;
int icp(char ch)
{
    switch (ch)
    {
    case '#':
        return 0;
    case '(':
        return 7;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
    case '%':
        return 4;
    case ')':
        return 1;
    default:
        return -1;
    }
}
int isp(char ch)
{
    switch (ch)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 3;
    case '*':
    case '/':
    case '%':
        return 5;
    case ')':
        return 7;
    default:
        return -1;
    }
}

class Calculator
{
public:
    Calculator(int maxSize1,int maxSize2):a(maxSize1),b(maxSize2){};
    void Run();
    void InfixToPost();
    void Arithmetic(char ch,double x,double y);
    void Clear(){a.Clear();b.Clear();}
private:
    SeqStack<double> a;
    SeqStack<char> b;
    bool GetOperands(double &,double &);
    void DoOperator(char);

};
void Calculator::Arithmetic(char ch,double x,double y)
{

     switch(ch)
     {
        case '+':
            a.Push(x+y);
            break;
        case '-':
            a.Push(y-x);
            break;
        case '*':
            a.Push(x*y);
            break;
        case '/':if(fabs(x)<1e-6)
        {
            cerr<<"Divide by 0"<<endl;
            Clear();
        }
        else
            a.Push(y/x);break;
        case '^':
            a.Push(pow(x,y));
            break;

    }
}
void Calculator::InfixToPost()
{
    char ch,sh,temp;
    double x,y;
    while(cin>>ch,ch!='#')
    {
        if(isdigit(ch) || isalpha(ch))
             a.Push(ch-48);
        else if(b.Top(temp),icp(ch)>isp(temp))
             b.Push(ch);
        else if( ch ==')')
        {
           a.Top(x);
           a.Pop();
           a.Top(y);
           a.Pop();
           b.Top(sh);
           b.Pop();
           b.Pop();
           char t;
           b.Top(t);
           Arithmetic(sh,x,y);
        }
        else
        {
            b.Top(sh);
            b.Pop();
            b.Push(ch);
            a.Top(x);
            a.Pop();
            a.Top(y);
            Arithmetic(sh,x,y);
        }
    }
}
bool Calculator::GetOperands(double &op1,double &op2)
{
    if(!a.Top(op1))
    {
        cerr<<"Missing operand!"<<endl;
        return false ;
    }
    a.Pop();
    if(!a.Top(op2))
    {
        cerr<<"Missing operand!"<<endl;
        return false ;
    }
    a.Pop();
    return true;
}
void Calculator::DoOperator(char oper)
{
    bool result;
    double oper1,oper2;
    result=GetOperands(oper1,oper2);
    if(result)
        Arithmetic(oper,oper1,oper2);
    else
        Clear();
}
void Calculator::Run()
{
    char c;
    while(b.Top(c))
    {
        b.Pop();
        switch(c)
        {
            case '+':DoOperator(c); break;
            case '-':DoOperator(c); break;
            case '*':DoOperator(c); break;
            case '/':DoOperator(c); break;
            case '^':DoOperator(c); break;
            default:break;
        }
    }
    double r;
    a.Top(r);
    cout<<"多项式计算后的结果是："<<r<<endl;
}
