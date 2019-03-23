#include <iostream>
#include "btnode.h"
#include "seqqueue.h"
using namespace std;
template <class T>
class BinaryTree
{
public:
    BinaryTree(){root=NULL;}
    ~BinaryTree(){}
    bool IsEmpty() {return root==NULL;};
    void Clear();
    bool Root(T &x) ;
    void MakeTree(const T& x,BinaryTree<T>& left,BinaryTree<T>& right);
    void BreakTree(T& x,BinaryTree<T>& left,BinaryTree<T>& right);
    void Traversal();
    void Visit(T& x);
    void Delete();
    int High();
    int Size();
    BTNode<T>* Copy(BTNode<T>* t);
    void Exchange(BTNode<T>* t);
    BTNode<T> *root;
    SeqQueue<BTNode<T>*> que;
private:
    int high=0;
    void Clear(BTNode<T>* &t);
    int High(BTNode<T> *t,int h);
    void Delete(BTNode<T> *t);
    int Size(BTNode<T> *t);
    void Traversal(BTNode<T> *t) ;
};
template <class T>
bool BinaryTree<T>::Root(T &x)
{
    if(root)
    {
        x=root->element;
        return true;
    }
    else
        return false;
}
template <class T>
void BinaryTree<T>::MakeTree(const T& x,BinaryTree<T>& left,BinaryTree<T>& right)
{
    if(root || &right == &left)
        return ;
    root=new BTNode<T>(x,left.root,right.root);
    left.root=right.root=NULL;
}
template <class T>
void BinaryTree<T>::BreakTree(T& x,BinaryTree<T>& left,BinaryTree<T>& right)
{
    if(!root || &left==&right || right.root || left.root)
        return;
    x=root->element;
    left.root=root->lchild;
    right.root=root->rchild;
    delete root ;
    root=NULL;
}
template <class T>
void BinaryTree<T>::Visit(T& x)
{
    cout<<x<<" ";
}
template <class T>
void BinaryTree<T>::Traversal()
{
    Traversal(root);

}

template <class T>
void BinaryTree<T>::Traversal(BTNode<T> *t)
{


    if(t)
    {
        Visit(t->element);
        if(t->lchild)
            que.EnQueue(t->lchild);
        if(t->rchild)
            que.EnQueue(t->rchild);
        if(que.IsEmpty())
            return ;
        BTNode<T> *temp;
        que.Front(temp);
        que.DeQueue();
        Traversal(temp);

    }
}
template <class T>
BTNode<T>* BinaryTree<T>::Copy(BTNode<T> *t)
{
    if(!t)
        return NULL;
    BTNode<T>* q=new BTNode<T>(t->element);
    q->lchild=Copy(t->lchild);
    q->rchild=Copy(t->rchild);
    return q;
}
template <class T>
void BinaryTree<T>::Exchange(BTNode<T> *t)
{
    BTNode<T> *temp;
    if(t->rchild ==NULL && t->lchild==NULL)
        return ;
    else
    {
        temp=t->lchild;
        t->lchild=t->rchild;
        t->rchild=temp;
    }
    Exchange(t->lchild);
    Exchange(t->rchild);
}
template <class T>
int BinaryTree<T>::Size()
{
    return Size(root);
}
template <class T>
int BinaryTree<T>::Size(BTNode<T> *t)
{
    if(t->lchild==NULL && t->rchild==NULL)
        return 1;
    if((t->lchild==NULL && t->rchild!=NULL) || (t->rchild==NULL && t->lchild!=NULL))
        return 0;
    return Size(t->lchild)+Size(t->rchild);
}
template <class T>
void BinaryTree<T>::Delete()
{
    Delete(root);
    root=NULL;
}
template <class T>
void BinaryTree<T>::Delete(BTNode<T> *root)
{
    if(root==NULL)
        return ;
    if(root->lchild)
        Delete(root->lchild);
    if(root->rchild)
        Delete(root->rchild);
    delete root;
}
template <class T>
int BinaryTree<T>::High()
{
    High(root,1);
}
template <class T>
int  BinaryTree<T>::High(BTNode<T> *t,int h)
{
    if(t)
    {
        if(t->lchild)
            High(t->lchild,h++);
        if(t->rchild)
            High(t->lchild,h++);
    }
    if(h>high)
        high=h;
    return high;
}
