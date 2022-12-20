#pragma once
#include "TStack.h"

template<class T>
class TQueue : public TStack<T>{
protected:
  int low;
  int CircleBuffer();
public:

  TQueue(int size = MAXMEMSIZE) : TStack(size) { low = 0; };
  TQueue(const TQueue<T>& st);
  T Pop();
  void Put(const T& value);
  T Low();
};

template<class T>
inline TQueue<T>::TQueue(const TQueue<T>& st)
{
  low = st.low;
  memSize = st.memSize;
  copy(st.pMem, st.pMem + memSize, pMem);
}

template<class T>
inline T TQueue<T>::Pop() {
  if (IsEmpty())
  {
    throw exception("Queue is empty");
  }
  dataCount--;

  if (CircleBuffer()) {
    return pMem[memSize];
  }

  return pMem[low++];
}

template<class T>
inline void TQueue<T>::Put(const T& value)
{
  CircleBuffer();
  pMem[++top] = value;
  dataCount++;
}

template<class T>
inline T TQueue<T>::Low()
{
  return pMem[low];
}

template<class T>
inline int TQueue<T>::CircleBuffer() {
  int flag = 0;
  if (low == memSize) {
    low = 0;
    flag = 1;
  }
  if (top == memSize) {
    top = -1;
    flag = 1;
  }
  if (dataCount > memSize) {
    dataCount = memSize;
  }
  return flag;

}