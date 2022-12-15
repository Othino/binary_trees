#include <stdio.h>

// Definition of a binary tree node
typedef struct binary_tree_s
{
    int value;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// Returns the size of a binary tree
size_t binary_tree_size(const binary_tree_t *tree)
{
    // If tree is NULL, return 0
    if (tree == NULL)
    {
        return 0;
    }

    // Otherwise, return the size of the left subtree + the size of the right subtree + 1 (for the root node)
    return binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1;
}
