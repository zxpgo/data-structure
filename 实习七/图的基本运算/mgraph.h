#include <iostream>
#include "graph.h"
#include "seqqueue.h"
using namespace std;
enum ResultCode{Underfow,Overflow,Success,Duplicate,NotPresent,Failure};
template <class T>
class MGraph
{
public:
    MGraph(int msize,const T& noedg);
    ~MGraph();
    ResultCode Insert(int u,int v,T w);
    ResultCode Remove(int u,int v);
    bool Exist(int u,int v);
    void DFS();
    void BFS();
    void Output();
protected:
    T **a;
    T noEdge;
    int n,e;
    void DFS(int v,bool* visited);
    void BFS(int v,bool* visited);
};
template <class T>
MGraph<T>::MGraph(int msize,const T& noedg)
{
    n=msize;
    e=0;
    noEdge=noedg;
    a=new T*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new T [n];
        for(int j=0;j<n;j++)
            a[i][j]=noEdge;
        a[i][i]=0;
    }
}
template <class T>
MGraph<T>::~MGraph()
{
    for(int i=0;i<n;i++)
        delete []a[i];
    delete []a;
}
template <class T>
bool MGraph<T>::Exist(int u,int v)
{
    if(u<0 || v<0 || u>n-1 || v>n-1 || u==v || a[u][v]==noEdge)
        return false;
    return true;
}
template <class T>
ResultCode MGraph<T>::Insert(int u,int v,T w)
{
    if(u<0 || v<0 || u>n-1 || v>n-1 || u==v)
        return Failure;
    if(a[u][v]!=noEdge)
        return Duplicate;
    a[u][v]=w;
    e++;
    return Success;
}
template <class T>
ResultCode MGraph<T>::Remove(int u,int v)
{
    if(u<0 || v<0 || u>n-1 || v>n-1 || u==v)
        return Failure;
    if(a[u][v]==noEdge)
        return NotPresent;
    a[u][v]=noEdge;
    e--;
    return Success;
}
template <class T>
void MGraph<T>::Output()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<this->Exist(i,j)<<"  ";
        cout<<endl;
    }
}
template <class T>
void MGraph<T>::DFS()
{
    bool* visited=new bool [n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    for(int i=0;i<n;i++)
        if(!visited[i])
        DFS(i,visited);
    delete []visited;
}
template <class T>
void MGraph<T>::DFS(int v,bool* visited)
{
    visited[v]=true;
    cout<<" "<<v;
    for(int j=0;j<n;j++)
        for(int i=0;i<n;i++)
            if(!visited[i] && a[j][i]!=0)
            DFS(i,visited);
}
template <class T>
void MGraph<T>::BFS()
{
    bool* visited=new bool [n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    for(int i=0;i<n;i++)
        if(!visited[i])
        BFS(i,visited);
    delete []visited;
}
template <class T>
void MGraph<T>::BFS(int v,bool* visited)
{
    SeqQueue<int> q(n);
    visited[v]=true;
    cout<<" "<<v;
    q.EnQueue(v);
    while(!q.IsEmpty())
    {
        q.Front(v);
        q.DeQueue();
        for(int j=0;j<n;j++)
        for(int i=0;i<n;i++)
                if(!visited[i] && a[j][i]!=0)
                   {
                        visited[i]=true;
                        cout<<" "<<i;
                        q.EnQueue(i);
                   }
    }
}
