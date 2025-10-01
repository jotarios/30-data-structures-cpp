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

    Node *current;

public:
    ForwardIterator(Node *init) : current(init) {
    };

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

    Node *head;
    std::size_t list_size;

public:
    OrderedLinkedList() : head(nullptr), list_size(0) {
    }

    bool find(AnyObject data, Node **&pointer);

    void insert(AnyObject data);

    void remove(AnyObject data);

    void reverse();

    bool empty();

    std::size_t size() const;

    void print();

    // Iterator functions
    ForwardIterator<AnyObject> begin();

    ForwardIterator<AnyObject> end();
};

#endif //INC_30_DATA_STRUCTURES_CPP_ORDEREDLINKEDLIST_H
