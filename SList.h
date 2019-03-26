#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SDListTypeData;

typedef struct Node{
  SDListTypeData value;
  struct Node *next;
}Node;

typedef struct Slist{
  Node *first;
}Slist;


void SListInit(Slist *s){
  s->first = NULL;
}
//头插
void SListPushFront(Slist *s, SDListTypeData v){
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = v;

  //更改链表的关系
  node->next = s->first;
  s->first = node;
}

void SListPushBack(Slist *s, SDListTypeData v){
  assert(s->first != NULL);
  Node *node = (Node*)malloc(sizeof(Node));
  node->value = v;

  if(s->first == NULL){
    s->first = node;
  }
  else{
    //找到链表的最后一个结点
    Node* c = s->first;
    while(c->next != NULL){
      c = c->next;
    }
    c->next = node;
  }
}

void SListPopFront(Slist *s){
  assert(s->first != NULL);
  if(s->first->next == NULL){
    s->first = NULL;
  }
  else{
    Node* second = s->first->next;
    free(s->first);
    s->first = second;
  }
}

void SListPopBack(Slist *s){
  assert(s->first != NULL);

  if(s->first->next == NULL){
    free(s->first);
    s->first = NULL;
    return;
  }
  else{
    //找到倒数第二个结点
    Node *c;
    for(c = s->first; c->next->next != NULL;c = c->next);
    free(c->next);//释放最后一个结点的地址
    c->next = NULL;
  }
}
//在链表中间某个位置之后插入
void SlistInsertAfter(Slist *s,Node *pos,SDListTypeData v){
  Node *node = (Node*)malloc(sizeof(Node));
  node->value = v;
  node->next = pos->next;
  pos->next = node;
}

void SListEarseAfter(Slist *s,Node *pos){
  Node *next = pos->next->next;
  free(pos->next);
  pos->next = next;
}

//删除遇到的第一个结点数
void SListRemove(Slist *s, SDListTypeData v){
  if(s->first == NULL){
    return;
  }
  if(s->first->value == v){
    Node *second = s->first->next;
    free(s->first);
    s->first = second;
  }
  else{
    Node *c = s->first;
    while(c->next != NULL){
      if(c->next->value == v){
        Node *next = c->next; //先将头结点的后一个结点设为next
        c->next = c->next->next;//这时候将头结点的后二个结点next转换为头结点的后一个结点
        free(next);//释放掉后一个结点
        return;
      }
      c = c->next;//将头结点的后一个结点当作头结点继续循环
    }
  }
}

void SListRemoveAll(Slist *s,SDListTypeData v){
  if(s->first == NULL){
    return;
  }
  Node *c = s->first;
  while(c->next != NULL){
    if(c->next->value == v){
      Node *next = c->next;
      c->next = c->next->next;
      free(next);
    }
    else{
      c = c->next;
    }
  }
  //除了第一个没有检查过
  if(s->first->value == v){
    //头删
    Node *next = s->first;
    s->first = s->first->next;
    free(next);
  }
}

struct Node*  SListReverse(struct Node *s){
  //定义三个指针
  struct Node *result = NULL;
  struct Node *c = s;
  
  while(c != NULL){
    Node *next = c->next;

    c->next = result;
    result = c;

    c = next;

  }

  return result;
  
}
