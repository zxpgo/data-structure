#include <iostream>
#include "queue.h"
using namespace std;
int main()
{
    SeqQueue<int> al;
    for(int i=0;i<10;i++)
        al.EnQueue(i);
    for(int i=0;i<10;i++)
    {
        cout<<al.Front()<<"  ";
        al.DeQueue();
    }
    cout<<endl;
    al.Clear();
    if(al.IsEmpty())
    cout<<"清除成功！"<<endl;
    return 0;
}
