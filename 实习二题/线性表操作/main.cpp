#include <iostream>
using namespace std;

template <class T>
class LinearList
{
public:
    virtual bool IsEmpty() const=0;
    virtual int Length() const=0;
    virtual bool Find(int i,T& x) const=0;
    virtual int Search(T x) const=0;
    virtual bool Insert(int i,T x)=0;
    virtual bool Delete(int i)=0;
    virtual bool Update(int i,T x)=0;
    virtual void Output(ostream& out) const =0;
    virtual bool DeleteX(const T &x)=0;
    virtual void Reverse() const=0;
protected:
    int n;
};

template <class T>
class SeqList:public LinearList<T>
{
public:
    SeqList(int msize);
    ~SeqList(){delete [] elements;}
    bool IsEmpty()const;
    int Length()const;
    bool Find(int i,T& x)const ;
    int Search(T x)const;
    bool Insert(int i,T x);
    bool Delete(int i);
    bool Update(int i,T x) ;
    void Output(ostream& out) const;
    void Reverse()const;
    bool DeleteX(const T &x) ;
private:
    int maxLength;
    T *elements;
    int n;
};
template <class T>
SeqList<T>::SeqList(int msize)
{
    maxLength=msize;
    elements=new T[maxLength];
    n=0;
}
template <class T>
bool SeqList<T>::IsEmpty() const
{
    return n==0;
}
template <class T>
int SeqList<T>::Length() const
{
    return n;
}
template <class T>
bool SeqList<T>::Find(int i,T& x) const
{
    if(i<-1 || i>n-1)
    {
        cout<<"Out of Bounds"<<endl;
        return false;
    }
    x=elements[i];
    return true;
}
template <class T>
int SeqList<T>::Search(T x) const
{
    for(int j=0;j<n;j++)
        if (elements[j]==x)
            return j;
    return -1;
}
template <class T>
bool SeqList<T>::Insert(int i,T x)
{
    if (i<-1 || i>n-1)
        {
            cout<<"Out of Bounds"<<endl;
            return false;
        }
    if(n==maxLength)
    {
        cout<<"Overflow"<<endl;
        return false;
    }
    for(int j=n-1;j>i;j--)
        elements[j+1]=elements[j];
    elements[i+1]=x;
    n++;
    return true;
}
template <class T>
bool SeqList<T>::Delete(int i)
{
    if (!n)
    {
        cout<<"UnderFlow"<<endl;
        return false ;
    }
     if (i<-1 || i>n-1)
    {
        cout<<"Out of Bounds"<<endl;
        return false;
    }
    for (int j=i+1;j<n;j++)
        elements[j-1]=elements[j];
    n--;
    return true;
}
template <class T>
bool SeqList<T>::Update(int i, T x)
{
     if (i<-1 || i>n-1)
     {
        cout<<"Out of Bounds"<<endl;
        return false;
     }
     elements[i]=x;
     return true;
}
template <class T>
void SeqList<T>::Output(ostream& out ) const
{
    for(int i=0;i<n;i++)
        out<<elements[i]<<' ';
    out<<endl;
}

template <class T>
bool SeqList<T>::DeleteX(const T &x)
{
    int count=0;
    int j=0;
    while(j<n)
    {
        if(elements[j]== x)
        {
            for(int i=j;i<n;i++)
            elements[i]=elements[i+1];
            count++;
        }
        else
            j++;
    }
    n=n-count;
    if(count==0)
        return false;
    else
        return true;
}
template <class T>
void SeqList<T>::Reverse() const
{
    T temp;
    int i=0;
    for(int i=0;i<n/2;i++)
    {
        temp=elements[i];
        elements[i]=elements[n-i-1];
        elements[n-i-1]=temp;
    }
}
const int SIZE=20;

int main()
{
    int m,n,k;
    SeqList <int> LA(SIZE);
    cout<<"请输入线性表中数据个数:"<<endl;
    cin>>m;
    cout<<"请输入线性表中的数据:"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>n;
        LA.Insert(i-1,n);
    }
    cout<<"原线性表数:"<<endl;
    LA.Output(cout);
    LA.Reverse();
    cout<<"逆置线性表后数据为:"<<endl;
    LA.Output(cout);
    cout<<"请输入要删除的数据:"<<endl;
    cin>>k;
    if(LA.DeleteX(k))
    {
        cout<<"删除数据"<<k<<"后线性表数据为:"<<endl;
        LA.Output(cout);
    }
    else
        cout<<"线性表中无此数据！";
}

