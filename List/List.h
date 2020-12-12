#pragma once

#include "ListElem.h"
#include <vector>

template <class T2>
class ListIterator;

template <class T>
class TList
{
protected:
  TListElem<T>* root;
  TListElem<T>* end;
  int count;
public:
  TList();
  TList(TList<T>& _v);
  ~TList();

  TList<T>& operator =(TList<T>& _v);

  void InsFirst(T d);
  void InsLast(T d);
  void Ins(TListElem<T>* e, T d);

  bool IsEmpty(void) const;

  bool IsFull(void) const;

  TListElem<T>* GetFirst();
  TListElem<T>* GetLast();

  int GetCount();
  void DelFirst();
  void DelLast();
  void Del(TListElem<T>* e);

  template <class T1>
  friend ostream& operator<<(ostream& ostr, const TList<T1>& L);
  template <class T1>
  friend istream& operator>>(istream& istr, TList<T1>& L);

  //��� �������

  vector<int> ElemsModKEqualsZero(int k);
  void WriteToFile(string name);
  template <class T1>
  friend ofstream& operator<<(ofstream& ofstr, const TList<T1>& L);
};

template<class T>
inline TList<T>::TList()
{
  root = 0;
  end = 0;
  count = 0;
}

template <class T>
TList<T>::TList(TList<T>& _v)
{
  count = _v.count;

  TListElem<T>* i = _v.root;
  TListElem<T>* j = this->root;
  TListElem<T>* p = 0;

  while (i != 0)
  {
    j = new TListElem<T>(*i);
    j->SetNext(0);
    if (p != 0)
    {
      p->SetNext(j);
      j->SetPrev(p);
    }

    p = j;

    if (root == 0)
      root = j;

    end = j;

    i = i->next();
  }
}

template <class T>
TList<T>::~TList()
{
  if (this->root != 0)
  {
    TListElem<T>* i = this->root;
    TListElem<T>* p = 0;

    while (i != 0)
    {
      p = i;
      i = i->GetNext();
      delete p;
    }

    this->root = 0;
    this->end = 0;
    count = 0;
  }
}

template <class T>
TList<T>& TList<T>::operator=(TList<T>& _v)
{
  if (this == &_v)
    return *this;

  this->~TList();
  this->TList(_v);
}

template<class T>
inline void TList<T>::InsFirst(T d)
{
  TListElem<T>* tmp = new TListElem<T>(d);
  tmp->SetNext(root);
  root = tmp;
  if (end == 0)
    end = tmp;
  count++;
}

template<class T>
inline void TList<T>::InsLast(T d)
{
  TListElem<T>* tmp = new TListElem<T>(d);
  if (end != 0)
  {
    end->SetNext(tmp);
    tmp->SetPrev(end);
  }
  end = tmp;
  if (root == 0)
    root = tmp;
  count++;
}

template<class T>
inline void TList<T>::Ins(TListElem<T>* e, T d)
{
  TListElem<T>* tmp = new TListElem<T>(d);
  tmp->SetNext(e->GetNext());
  tmp->SetPrev(e);
  if (e->GetNext() != 0)
    e->GetNext()->SetPrev(tmp);
  else
    end = tmp;
  e->SetNext(tmp);
  count++;
}

template<class T>
inline bool TList<T>::IsEmpty(void) const
{
  return count == 0;
}

template<class T>
inline bool TList<T>::IsFull(void) const
{
  try
  {
    TListElem<T>* tmp = new TListElem<T>(0);
    delete tmp;
    return false;
  }
  catch (...)
  {
    return true;
  }
}

template<class T>
inline TListElem<T>* TList<T>::GetFirst()
{
  return root;
}

template<class T>
inline TListElem<T>* TList<T>::GetLast()
{
  return end;
}

template<class T>
inline void TList<T>::DelFirst()
{
  TListElem<T>* i = root;
  root = root->GetNext();
  count--;
  delete i;
}

template<class T>
inline void TList<T>::DelLast()
{
  TListElem<T>* i = end;
  end = end->GetPrev();
  end->SetNext(0);
  count--;
  delete i;
}

template<class T>
inline void TList<T>::Del(TListElem<T>* e)
{
  e->GetPrev()->SetNext(e->GetNext());
  e->GetNext()->SetPrev(e->GetPrev());

  count--;
  delete e;
}

template<class T>
inline int TList<T>::GetCount()
{
  return count;
}

template <class T1>
ostream& operator<<(ostream& ostr, const TList<T1>& L) {

  TListElem<T1>* i = L.root;
  while (i != 0)
  {
    ostr << *i << endl;
    i = i->GetNext();
  }
  return ostr;
}

template <class T1>
istream& operator>>(istream& istr, TList<T1>& L) {
  int count;
  istr >> count;
  for (int i = 0; i < count; i++)
  {
    T1 d;
    istr >> d;
    L.InsLast(d);
  }
  return istr;
}

//��� �������

template<class T>
vector<int> TList<T>::ElemsModKEqualsZero(int k)
{
  if (this->root == 0)
    throw new std::exception();
  TListElem<T>* elem = this->root;
  vector<int> res;
  while (elem != 0)
  {
    if (elem->GetData() % k == 0)
      res.push_back(elem->GetData());
    elem = elem->GetNext();
  }
  return res;
}

template<class T>
inline void TList<T>::WriteToFile(string name)
{
  ofstream fout(name.c_str());
  fout << *this;
  fout.close();
}

template<class T1>
inline ofstream& operator<<(ofstream& ofstr, const TList<T1>& L)
{
  TListElem<T1>* i = L.root;
  while (i != 0)
  {
    ofstr << *i;
    i = i->GetNext();
  }
  return ofstr;
}

template <class T2>
class ListIterator
{
private:
  TListElem<T2>* cur;
public:
  ListIterator(TListElem<T2>* itr)
  {
    cur = itr;
  }
  void operator++()
  {
    cur = cur->GetNext();
  }
  void operator--()
  {
    cur = cur->GetPrev();
  }
  bool empty()
  {
    return cur == 0;
  }
  TListElem<T2>* elem()
  {
    return cur;
  }
  T2 operator*()
  {
    return cur->GetData();
  }
};