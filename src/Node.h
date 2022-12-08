#pragma once

template <class ElemType>
class Node
{
public:
    int prior;
    ElemType data;
    int next;
    bool isEmpty;
    Node();
    Node(ElemType& e,
        int _prior,
        int _next);
};

template<class ElemType>
Node<ElemType>::Node() :isEmpty(true)
{
    this->next = -1;
    this->prior = -1;
}

template<class ElemType>
Node<ElemType>::Node(ElemType& e, int _prior, int _next) :prior(_prior), next(_next)
{
    this->data = e;
}

