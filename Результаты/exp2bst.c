#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "bstree.h"

#define LINE_SIZE 1200
#define HASHTAB_SIZE 1000

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

char *dictionary[366000];

int load_words(char *filename) 
{
    int i = 0, j = 0;
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    char mas[LINE_SIZE];
       while (fgets(mas, LINE_SIZE, fp)) {
                dictionary[j] = strdup(mas);
                dictionary[j] = malloc(strlen(mas) * sizeof(char) + 1);
                strcpy(dictionary[j], mas);
                j++;
    }
    fclose(fp);
    return j;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(int argc, char *argv[])
{
    int i = 0, o, j;
    double t;
    j = load_words(argv[1]);
    struct bstree *tree, *node;
    tree = bstree_create(dictionary[0], 0);
    
    for (i = 1; i <= 200000; i++) {
        bstree_add(tree, i, dictionary[i]);
    }
	for (i = 1; i <= 200000; i++) {
        t = wtime();
        bstree_add(tree, i, dictionary[i]);
        t = wtime()-t;
        if (i%10000==0)
            printf ("%d %.6f \n", i, t);
    }

    return 0;
}
