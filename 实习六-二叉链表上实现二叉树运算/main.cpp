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
    cout<<"该二叉树的高度为："<<i<<endl;
    k=z.Size();
    cout<<"该二叉树的叶子结点数为："<<k<<endl;
    w.root=z.Copy(z.root);
    cout<<"复制二叉树得(层次遍历)："<<endl;
    w.Traversal();
    cout<<"\n交换二叉树左右子树得(层次遍历)："<<endl;
    z.Exchange(z.root);
    z.Traversal();
    cout<<endl;
    z.Delete();
    if(z.IsEmpty())
    cout<<"二叉树删除成功！"<<endl;
}
