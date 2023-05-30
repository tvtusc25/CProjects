//
//  wordcounter.h
//  
//
//  Created by Trey Tuscai on 4/1/22.
//

#ifndef wordcounter_h
#define wordcounter_h

#include <stdio.h>

typedef struct KeyValuePair
{
    char *key;
    int value;
} kvp;

void create_wordlist(char *filename);

void strip_punct(char *src, char *dst);

void create_unique_wordList(char *wordList[], int num_words);

void count_words(kvp *unique_wordList, int unique_words, char **wordList, int num_words);

void sort_words(kvp *unique_wordList, int unique_words);

void print_wordList(kvp *unique_wordList, int unique_words);

#endif /* wordcounter_h */
