#include <cassert>

#include "Trie.h"

int main(int argc, char *argv[]) {
    Trie trie;

    trie.insert("romane");
    trie.insert("romanes");
    trie.insert("romanus");
    trie.insert("romulus");
    trie.insert("rubens");
    trie.insert("rubes");
    trie.insert("ruber");
    trie.insert("rubicon");
    trie.insert("rubicundus");
    trie.insert("rubric");

    assert(trie.find("romane"));
    assert(!trie.find("roma"));

    trie.insert("roma");
    assert(trie.find("roma"));

    trie.remove("romanes");
    assert(!trie.find("romanes"));

    trie.print();
}
