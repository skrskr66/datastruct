#pragma once
#include <iostream>

template<class T>
struct ListNode
{
  ListNode<T>* _next;
  ListNode<T>* _prev;
  T _data;

  ListNode(const T& x = T())
    :_next(nullptr)
    ,_prev(nullptr)
    ,_data(x)
  {}
};

// typedef __ListIterator<T, T&, T*> iterator;
// typedef __ListIterator<T, const T&, const T*> const_iterator;
template<class T,class Ref,class Ptr>
struct __ListIterator
{
  typedef ListNode<T> Node;
  typedef __ListIterator<T,Ref,Ptr> Self;
  Node* _node; 

  __ListIterator(Node* node)
    :_node(node)
  {

  }
  Ref operator*()
  {
    return _node->_data;
  }

  Ptr operator->()
  {
    return &_node->_data;
  }

  Self& operator++()
  {
    _node = _node->_next;
    return *this;
  }

  Self operator++(int)
  {
    Self tmp(*this);
    _node = _node->_next;
    return tmp;
  }
  Self& operator--()
  {
    _node = _node->_prev;
    return *this;
  }
  bool operator!= (const Self& it)
  {
    return _node != it._node;
  }
  bool operator==(const Self& it)
  {
    return _node == it._node;
  }
};

template<class T>
class List 
{
  typedef ListNode<T> Node;
public:
  typedef __ListIterator<T,T&,T*> iterator;
  typedef __ListIterator<T,const T&,const T*> const_iterator;

  List()
    :_head(new Node)
  {
    _head->_next = _head;
    _head->_prev = _head;
  }
  iterator begin()
  {
    return _head->_next;
  }
  iterator end()
  {
    return iterator(_head);
  }
  const_iterator begin()const
  {
    return const_iterator(_head->_next);
  }
  const_iterator end()const
  {
    return _head;  
  }
  void PushBack(const T& x)
  {
    Node *tail = _head->_prev;//此时是将最后头节点的前置节点记录下来，其实也就是最后一个节点记录
    Node* newnode = new Node(x);

    tail->_next = newnode;
    newnode->_prev = tail;

    newnode->_next = _head; 
    _head->_prev = newnode;
  }
private:
  Node* _head;
};
