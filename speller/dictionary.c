// Implements a dictionary's functionality
#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const int N = 10000;

const int TABLE_SIZE = 65536;

// Hash table
node *table[TABLE_SIZE];

// Hashes word to a number
// Source: www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn/
unsigned int hash(const char *needs_hashing)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(needs_hashing); i < n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % N;
}
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char lcword[LENGTH + 1];

    for (int i = 0, n = strlen(word); i < n + 1; i++)
    {
        lcword[i] = tolower(word[i]);
    }

    node *cursor = table[hash(lcword)];

    while (cursor != NULL)
    {
        if (strcasecmp(lcword, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];

    FILE *dicptr = fopen(dictionary, "r");
    if (dicptr == NULL)
    {
        return false;
    }

    while (fscanf(dicptr, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            unload();
            return false;
        }
        else
        {
            strcpy(new_node->word, word);

            int n = hash(new_node->word);

            new_node->next = table[n];
            table[n] = new_node;
        }
    }
    fclose(dicptr);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int counter = 0;

    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            counter++;
            cursor = cursor->next;
        }
    }
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // iterate through hashtable
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
