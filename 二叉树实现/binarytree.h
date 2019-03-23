#include "btnode.h"
#include <iostream>
using namespace std;
template<class T>
class BinaryTree
{
public:
    BinaryTree(){root=NULL;}
    ~BinaryTree(){}
    bool IsEmpty()const;
    void Clear();
    bool Root(T& x)const;
    void MakeTree(const T& x,BinaryTree<T>& left,BinaryTree<T>& right);
    void BreakTree(T& x,BinaryTree<T>& left,BinaryTree<T>& right);
    void PreOrder();
    void InOrder();
    void PostOrder();
    int Size1(BTNode<T> *t);
    void Exchange(BTNode<T>* t);
    void Delete(BinaryTree<T> t);
    BTNode<T>* root;
private:
     void Delete(BTNode<T> *t);
    void Clear(BTNode<T>* &t);
    void PreOrder(BTNode<T>*t);
    void InOrder(BTNode<T>*t);
    void PostOrder(BTNode<T>*t);
};
template<class T>
bool BinaryTree<T>::Root(T& x)const
{
    if(root)
    {
        x=root->element;
        return true;
    }
    else
        return false;
}
template<class T>
void BinaryTree<T>::MakeTree(const T& x,BinaryTree<T>& left,BinaryTree<T>& right)
{
    if(root||&left==&right)
        return ;
    root=new BTNode<T>(x,left.root,right.root);
    left.root=right.root=NULL;
}
template<class T>
void BinaryTree<T>::BreakTree(T& x,BinaryTree<T>& left,BinaryTree<T>& right)
{
    if(!root||&left==&right||right.root||left.root)
        return ;
    x=root->element;
    left.root=root->lchild;
    right.root=root->rchild;
    delete root;
    root=NULL;
}
template<class T>
void Visit(T& x)
{
    cout<<x<<" ";
}
template<class T>
void BinaryTree<T>::PreOrder()
{
    PreOrder(root);
}
template<class T>
void BinaryTree<T>::PreOrder(BTNode<T> *t)
{
    if(t)
    {
        Visit(t->element);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}
template <class T>
void BinaryTree<T>::Exchange(BTNode<T> *t)
{
     BTNode<T> *temp = NULL;
     if(t->lchild == NULL && t->rchild == NULL)
            return;
     else{
           temp = t->lchild;
           t->lchild = t->rchild;
           t->rchild = temp;
     }
     if(t->lchild)
          Exchange(t->lchild);
     if(t->rchild)
          Exchange(t->rchild);
}
template <class T>
int BinaryTree<T>::Size1(BTNode<T>* t)
{
    if(t==NULL)
        return 0;
    if((t->lchild==NULL&&t->rchild!=NULL) || (t->lchild!=NULL&&t->rchild==NULL))
    {
        return 1;
    }
    return Size1(t->lchild)+Size1(t->rchild);
}
template <class T>
void BinaryTree<T>::Delete(BinaryTree<T> t)
{
    Delete(t.root);
}
template <class T>
void BinaryTree<T>::Delete(BTNode<T> *t)
{
    if(t==NULL)
        return ;
    Delete(t->rchild);
    Delete(t->lchild);
    delete t;
    t=NULL;
    return;
}
