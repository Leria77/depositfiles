#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define HASHTAB_SIZE 1000
#define HASHTAB_MUL 31
#define BUFSIZE 1024

#include "hashtab.h"

struct listnode *hashtab[HASHTAB_SIZE];

unsigned int hashtab_hash(char *key) 
{
	unsigned int h = 0; char *p;
	for (p = key; *p != '\0'; p++)
	{
		h = h * HASHTAB_MUL + (unsigned int)*p;
	}
	return h % HASHTAB_SIZE;
}

void hashtab_init (struct listnode **hashtab) {
	int i;
	for (i = 0; i < HASHTAB_SIZE; i++) {
		hashtab[i] = NULL;
	}
}

int hashtab_add (struct listnode **hashtab, char*key, int value, int zer) {
	struct listnode *node;
	int index = hashtab_hash (key);
	node = malloc (sizeof (*node));
	if(hashtab[index] != NULL) {
			zer++;		
	}
	if (node != NULL) {
		node->key = key;
		node->value = value;
		node->next = hashtab[index];
		hashtab[index] = node;
	}
	return zer;
}

struct listnode *hashtab_lookup (struct listnode **hashtab, char *key) {
	int index;
	struct listnode *node;
	index = hashtab_hash(key);
	for (node = hashtab[index]; node  != NULL; node = node->next) {
		if (strcmp (node->key, key) == 0)
			return node;
	}
	return NULL;
}

void hashtab_delete (struct listnode **hashtab, char *key) {
	int index;
	struct listnode *p, *prev = NULL;
	index = hashtab_hash (key);
	for (p = hashtab[index]; p != NULL; p = p->next) {
		if (strcmp (p->key, key) == 0) {
			if (prev == NULL)
				hashtab[index] = p->next;
			else
				prev->next = p->next; 
			free (p);
			return;
		}
		prev = p;
	}
}
