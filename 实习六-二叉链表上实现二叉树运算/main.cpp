#include <iostream>
#include "binarytree.h"
using namespace std;

int main()
{
    BinaryTree<char> a,b,x,y,z,w;
    int i,k;
    y.MakeTree('E',a,b);
    z.MakeTree('F',a,b);
    x.MakeTree('C',y,z);
    y.MakeTree('D',a,b);
    z.MakeTree('B',y,x);
    z.Traversal();
    cout<<endl;
    i=z.High();
    cout<<"�ö������ĸ߶�Ϊ��"<<i<<endl;
    k=z.Size();
    cout<<"�ö�������Ҷ�ӽ����Ϊ��"<<k<<endl;
    w.root=z.Copy(z.root);
    cout<<"���ƶ�������(��α���)��"<<endl;
    w.Traversal();
    cout<<"\n��������������������(��α���)��"<<endl;
    z.Exchange(z.root);
    z.Traversal();
    cout<<endl;
    z.Delete();
    if(z.IsEmpty())
    cout<<"������ɾ���ɹ���"<<endl;
}
