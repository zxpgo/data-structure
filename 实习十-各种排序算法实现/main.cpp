#include "sort.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
const int m=30000;
int main()
{
    int elements[28]={40,4,5,2,3,11,8,7,6,20,16,15,18,19,30,31,41,23,25,60,70,90,100,99,66,77,111,46};
    cout<<"elementsΪ��"<<endl;
    Output(elements,28);
    cout<<"������elements��������ã�"<<endl;
    QuickSort(elements,28);
    Output(elements,28);
    srand(time(0));
    double start,end;
    int A1[m],A2[m],A3[m],A4[m],A5[m],A6[m];
    for(int i=0;i<m;i++)
        A1[i]=A2[i]=A3[i]=A4[i]=A5[i]=A6[i]=rand();
    start=(double)clock()/CLOCKS_PER_SEC;
    SelectSort(A1,m);
    end=(double)clock()/CLOCKS_PER_SEC;
    cout<<"��ѡ����������ʱ�䣺"<<end-start<<'s'<<endl;
    start=(double)clock()/CLOCKS_PER_SEC;
    InsertSort(A2,m);
    end=(double)clock()/CLOCKS_PER_SEC;
     cout<<"ֱ�Ӳ�����������ʱ�䣺"<<end-start<<'s'<<endl;
    start=(double)clock()/CLOCKS_PER_SEC;
    BubbleSort(A3,m);
    end=(double)clock()/CLOCKS_PER_SEC;
     cout<<"˫��ð����������ʱ�䣺"<<end-start<<'s'<<endl;
    start=(double)clock()/CLOCKS_PER_SEC;
    QuickSort(A4,m);
    end=(double)clock()/CLOCKS_PER_SEC;
     cout<<"������������ʱ�䣺"<<end-start<<'s'<<endl;
    start=(double)clock()/CLOCKS_PER_SEC;
    MergeSort(A5,m);
    end=(double)clock()/CLOCKS_PER_SEC;
     cout<<"��·�ϲ���������ʱ�䣺"<<end-start<<'s'<<endl;
    start=(double)clock()/CLOCKS_PER_SEC;
    HeapSort(A6,m);
    end=(double)clock()/CLOCKS_PER_SEC;
    cout<<"����������ʱ�䣺"<<end-start<<'s'<<endl;
    return 0;
}
