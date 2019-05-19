#include <iostream>
#include <assert.h>
typedef int DateType;
class SeqList
{
public:
  SeqList(int capacity = 10){
    _pData = (DateType*)malloc(capacity * sizeof(DateType));
    assert(_pData);
    _size = 0;
    _capacity = capacity;
  }
  ~SeqList()
  {
    if(_pData)
    {
      free(_pData);
      _pData = NULL;
      _size = 0;
      _capacity = 0;
    }
  }
private:
  int* _pData;
  size_t _size;
  size_t _capacity;
};
