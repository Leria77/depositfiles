#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bstree.h"

struct bstree {
	char *key;
	int value;
	struct bstree *left;
	struct bstree *right;
	struct bstree *parent;
};

struct bstree *bstree_create (char *key, int value) {
	struct bstree *nome;
	nome = malloc (sizeof (*nome));
	if (nome != NULL) {
		nome -> key = key;
		nome -> value = value;
		nome -> left = NULL;
		nome -> right = NULL;
	}
	return nome;
}

void bstree_add (struct bstree *tree, char *key, int value)
{
	struct bstree *parent, *nome;
	if (tree == NULL)
		return;
	for (parent = tree; tree != NULL; ) {
 		parent = tree;
		if (key < tree->key)
			tree = tree->left;
		else if (key > tree->key)
			tree = tree->right;
		else
			return;
	}
	nome = bstree_create (key, value);
	if (key < parent->key)
		parent->left = nome;
	else
		parent->right = nome;
	//printf(" tree2 %s \n", nome->key);
	//printf(" tree3 %d \n", nome->value);
}

struct bstree *bstree_lookup (struct bstree *tree, char *key) {
	while(tree != NULL) {
		if (key == tree->key) {
			return tree;
		}
		else if (key < tree->key) {
			tree = tree->left;
		} else {
				tree = tree->right;
		}
	}
	return tree;
}

struct bstree *bstree_min (struct bstree *tree) {
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

struct bstree *bstree_max (struct bstree *tree) {
        if (tree == NULL)
                return NULL;
        while (tree->right != NULL)
                tree = tree->right;
        return tree;
}
