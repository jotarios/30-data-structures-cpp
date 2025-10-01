#ifndef DATASTRUCTURES_TRIE_H
#define DATASTRUCTURES_TRIE_H

#include <string>

static constexpr int ALPHABET_SIZE = 26;

/**
 * Trie (Prefix Tree) implementation for storing strings
 *
 * IMPORTANT: This implementation assumes all input strings contain only
 * lowercase English letters ('a'-'z'). Runtime validation is performed
 * and throws std::invalid_argument for invalid characters.
 *
 * Example of valid input: "hello", "world", "trie"
 * Example of invalid input: "Hello", "test123", "test-case"
 */

struct TrieNode {
    bool is_end_of_word = false;
    TrieNode *children[ALPHABET_SIZE] = {};
};

class Trie {
    typedef TrieNode Node;

    Node *root;

    static void print_helper(const Node *node, std::string &current_word);

    bool remove_helper(Node *node, const std::string &word, size_t index);

    void destroy_helper(Node *node);

    Node *copy_helper(const Node *node);

    static void validate_char(char c);

public:
    Trie() : root(nullptr) {
    };

    ~Trie();

    Trie(const Trie &other);

    Trie &operator=(const Trie &other);

    Trie(Trie &&other) noexcept;

    Trie &operator=(Trie &&other) noexcept;

    bool empty() const;

    void insert(const std::string &word);

    bool find(const std::string &word) const;

    void remove(const std::string &word);

    void print() const;
};


#endif //DATASTRUCTURES_TRIE_H
