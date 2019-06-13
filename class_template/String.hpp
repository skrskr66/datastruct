#include <iostream>
#include <assert.h>
#include <string.h>
class String
{
public:
  typedef char* iterator;   
  typedef const char* const_iterator;

  String(const char* str = "")//构造函数
    :_str(nullptr)
    ,_capacity(0)
  {
    _size = strlen(_str);
    Reserve(_size);
    strcpy(_str,str);
  }
  //s(s1)
  String(const String& s)//拷贝构造
    :_str(nullptr)
    ,_size(0)
    ,_capacity(0)
  {
    String tmp(s._str);
    Swap(tmp);//tmp.Swap(*this)
  }
  ~String()//析构函数
  {
   if(_str)
   {
     delete[] _str;
     _str = nullptr;
     _size = _capacity = 0;
   }
  }
  
  const_iterator begin()const 
  {
    return _str;
  }
  const_iterator end()const 
  {
    return _str + _size;
  }
  iterator begin()
  {
    return _str;
  }
  iterator end()
  {
    return _str+_size;
  }
  void Swap(String& s)
  {
    std::swap(_str,s._str);
    std::swap(_size,s._size);
    std::swap(_capacity,s._capacity);
  }
  void Reserve(size_t n)//增容,开辟空间
  {
    if(n == 0 || n > _capacity)
    {
      size_t newsize = n;
      if(n % 8 != 0)
      {
        newsize = (n / 8 + 1) * 8;
      }
      else
      {
        newsize = n + 8;
      }

      char* newstr = new char[newsize];
      if(_str)
      {
        strcpy(newstr,_str);
      }
      _str = newstr;
      _capacity = newsize - 1;
    }
  }
  void Resize(size_t n,char ch = '\0')//设置大小，我们可以理解为字符串的大小
  {
    if(n <= _size)
    {
      _size = n;
      _str[_size] = '\0';
    }
    else
    {
      Reserve(n);
      for(size_t i = 0;i < n;i++)
      {
        _str[i] = ch;
        ++_size;
      }
      _str[_size] = '\0';
    }
  }
  size_t Capacity() const//容量
  {
    return _capacity;
  }
  size_t Size() const//字符串当前大小
  {
    return _size;
  }
  char* c_str() const //返回字符串
  {
    return _str;
  }
  char& operator[](size_t pos)//返回字符串中pos位置的字符
  {
    assert(pos < _size);
    return _str[pos];
  }
  const char& operator[](size_t pos)const //同上，不过是const，只读形式
  {
    assert(pos < _size);
    return _str[pos];
  }
  void Append(const char* str)//添加字符
  {
    //size_t len = strlen(str);
    //if(_size + len > _capacity)
    //{
    //  Reverse(_size + len);
    //}
    //strcpy(_str + _size,str);//这里_str+_size,是要为str提前将空间部署好，之后复制str将_size的空间直接覆盖
    //_size += len;
    Insert(_size,str); 
  }
  void PushBack(const char str)//尾插
  {
    if(_size == _capacity)
    {
      Reserve(_capacity * 2);
    }
    _str[_size] = str;
    ++_size;
    _str[_size] = '\0';
  }
  //Insert(1,'d');
  void Insert(size_t pos,char ch)//插入数据，直接插入一大段在某一位置上
  {
    assert(pos < _size);
    if(_size == _capacity)
    {
      Reserve(_capacity * 2);
    }
    for(int i = _size;i >= (int)pos;--i)
    {
      _str[i + 1] = _str[i];
    }
    _str[pos] = ch;
    _size++;
  }
  //Insert(1,"asdf");
  void Insert(size_t pos,const char* str)//插入数据，将这一段数据，分别插在某一段位置上，
  {
    size_t len = strlen(str);
    if(len + _size > _capacity)
    {
      Reserve(len + _size);
    }
    int end = _size;
    while(end >= (int)pos)
    {
      _str[end + len] = _str[end];
      --end;
    }
    strncpy(_str+pos,str,len);
    _size += len;
  }
  void Earse(size_t pos = 0,size_t len = npos)//删除字符串
  {
    if(pos + len >= _size)//说明将pos之后全部删除
    {
      _size = pos;
      _str[_size] = '\0';
    }
    else 
    {
      size_t start = pos + len;
      strcpy(_str + pos, _str + start);//因为 _str+pos 的意思就是将指针移到这个字符数组的pos位置 
                                        //再往后面 复制字符,_str+pos+len就将_str+_pos的字符串处覆盖了
      _size -= len;
    }
  }
  size_t Find(char ch,size_t pos = 0)
  {
    for(size_t i = pos;i < _size;i++)
    {
      if(_str[i] == ch)
      {
        return i;
      }
    }
    return npos;
  }
  size_t Find(const char* ch,size_t pos = 0)
  {
    const char* ret = strstr(_str + pos,ch);
    if(ret == nullptr)
    {
      return npos; 
    }
    else 
    {
      return ret - _str;
    }
  }


  bool operator<(const String& s)const 
  {
    size_t i = 0;
    size_t j = 0;
    while(i < _size && j < s._size )
    {
      if(_str[i] < s[j])
      {
        return true;
      }
      else if(_str[i] > s[j])
      {
        return false;
      }
      else 
      {
        ++i;
        ++j;
      }
    }
    if(j < s._size)
    {
      return true;
    }
    else 
    {
      return false;
    }
  }
  bool operator==(const String& s)const 
  {
    size_t i = 0;
    size_t j = 0;
    while(i < _size && j < s._size)
    {
      if(_str[i] != s[j])
      {
        return false;
      }
      else 
      {
        ++i;
        ++j;
      }
    }
    if(i == _size && j == s._size)
    {
      return true;
    }
    else 
    {
      return false;
    }
  }
  bool operator!=(const String& s)const 
  {
    return !(*this == s);
  }
  bool operator<=(const String& s)const
  {
    return *this < s || *this == s;
  }
  bool operator>=(const String& s)const
  {
    return !(*this < s);
  }
  bool operator>(const String& s)const
  {
    return !(*this <= s);
  }


  String& operator+=(char ch)//加等，向字符串的末尾进行添加
  {
    PushBack(ch);
    return *this;
  }
  String operator+=(const char* str)//加等，向字符串的末尾进行添加，不可修改
  {
    Append(str);
    return *this;
  }
  String& operator+(const char* str)
  {
    String tmp(*this);
    tmp.Append(str);
    return tmp;
  }
  String operator+(char ch)const 
  {
    String tmp(*this);
    tmp.PushBack(ch);
    return tmp;
  }


private:
  char* _str;
  size_t _size;
  size_t _capacity;

  static size_t npos;
};

size_t String::npos = -1;

