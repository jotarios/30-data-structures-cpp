#include "OrderedLinkedList.h"
#include "OrderedLinkedList.cpp"

int main(int argc, const char *argv[]) {
  OrderedLinkedList<int> integerList;

  std::cout << integerList.empty() << "\n";

  integerList.insert(20);
  integerList.insert(10);
  integerList.insert(20);
  integerList.insert(2);
  integerList.insert(2);
  integerList.insert(2);
  integerList.insert(40);
  integerList.insert(1);
  integerList.insert(100);

  integerList.print();

  integerList.reverse();

  integerList.print();

  integerList.remove(300);
  integerList.remove(1);
  integerList.remove(100);

  integerList.print();

  integerList.reverse();

  integerList.print();

  std::cout << integerList.empty() << "\n";

  return 0;
}
