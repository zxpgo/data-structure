#include <iostream>
#include<algorithm>
using namespace std;
void BuBBleSort(int elements[],int n)
{
    int first=0,last=n-1,k=0;
    while(first<last)
    {
        k=first;
        for(int i=first;i<last;i++)
            if(elements[i+1]<elements[i])
                {
                    swap(elements[i+1],elements[i]);
                    k=i;
                }
        last=k;
        for(int j=last;j>first;j--)
            if(elements[j-1]>elements[j])
            {
                swap(elements[j-1],elements[j]);
                k=j;
            }
        first=k;
    }
}
int main()
{
    int elements[5]={1,3,4,2,0};
    BuBBleSort(elements,5);
    for(int i=0;i<5;i++)
    cout<<elements[i]<<"  ";
    cout<<endl;
    return 0;
}
