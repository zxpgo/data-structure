#include <algorithm>
#include <iostream>

using namespace std;
template <class T>
void Output(T A[],int n)
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
template <class T>
void SelectSort(T A[],int n)
{
    int small;
    for(int i=0;i<n-1;i++)
    {
        small=i;
        for(int j=i+1;j<n;j++)
            if(A[j]<A[small])
                small=j;
            swap(A[i],A[small]);
    }
}
template <class T>
void InsertSort(T A[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i;
        T temp=A[i];
        while(j>0 && temp<A[j-1])
        {
            A[j]=A[j-1];
            j--;
        }
        A[j]=temp;
    }
}
template <class T>
void BubbleSort(T A[],int n)
{
    int i,j,last;
    i=n-1;
    while(i>0)
    {
        last=0;
        for(j=0;j<i;j++)
        {
            if(A[j+1]<A[j])
            swap(A[j],A[j+1]);
            last=j;
        }
        i=last;
    }
}
template <class T>
void Qsort(T A[],int left,int right)
{
    int i,j;
    if(right-left<10)
    {
        int m=right-left+1;
        T B[m];
        for(int i=0;i<m;i++)
            B[i]=A[i+left];
        InsertSort(B,m);
        for(int i=0;i<m;i++)
            A[i+left]=B[i];
    }

    else if(left<right)
    {
        j=right+1;
        i=left;
        do
        {
            do i++; while(A[i]<A[left]);
            do j--; while(A[j]>A[left]);
            if(i<j)
                swap(A[i],A[j]);
        }while(i<j);
        swap(A[left],A[j]);
        Qsort(A,left,j-1);
        Qsort(A,j+1,right);
    }
}
template <class T>
void QuickSort(T A[],int n)
{
    Qsort(A,0,n-1);
}
template <class T>
void Merge(T A[],int i1,int j1,int i2,int j2)
{
    T *Temp=new T[j2-i1+1];
    int i=i1,j=i2,k=0;
    while(i<=j1 && j<=j2)
        if(A[i]<=A[j])
            Temp[k++]=A[i++];
        else
            Temp[k++]=A[j++];
    while(i<=j1)
        Temp[k++]=A[i++];
    while(j<=j2)
        Temp[k++]=A[j++];
    for(i=0;i<k;i++)
        A[i1++]=Temp[i];
    delete []Temp;
}
template <class T>
void MergeSort(T A[],int n)
{
    int i1,j1,i2,j2;
    int size=1;
    while(size<n)
    {
        i1=0;
        while(i1+size<n)
        {
            i2=i1+size;
            j1=i2-1;
            if(i2+size-1>n-1)
                j2=n-1;
            else
                j2=i2+size-1;
            Merge(A,i1,j1,i2,j2);
            i1=j2+1;
        }
        size*=2;
    }
}
template <class T>
void AdjustDown(T A[],int r,int j)
{
    int child=2*r+1;
    T temp=A[r];
    while(child<=j)
    {
        if((child<j) && (A[child]<A[child+1]))
            child++;
        if(temp>=A[child])
            break;
        A[(child-1)/2]=A[child];
        child=2*child+1;
    }
    A[(child-1)/2]=temp;
}
template <class T>
void HeapSort(T A[],int n)
{
    for(int i=(n-2)/2;i>-1;i--)
        AdjustDown(A,i,n-1);
    for(int i=n-1;i>0;i--)
    {
        swap(A[0],A[i]);
        AdjustDown(A,0,i-1);
    }
}

