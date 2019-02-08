#ifndef INC_30_DATA_STRUCTURES_CPP_ORDEREDLINKEDLIST_H
#define INC_30_DATA_STRUCTURES_CPP_ORDEREDLINKEDLIST_H

#include <iostream>

namespace DataStructures {

template<class AnyObject>
class OrderedLinkedList {
  struct Node {
    AnyObject data;
    Node *next;
  };

  Node *head;

 public:
  OrderedLinkedList() : head(nullptr) {}

  bool find(AnyObject data, Node **&pointer);

  void insert(AnyObject data);

  void remove(AnyObject data);

  void reverse();

  bool empty();

  void print();
};
}

#endif //INC_30_DATA_STRUCTURES_CPP_ORDEREDLINKEDLIST_H
