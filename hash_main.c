#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "hashtab.h"

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
    while (fgets(mas, LINE_SIZE, fp)) 
    {
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

int main(char *argv[])
{
    int i = 0, o, j, zer = 0;
    double t;
	int count=0;
	int *mas;
    j = load_words(argv[1]);
    struct listnode *node;
    hashtab_init(hashtab);
    for (i = 0; i <= 200000 ; i++) 
    {
        zer = hashtab_add(hashtab, dictionary[i], i, zer);
    }
    for(i = 10000; i <= 200000; i = i + 10000) 
    {
        o = getrand(0, i);
        t = wtime();
        node = hashtab_lookup(hashtab, dictionary[o]);
        t = wtime() - t;
        for (j = 1; j <= i; j++) {
	     	   mas[hashtab_hash(dictionary[j])];
		}
		for (j = 0; j <= 200000; j++) {
	     		if (mas[j]>0){
				mas[j]--;
				count+= mas[j];
			}
		}
        	printf("%d %.6f %d\n", i, t, count);
		for (j=1;j<i;j++){
			mas[j]=0;
			count=0;
		}
    }
    return 0;
}
