#include <cassert>
#include "OrderedLinkedList.h"
#include "OrderedLinkedList.cpp"

int main(int argc, const char *argv[]) {
    OrderedLinkedList<int> integers;

    assert(integers.empty());
    assert(integers.size() == 0);

    integers.insert(20);
    integers.insert(10);
    integers.insert(20);
    integers.insert(2);
    integers.insert(2);
    integers.insert(2);
    integers.insert(40);
    integers.insert(1);
    integers.insert(100);
    integers.insert(100);

    assert(integers.size() == 10);

    integers.remove(1);
    integers.remove(100);

    assert(integers.size() == 8);

    integers.print();

    assert(!integers.empty());

    return 0;
}
