#include <iostream>
#include "mgraph.h"
#include "lgraph.h"
using namespace std;

int main()
{
    LGraph<int> gra1(2);
    cout<<"-----�ڽӱ��ʾ��-----"<<endl;
    gra1.Insert(1,0,1);
    gra1.Insert(0,1,1);
    gra1.Output();
    cout<<"ɾ����<1,0>"<<endl;
    gra1.Remove(1,0);
    gra1.Output();
    cout<<endl;
    cout<<"-----�ڽӾ����ʾ��-----"<<endl;
    MGraph<int> gra(5,0);
    int k;
    cout<<"����ͼ�ıߵ�Ȩ�أ�"<<endl;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            cin>>k;
            gra.Insert(i,j,k);
        }
    cout<<"ͼ�Ŀ�ȱ���Ϊ��";
    gra.BFS();
    cout<<endl;
    cout<<"ɾ����<1,2>"<<endl;
    gra.Remove(1,2);
    gra.Output();
    cout<<endl<<"ɾ����<1,2>�����ȱ�����";
    gra.BFS();
    cout<<endl;
    cout<<"�����<1,2>"<<endl;
    gra.Insert(1,2,1);
    gra.Output();
    cout<<endl<<"ͼ����ȱ���Ϊ��";
    gra.DFS();
}
