//
//  wordcounter.c
//  
//
//  Created by Trey Tuscai on 4/1/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "wordcounter.h"

//create sorted word list by num of occurences
void create_wordlist(char *filename)
{
    int num_words = 0;
    
    //open readable file from command line
    FILE *file = fopen(filename, "r");
    
    //create a char* array with the word count
    char **wordList;
    char buf[45];
    
    //dyanmically allocate memory based on number of words
    wordList = malloc(sizeof(char*));
    
    //add all words to the list
    int pos = 0;
    while (fscanf(file, "%s", buf) != EOF)
    {
        //reallocate memory for increasing wordlist
        wordList = realloc(wordList,(num_words +1) * sizeof(char*));
    
        //strip punct and case
        strip_punct(buf, buf);
        
        //allocate memory for each word and copy it to array
        wordList[pos]= (char*)malloc(strlen(buf)*sizeof(char));
        strcpy(wordList[pos], buf);
        
        num_words++;
        pos++;
    }
    
    //create array of key-value pairs holding the unique words and their num of occurences
    create_unique_wordList(wordList, num_words);
}

//strips the punctuations and uppercase letters
void strip_punct(char *src, char *dst)
{
    //remove each character of punctuation
    //upper to lower case
    for (; *src; ++src)
            if (!ispunct((unsigned char) *src))
                *dst++ = tolower((unsigned char) *src);
        *dst = 0;
}

//create array of unique words
void create_unique_wordList(char **wordList, int num_words)
{
    //create array of key-value pairs
    int unique_words = 0;
    kvp *unique_wordList = malloc(sizeof(kvp));
    
   //count number of unique words
    int i, j, k = 0;
    
    for (i = 0; i < num_words; i++)
    {
        //dynamically allocate memory based on the number of unique words
        for (j = i + 1; j < num_words; j++)
            if (strcmp(wordList[i], wordList[j]) == 0)
                break;
        if (j == num_words)
        {
            //reallocate memory for each word and copy to array
            unique_wordList = realloc(unique_wordList,(unique_words +1) * sizeof(kvp));
            unique_wordList[k].key = (char*)malloc(strlen(wordList[i])*sizeof(char));
            unique_wordList[k].key = wordList[i];
            
            unique_words++;
            k++;
        }
    }

    //count the word occurences
    count_words(unique_wordList, unique_words, wordList, num_words);
}

//count the word occurences
void count_words(kvp *unique_wordList, int unique_words, char **wordList, int num_words)
{
    int counter = 0;
    for(int i = 0; i < unique_words; i++)
    {
        for(int j = 0; j < num_words; j++)
        {
            //if word finds another occurence increase the count
            if(strcmp(unique_wordList[i].key, wordList[j]) == 0)
                   counter++;
        }
        //sets its value to the count
        unique_wordList[i].value = counter;
        counter = 0;
    }
    //sort words by occurence
    sort_words(unique_wordList, unique_words);
}

//sort words by occurences
void sort_words(kvp *unique_wordList, int unique_words)
{
    //insertion sort
    int i, value, j;
    char *key;
        for (i = 1; i < unique_words; i++)
        {
            value = unique_wordList[i].value;
            key = unique_wordList[i].key;
            j = i - 1;
     
            /* Move elements of unique_wordList[0..i-1], that are
              greater than key, to one position ahead
              of their current position */
            while (j >= 0 && unique_wordList[j].value > value)
            {
                unique_wordList[j + 1].value = unique_wordList[j].value;
                unique_wordList[j + 1].key = unique_wordList[j].key;
                j = j - 1;
            }
            unique_wordList[j + 1].value = value;
            unique_wordList[j + 1].key = key;
        }
    
    //prints the finalized word list
    print_wordList(unique_wordList, unique_words);
}

//prints the finalized word list
void print_wordList(kvp *unique_wordList, int unique_words)
{
    //iterates through each key and value
    for(int i = unique_words-1; i >= 0; i--)
    {
        printf("%s: ", unique_wordList[i].key);
        printf("%d\n", unique_wordList[i].value);
    }
}

//create word list from file
int main(int argc, char** argv)
{
    create_wordlist(argv[1]);
}

