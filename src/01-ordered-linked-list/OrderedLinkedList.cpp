#include "OrderedLinkedList.h"

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

    while ((*pointer) && (*pointer)->data <= data) {
        pointer = &((*pointer)->next);
    }

    nodeToBeInserted->next = (*pointer);
    (*pointer) = nodeToBeInserted;
    list_size++;
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
        list_size--;
    }
}

/**
 * Reverse the order of the list
 *
 * @tparam AnyObject
 */
template<class AnyObject>
void OrderedLinkedList<AnyObject>::reverse() {
    Node *init = this->head;
    Node *next = nullptr;
    Node *temp = nullptr;

    while (init) {
        temp = init->next;
        init->next = next;
        next = init;
        init = temp;
    }

    this->head = next;
};

/**
 * Check if the ordered linked list is empty
 *
 * @tparam AnyObject
 * @return
 */
template<class AnyObject>
bool OrderedLinkedList<AnyObject>::empty() {
    return !this->head;
};

template<class AnyObject>
std::size_t OrderedLinkedList<AnyObject>::size() const {
    return list_size;
}

template<class AnyObject>
void OrderedLinkedList<AnyObject>::print() {
    for (auto it = this->begin(); it != this->end(); it++) {
        std::cout << *it << " ";
    }

    std::cout << "\n";
};

// Iterators
template<class AnyObject>
ForwardIterator<AnyObject> OrderedLinkedList<AnyObject>::begin() {
    return ForwardIterator<AnyObject>(this->head);
}

template<class AnyObject>
ForwardIterator<AnyObject> OrderedLinkedList<AnyObject>::end() {
    return ForwardIterator<AnyObject>(nullptr);
}
