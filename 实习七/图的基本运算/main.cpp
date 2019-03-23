#include <iostream>
#include "mgraph.h"
#include "lgraph.h"
using namespace std;

int main()
{
    LGraph<int> gra1(2);
    cout<<"-----邻接表表示法-----"<<endl;
    gra1.Insert(1,0,1);
    gra1.Insert(0,1,1);
    gra1.Output();
    cout<<"删除边<1,0>"<<endl;
    gra1.Remove(1,0);
    gra1.Output();
    cout<<endl;
    cout<<"-----邻接矩阵表示法-----"<<endl;
    MGraph<int> gra(5,0);
    int k;
    cout<<"输入图的边的权重："<<endl;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            cin>>k;
            gra.Insert(i,j,k);
        }
    cout<<"图的宽度遍历为：";
    gra.BFS();
    cout<<endl;
    cout<<"删除边<1,2>"<<endl;
    gra.Remove(1,2);
    gra.Output();
    cout<<endl<<"删除边<1,2>后的深度遍历：";
    gra.BFS();
    cout<<endl;
    cout<<"插入边<1,2>"<<endl;
    gra.Insert(1,2,1);
    gra.Output();
    cout<<endl<<"图的深度遍历为：";
    gra.DFS();
}
