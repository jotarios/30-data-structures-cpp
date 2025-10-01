#include "Trie.h"
#include <iostream>
#include <stdexcept>

/**
 * Destructor - recursively deletes all nodes in the trie
 */
Trie::~Trie() {
    destroy_helper(root);
}

/**
 * Copy constructor - performs deep copy of the trie
 *
 * @param other The trie to copy from
 */
Trie::Trie(const Trie &other) : root(copy_helper(other.root)) {
}

/**
 * Copy assignment operator - performs deep copy with cleanup of existing data
 *
 * @param other The trie to copy from
 * @return Reference to this trie
 */
Trie &Trie::operator=(const Trie &other) {
    if (this != &other) {
        destroy_helper(root);
        root = copy_helper(other.root);
    }

    return *this;
}

/**
 * Move constructor - transfers ownership of resources
 *
 * @param other The trie to move from
 */
Trie::Trie(Trie &&other) noexcept : root(other.root) {
    other.root = nullptr;
}

/**
 * Move assignment operator - transfers ownership with cleanup of existing data
 *
 * @param other The trie to move from
 * @return Reference to this trie
 */
Trie &Trie::operator=(Trie &&other) noexcept {
    if (this != &other) {
        destroy_helper(root);
        root = other.root;
        other.root = nullptr;
    }

    return *this;
}

/**
 * Helper function to recursively delete all nodes
 *
 * @param node Current node to delete
 */
void Trie::destroy_helper(Node *node) {
    if (!node) {
        return;
    }

    for (auto child: node->children) {
        destroy_helper(child);
    }

    delete node;
}

/**
 * Helper function to recursively deep copy all nodes
 *
 * @param node Current node to copy
 * @return Pointer to the newly created copy of the node
 */
Trie::Node *Trie::copy_helper(const Node *node) {
    if (!node) {
        return nullptr;
    }

    Node *new_node = new Node();
    new_node->is_end_of_word = node->is_end_of_word;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            new_node->children[i] = copy_helper(node->children[i]);
        }
    }

    return new_node;
}

/**
 * Validate that a character is a lowercase letter
 *
 * @param c The character to validate
 * @throws std::invalid_argument if character is not in range 'a'-'z'
 */
void Trie::validate_char(char c) {
    if (c < 'a' || c > 'z') {
        throw std::invalid_argument("Character must be lowercase letter (a-z)");
    }
}

/**
 * Check if the trie is empty
 *
 * @return bool
 */
bool Trie::empty() const {
    return !root;
}

/**
 * Insert a word into the trie
 *
 * @param word The word to insert (must contain only lowercase letters 'a'-'z')
 */
void Trie::insert(const std::string &word) {
    if (!root) {
        root = new Node();
    }

    Node *current = root;
    for (const char c: word) {
        validate_char(c);
        if (!current->children[c - 'a']) {
            current->children[c - 'a'] = new Node();
        }

        current = current->children[c - 'a'];
    }

    current->is_end_of_word = true;
}

/**
 * Check if a word exists in the trie
 *
 * @param word The word to search for (must contain only lowercase letters 'a'-'z')
 * @return bool
 */
bool Trie::find(const std::string &word) const {
    if (empty()) {
        return false;
    }

    const Node *current = root;
    for (const char c: word) {
        validate_char(c);
        if (!current->children[c - 'a']) {
            return false;
        }
        current = current->children[c - 'a'];
    }

    return current->is_end_of_word;
}

/**
 * Remove a word from the trie
 *
 * @param word The word to remove (must contain only lowercase letters 'a'-'z')
 */
void Trie::remove(const std::string &word) {
    if (empty() || word.empty()) {
        return;
    }

    remove_helper(root, word, 0);
}

/**
 * Helper function to recursively remove a word from the trie
 *
 * @param node Current node being processed
 * @param word The word to remove
 * @param index Current index in the word
 * @return bool True if the node should be deleted
 */
bool Trie::remove_helper(Node *node, const std::string &word, size_t index) {
    if (!node) {
        return false;
    }

    if (index == word.length()) {
        if (!node->is_end_of_word) {
            return false;
        }

        node->is_end_of_word = false;

        for (const auto &childrenNode: node->children) {
            if (childrenNode) {
                return false;
            }
        }

        return true;
    }

    const char ch = word[index];
    validate_char(ch);
    Node *child = node->children[ch - 'a'];

    if (remove_helper(child, word, index + 1)) {
        delete node->children[ch - 'a'];
        node->children[ch - 'a'] = nullptr;

        if (!node->is_end_of_word) {
            for (const auto &childrenNode: node->children) {
                if (childrenNode) {
                    return false;
                }
            }

            return node != root;
        }
    }

    return false;
}

/**
 * Print all words in the trie in lexicographic order
 */
void Trie::print() const {
    if (!root) {
        std::cout << "Trie is empty" << std::endl;
        return;
    }

    std::string current_word;
    print_helper(root, current_word);
}

/**
 * Helper function to recursively print words in the trie
 *
 * @param node Current node being processed
 * @param current_word Current word being built
 */
void Trie::print_helper(const Node *node, std::string &current_word) {
    if (node->is_end_of_word) {
        std::cout << current_word << "\n";
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            current_word.push_back('a' + i);
            print_helper(node->children[i], current_word);
            current_word.pop_back();
        }
    }
}
