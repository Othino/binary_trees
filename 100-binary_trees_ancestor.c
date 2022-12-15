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
  * binary_trees_ancestor -  finds the ancestor of given nodes
  * @first: first node
  * @second: second node
  * Return: ancestor node
  */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	size_t first_depth = 0, second_depth = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);
	while (first && second)
	{
		if (first_depth > second_depth)
		{
			first_depth -= 1;
			first = first->parent;
		}
		else if (second_depth > first_depth)
		{
			second_depth -= 1;
			second = second->parent;
		}
		else
		{
			if (first == second)
				return ((binary_tree_t *) first);
			first = first->parent;
			second = second->parent;
		}

	}
	return (NULL);
}
