#ifndef INC_30_DATA_STRUCTURES_CPP_ORDEREDLINKEDLIST_H
#define INC_30_DATA_STRUCTURES_CPP_ORDEREDLINKEDLIST_H

#include <iostream>

template<class AnyObject>
struct ListNode {
  AnyObject data;
  ListNode *next;
};

template<class AnyObject>
class ForwardIterator : std::iterator<std::forward_iterator_tag, AnyObject> {
  typedef ListNode<AnyObject> Node;

 private:
  Node *current;

 public:
  ForwardIterator(Node *init) : current(init) {};

  /* Operators overload */
  bool operator!=(const ForwardIterator &toCompare) {
    return this->current != toCompare.current;
  }

  ForwardIterator &operator++(int _increment) {
    this->current = this->current->next;
    return *this;
  }

  AnyObject operator*() const {
    return this->current->data;
  }
};

template<class AnyObject>
class OrderedLinkedList {
  typedef ListNode<AnyObject> Node;

 private:
  Node *head;

 public:
  OrderedLinkedList() : head(nullptr) {}

  bool find(AnyObject data, Node **&pointer);

  void insert(AnyObject data);

  void remove(AnyObject data);

  void reverse();

  bool empty();

  void print();

  // Iterator functions
  ForwardIterator<AnyObject> begin();

  ForwardIterator<AnyObject> end();
};

#endif //INC_30_DATA_STRUCTURES_CPP_ORDEREDLINKEDLIST_H
