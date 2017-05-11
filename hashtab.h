#ifndef PROCESSING_H
#define PROCESSING_H

#define BUFSIZE 1024
#define HASHTAB_SIZE 1000
#define HASHTAB_MUL 31

struct listnode *hashtab[HASHTAB_SIZE];

struct listnode {
        char *key;
        int value;
        struct listnode *next;
};

unsigned int hashtab_hash (char *key);
void hashtab_init (struct listnode **hashtab);
int hashtab_add (struct listnode **hashtab, char *key, int value, int zer);
struct listnode *hashtab_lookup (struct listnode **hashtab, char *key);
void hashtab_delete (struct listnode **hashtab, char *key);

#endif
