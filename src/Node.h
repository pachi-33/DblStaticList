#pragma once

template <class ElemType>
class Node
{
protected:
    int prior;
    ElemType data;
    int next;
public:
    Node();
    Node(ElemType &e,
    int _prior,
    int _next);
};

template<class ElemType>
Node<ElemType>::Node()
{
    this->next=-1;
    this->prior=-1;
}

template<class ElemType>
Node<ElemType>::Node(ElemType &e,int _prior,int _next):prior(_prior),next(_next)
{
    this->data=e;
}
