#include <iostream>

using namespace std;
class Term
{
public:
    Term(int c,int e);
    Term(int c,int e,Term* nxt);
    Term* InsertAfter(int c,int e);
private:
    int coef;
    int exp;
    Term *link;
    friend ostream & operator<<(ostream &,const Term &);
    friend class Polynominal;
};
class Polynominal
{
public:
    Polynominal();
    ~Polynominal();
    void Output(ostream& out) const;
    void PolyAdd(Polynominal& r);
    void Addterms(istream & in);
    void Multiplication(Polynominal& r);
private:
    Term* theList;
    friend ostream & operator <<(ostream &,const Polynominal &);
    friend istream & operator >>(istream &,const Polynominal &);
    friend Polynominal& operator +(Polynominal &, Polynominal &);
    friend Polynominal& operator *(Polynominal &, Polynominal &);
};

Polynominal::Polynominal()
{
    theList=new Term(0,-1);
    theList->link=theList;
}
Polynominal::~Polynominal()
{
    Term* p=theList->link;
    while(p!=theList)
    {
        theList->link=p->link;
        delete p;
        p=theList->link;
    }
    delete theList;
}
void Polynominal::Addterms(istream & in)
{
    Term* q=theList;
    int c,e;
    for(;;)
    {
        cout<<"Input a term(coef,exp):\n"<<endl;
        cin>>c>>e;
        if(e<0)
            break;
        q=q->InsertAfter(c,e);
    }
}
void Polynominal::Output(ostream & out) const
{
    int first=1;
    Term *p=theList->link;
    cout<<"The polynominal is:\n"<<endl;
    for(;p!=theList;p=p->link)
    {
        if (!first && (p->coef>0))
            out<<"+";
        first =0;
        out<<*p;
    }
    cout<<"\n"<<endl;
}
void Polynominal::PolyAdd(Polynominal& r)
{
    Term* q,*q1=theList,*p;
    p=r.theList->link;
    q=q1->link;
    while(p->exp >=0)
    {
        while(p->exp < q->exp)
        {
            q1=q;
            q=q->link;
        }

        if(p->exp == q->exp)
        {
            q->coef=q->coef + p->coef;
            if(q->coef == 0)
            {
                q1->link=q->link;
                delete(q);
                q=q1->link;
            }
            else
            {
                q1=q;
                q=q->link;
            }
        }
        else
            q1=q1->InsertAfter(p->coef,p->exp);
        p=p->link;
    }
}
Polynominal d;
void Polynominal::Multiplication(Polynominal& r)
{
    Term* q,*p;
    Term* t;
    p=r.theList->link;
    while(p->exp>=0)
    {
        q=theList->link;
        Polynominal c;
        t=c.theList;
        while(q->exp>=0)
        {
            t=t->InsertAfter((p->coef)*(q->coef) , p->exp + q->exp);
            q=q->link;
            t=t->link;
        }
        d.PolyAdd(c);
        p=p->link;
    }
}
ostream& operator <<(ostream &out,const Polynominal &x)
{
    x.Output(out);
    return out ;
}
istream& operator >>(istream& in,Polynominal &x)
{
    x.Addterms(in);
    return in;
}
Polynominal& operator +(Polynominal &a,Polynominal &b)
{
    a.PolyAdd(b);
    return a;
}
Polynominal& operator *(Polynominal &a,Polynominal &b)
{
    a.Multiplication(b);
    return a;
}
Term::Term(int c,int e):coef(c),exp(e)
{
    link=0;
}
Term::Term(int c,int e,Term *nxt):coef(c),exp(e)
{
    link=nxt;
}
Term *Term::InsertAfter(int c,int e)
{
    link=new Term(c,e,link);
    return link;
}
ostream &operator <<(ostream & out ,const Term& val)
{
    if(val.coef==0)
        return out ;
    out<<val.coef;
    switch(val.exp)
    {
        case 0: break;
        case 1: out<<"X"; break;
        default: out<<"X^"<<val.exp; break;
    }
    return out ;
}

int main()
{
  Polynominal p,q;
  cin>>p;
  cout<<p;
  cin>>q;
  cout<<q;
  p*q;
  cout<<"两多项式相乘得："<<d;
  q=p+q;
  cout<<"两多项式相加得："<<q;
}
