#include "binary_trees.h"

/**
  * printGivenLevel - print in order level
  * @tree: root node of the BT
  * @func: function to print the traverse
  * @level: level of BiTr
  * Return: Nothing
  */
void printGivenLevel(binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		printGivenLevel(tree->left, func, level - 1);
		printGivenLevel(tree->right, func, level - 1);
	}
}

/**
  * height - get the height of BiTr
  * @tree: root node of the BT
  * Return: the height of BT
  */
int height(binary_tree_t *tree)
{
	int lheight = 0;
	int rheight = 0;

	if (tree == NULL)
		return (0);
	lheight = height(tree->left);
	rheight = height(tree->right);
	if (lheight > rheight)
		return (lheight + 1);
	else
		return (rheight + 1);
}

/**
  * binary_tree_levelorder - goes through abinarytreeusinglevel-ordertraversal
  * @tree: root node of the BT
  * @func: function to print the traverse
  * Return: Nothing
  */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h = 0, i = 0;

	if (tree && func)
	{
		h = height((binary_tree_t *) tree);
		for (i = 1; i <= h; i++)
			printGivenLevel((binary_tree_t *) tree, func, i);
	}
}
