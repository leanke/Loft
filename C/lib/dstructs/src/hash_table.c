#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct {
    char* key;
    int value;
} Entry;

Entry* hashTable[TABLE_SIZE];

// Naive hash function
static unsigned int hash(const char* key) {
    unsigned int hashVal = 0;
    while (*key) {
        hashVal += (unsigned int)(*key);
        key++;
    }
    return hashVal % TABLE_SIZE;
}

// Insert a key-value pair into the hash table
void htInsert(char* key, int value) {
    unsigned int idx = hash(key);
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = strdup(key);
    newEntry->value = value;
    hashTable[idx] = newEntry;
}

// Look up a value by its key
int htLookup(char* key) {
    unsigned int idx = hash(key);
    Entry* entry = hashTable[idx];
    if (entry && strcmp(entry->key, key) == 0) {
        return entry->value;
    }
    return -1;
}
