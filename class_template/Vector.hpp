#pragma once 
#include <iostream>
#include <assert.h>
#include <cstring>
template<class T>
class Vector
{
public:
  typedef T* iterator;
  typedef const T* const_iterator;
  
  Vector()
  :_start(nullptr)
  ,_finsh(nullptr)
  ,_end_of_storage(nullptr)
  {

  }
  
  ~Vector()
  {
    if(_start)
    {
      delete[] _start;
      _start = _finsh = _end_of_storage = nullptr;
    }
  }

  iterator begin()
  {
    return _start;
  }

  iterator end()
  {
    return _finsh;
  }
  const_iterator begin() const 
  {
    return _start;
  }

  const_iterator end() const 
  {
    return _finsh;
  }
  Vector(const Vector<T>& v)
  :_start(nullptr)
  ,_finsh(nullptr)
  ,_end_of_storage(nullptr)
  {
    Reserve(v.Size()); 
    for(size_t i = 0;i < v.Size();i++)
    {
      this->PushBack(v[i]);
    }
  }
  
  void Reserve(size_t n)
  {
    if(n > Capacity())
    {
      size_t size = Size();
      //开新空间
      T* newarray = new T[n];
      if(_start)
      {
        memcpy(newarray,_start,sizeof(T)*Size());
      }
      //释放旧空间
      delete[] _start; 
      _start = newarray;
      _finsh = _start + size;
      _end_of_storage = _start + n;
    }
  }
  
  void Resize(size_t n,const T& val = T())//Resize也是扩容的一种，但是会将其都初始化
  {
    if(n <= Size())
    {
      _finsh = _start + n;
    }
    else 
    {
      Reserve(n);
      while(_finsh != _start + n)
      {
        *_finsh = val;
        ++_finsh;
      }
    }
  }

  void Swap(Vector<T>& x)
  {
    std::swap(_start,x._start);
    std::swap(_finsh,x._finsh);
    std::swap(_end_of_storage,x._end_of_storage);
  }
  
  Vector<T>& operator=(Vector<T> v)
  {
    this->Swap(v);
    return *this;
  }

  T& operator[](size_t pos)
  {
    assert(pos < Size());
    return _start[pos];
  }

  const T& operator[](size_t pos) const 
  {
    assert(pos < Size());
    return _start[pos];
  }

  void PushBack(const T& x)
  {
    if(_finsh == _end_of_storage)
    {
      size_t newcapacity = Capacity() == 0 ? 4 : Capacity() * 2;
      Reserve(newcapacity);
    }
    *_finsh = x;
    ++_finsh;
  }

  void PopBack()
  {
    assert(_finsh > _start);
    --_finsh;
  }

  void Insert(iterator pos,const T& x)
  {
    assert(pos < _finsh);
    if(_finsh == _end_of_storage)
    {
      size_t n = pos - _start;
      size_t newcapacity = Capacity() == 0 ? 4 : Capacity() * 2;
      Reserve(newcapacity);
      pos = _start + n;
    }
    iterator end = _finsh - 1;
    while(end >= pos)
    {
      *(end + 1) = *end;
      --end;
    }
    *pos = x;
    _finsh++;
  }

  iterator Erase(iterator pos)
  {
    assert(pos < _finsh);
    iterator it = pos;
    while(it < _finsh)
    {
      *it = *(it + 1);
      it++;
    }

    --_finsh;

    return pos;
  }

  size_t Size()const
  {
    return _finsh - _start;
  }
  
  size_t Capacity()const
  {
    return _end_of_storage - _start;
  }

private:
  iterator _start;//使用空间的开始
  iterator _finsh;//使用空间的尾
  iterator _end_of_storage;//表示可用空间的尾
};
