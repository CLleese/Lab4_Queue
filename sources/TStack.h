#pragma once
#include <iostream>
using namespace std;

const int MAXMEMSIZE = 25;

template<class T>
class TStack {
protected:
  T *pMem;
  int memSize, dataCount, top;

public:
  TStack(int size = MAXMEMSIZE);
  TStack(const TStack<T>& st);

  ~TStack();
 
  bool IsEmpty();
  bool IsFull();
  
  T Pop();
  void Put(const T& value);
 
};

template<class T>
inline TStack<T>::TStack(int size = MAXMEMSIZE)
{
  if (size < 0)
  {
    throw exception();
  }
  memSize = size;
  top = -1;
  dataCount = 0;
  
  pMem = new T[memSize];
}

template<class T>
inline TStack<T>::TStack(const TStack<T>& st)
{
  top = st.top;
  memSize = st.memSize;
  copy(st.pMem, st.pMem + memSize, pMem);
}

template<class T>
inline TStack<T>::~TStack()
{
  pMem = nullptr;
  delete[] pMem;
}

template<class T>
inline bool TStack<T>::IsEmpty()
{
  return dataCount == 0;
}

template<class T>
inline bool TStack<T>::IsFull()
{
  return dataCount == memSize;
}  

template<class T>
inline T TStack<T>::Pop()
{
  if (IsEmpty())
  {
    throw exception("Stack is empty");
  }
  dataCount--;
  return pMem[top--];
}

template<class T>
inline void TStack<T>::Put(const T& value)
{
  pMem[++top] = value;
  dataCount++;
}
