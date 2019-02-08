#include "OrderedLinkedList.h"

using namespace DataStructures;

/**
 * Check if the data exists in the ordered linked list
 *
 * @tparam AnyObject
 * @param data
 * @param pointer
 * @return bool
 */
template<class AnyObject>
bool OrderedLinkedList<AnyObject>::find(AnyObject data, OrderedLinkedList<AnyObject>::Node **&pointer) {
  // If necessary, operators should to be override in AnyObject.
  while ((*pointer) && (*pointer)->data <= data) {
    if ((*pointer)->data == data) {
      return true;
    }

    pointer = &((*pointer)->next);
  }

  return false;
}

/**
 * Insert the data through a new node in the ordered linked list
 *
 * @tparam AnyObject
 * @param data
 */
template<class AnyObject>
void OrderedLinkedList<AnyObject>::insert(AnyObject data) {
  Node *nodeToBeInserted = new Node{data, nullptr};
  Node **pointer = &head;

  // Avoid duplicated data
  if (!find(data, pointer)) {
    nodeToBeInserted->next = (*pointer);
    (*pointer) = nodeToBeInserted;
  }
}

/**
 * Remove the data of the ordered linked list
 *
 * @tparam AnyObject
 * @param data
 */

template<class AnyObject>
void OrderedLinkedList<AnyObject>::remove(AnyObject data) {
  Node **pointer = &head;

  if (find(data, pointer)) {
    Node *temp;
    temp = (*pointer);
    (*pointer) = (*pointer)->next;
    delete temp;
  }
}

template<class AnyObject>
void OrderedLinkedList<AnyObject>::reverse() {

};

template<class AnyObject>
bool OrderedLinkedList<AnyObject>::empty() {

};

template<class AnyObject>
void OrderedLinkedList<AnyObject>::print() {
  for (auto *node = this->head; node != nullptr; node = node->next) {
    std::cout << node->data << " ";
  }

  std::cout << "\n";
};
