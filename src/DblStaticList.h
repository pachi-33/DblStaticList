#pragma once
#include "Assistance.h"
#include "Node.h"

template <class ElemType>
class dblStaticList
{
private:
    int head;
    int length;
    int maxLen;
    int avail;
    Node<ElemType> &pool[];
public:
    int getLen();
    void Traverse(void (*Visit)(const ElemType &e))const;
    Status malloc_list(int &tar);
    Status InsElem(const ElemType &e);
    dblStaticList(ElemType *_pool,int _TotalSize);
    ~dblStaticList();
};

template <class ElemType>
dblStaticList<ElemType>::dblStaticList(ElemType &_pool[],int _TotalSize):pool(_pool),maxLen(_TotalSize-1)
{
   this->avail=1;
   this->head=0;
   this->length=0;
}

template <class ElemType>
dblStaticList<ElemType>::~dblStaticList()
{
}

template <class ElemType>
int dblStaticList<ElemType>::getLen()
{
    return length;
}

template <class ElemType>
void dblStaticList<ElemType>::Traverse(void (*Visit)(const ElemType &e))const
{
    for(int it=this->head;it!=head;it=pool[it].next)
    {
        Visit(pool[it].data);
    }
}

template <class ElemType>
Status dblStaticList<ElemType>::InsElem(const ElemType &e)
{
    int it=pool[this->head].prior;
    pool[avail]=Node<ElemType>(e,it,pool[it].next);

    return SUCCESS;
}

