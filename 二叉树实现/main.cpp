#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
   BinaryTree<char> a,b,x,y,z;
   y.MakeTree('E',a,b);
   z.MakeTree('F',a,b);
   x.MakeTree('C',y,z);
   y.MakeTree('D',a,b);
   z.MakeTree('B',y,x);
   z.PreOrder();
   cout<<endl;
   z.Exchange(z.root);
   z.PreOrder();
   cout<<endl;
   int count=0;
   count=z.Size1(z.root);
   cout<<"度数为1的结点个数："<<count<<endl;
   z.Delete(z);
    return 0;
}
