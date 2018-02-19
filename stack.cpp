//This code is created by rohit
#include<iostream>

template <typename T>
class stack{
  T *ptr;
  int size;
  int top;
public:
  stack(int size)
  {
    ptr = new T[size];
    for(int i = 0 ; i< size ;i++)
        T[i] = 0;
  }
};
