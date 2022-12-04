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
    Node<ElemType>* sll;
public:
    int malloc_sll();
    Status free_sll(const int i);
    Status InsertElem(const ElemType &e);
    int getLen();
    bool isEmpty();
    void Clear();
    void Traverse(void (*Visit)(const ElemType &e))const;
    dblStaticList(int _TotalSize);
    ~dblStaticList();
};

template <class ElemType>
int dblStaticList<ElemType>::malloc_sll()
{
    if(sll==nullptr||avail==-1){
        return -1;
    }else{
        int tmp=avail;
        sll[avail].isEmpty=false;
        avail=sll[avail].next;
        return tmp;
    }
}

template <class ElemType>
Status dblStaticList<ElemType>::free_sll(const int i)
{
    if(sll[i].isEmpty)
    {
        return Status::RANGE_ERROR;
    }
    sll[i].next=avail;
    avail=i;
    sll[avail].isEmpty=true;
    return SUCCESS;
}

template <class ElemType>
dblStaticList<ElemType>::dblStaticList(int _TotalSize):maxLen(_TotalSize)
{
    this->avail=1;
    this->head=0;
    sll[head].next=head;
    sll[head].prior=head;
    this->length=0;

    if(sll!=nullptr){
        sll=new Node<ElemType>[_TotalSize+1];
        for(int it=0;it<_TotalSize;it++)
        {
            sll[it].next=it+1;
        }
        sll[_TotalSize].next=-1;
    } 
}

template <class ElemType>
dblStaticList<ElemType>::~dblStaticList()
{
    delete[] sll;
}

template <class ElemType>
int dblStaticList<ElemType>::getLen()
{
    return length;
}

template <class ElemType>
void dblStaticList<ElemType>::Traverse(void (*Visit)(const ElemType &e))const
{
    for(int it=sll[this->head].next;it!=head;it=sll[it].next)
    {
        (*Visit)(sll[it].data);
    }
}

template <class ElemType>
void dblStaticList<ElemType>::Clear()
{
    int p=sll[head].next;
    Status sta=SUCCESS;
    while(sta==SUCCESS)
    {
        sta=free_sll(p);
    }
    this->avail=1;
    this->head=0;
    sll[head].next=head;
    sll[head].prior=head;
    this->length=0;
}

template <class ElemType>
bool dblStaticList<ElemType>::isEmpty()
{
    return sll[sll[head].next].isEmpty;
}

template <class ElemType>
Status dblStaticList<ElemType>::InsertElem(const ElemType &e)
{
    int p;
	for (p = sll[head].next; p != head; p = sll[p].next){
		if(sll[p].data>e){
			break;
		}
	}
	int _pNode=malloc_sll();
    sll[_pNode].data=e;
    sll[_pNode].prior=sll[p].prior;
    sll[_pNode].next=p;
    
	sll[sll[p].prior].next=_pNode;
	sll[p].prior=_pNode;
	length++;						
	return SUCCESS;
}



