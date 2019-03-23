template <class T>
class BTNode
{
public:
    BTNode(){lchild=rchild=NULL;}
    BTNode(const T& x)
    {
        element=x;
        lchild=rchild=NULL;
    }
    BTNode(const T& x,BTNode<T>* l,BTNode<T>* r)
    {
        element=x;
        lchild=l;
        rchild=r;
    }
    T element;
    BTNode<T>* rchild,*lchild;
};
