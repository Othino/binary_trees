#include "binary_trees.h"

/**
  * node_depth - count the levels of the Binary tree
  * @tree: root node of the BT
  * Return: Nothing
  */
size_t node_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + node_depth(tree->parent));
}

/**
  * binary_tree_depth - measures the depth of a node in a binary tree
  * @tree: root node of the BT
  * Return: Nothing
  */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (node_depth(tree) - 1);
}

/**
  * BT_perfect - checks if a binary tree is perfect
  * @tree: root node of the BT
  * Return: numbers of leave
  */
int BT_perfect(const binary_tree_t *tree)
{
	size_t perfect_left = 0, perfet_right = 0, perfect = 0;

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (binary_tree_depth(tree));

	perfect_left = BT_perfect(tree->left);
	perfet_right = BT_perfect(tree->right);

	if (perfect_left == perfet_right)
		perfect = perfect_left;
	else
		perfect = 0;

	return (perfect);
}

/**
  * binary_tree_is_perfect - checks if a binary tree is perfect
  * @tree: root node of the BT
  * Return: numbers of leave
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!(tree->parent) && !(tree->left) && !(tree->right))
		return (1);

	if (BT_perfect(tree) == 0)
		return (0);
	else
		return (1);
}
