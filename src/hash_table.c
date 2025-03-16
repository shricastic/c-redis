#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define TABLE_SIZE 101

static unsigned int hash(const char *key){
  unsigned long int value = 0;
  while(*key) value = (value * 37) + *key++;
  return value % TABLE_SIZE;
}

HashTable *ht_create() {
  HashTable *table = malloc(sizeof(HashTable));
  table->size = TABLE_SIZE;
  table->buckets = calloc(table->size, sizeof(Entry *));
  return table;
}

void ht_free(HashTable *table) {
  for(int i=0; i < table->size ; i++){
    Entry *entry = table->buckets[i];
    while (entry) {
      Entry *temp = entry;
      entry = entry->next;

      free(temp->key);
      free(temp->value);
      free(temp);
    }
  }

  free(table->buckets);
  free(table);
}

void ht_insert(HashTable *table, const char *key, const char *value) {
  unsigned int index = hash(key);
  Entry *entry = table->buckets[index];

  while (entry) {
    if(strcmp(entry->key, key) == 0) {
      free(entry->value);
      entry->value = strdup(value);
      return;
    }
    entry = entry->next;
  }

  entry = malloc(sizeof(Entry));
  entry->key = strdup(key);
  entry->value = strdup(value);
  entry->next = table->buckets[index];
  table->buckets[index] = entry;
}

char *ht_search(HashTable *table, const char *key) {
  unsigned int index = hash(key);
  Entry *entry = table->buckets[index];

  while (entry) {
    if (strcmp(entry->key, key) == 0) {
      return entry->value;
    }
    entry = entry->next;
  }

  return NULL;
}

void ht_delete(HashTable *table, const char *key){
  unsigned int index = hash(key);
  Entry *entry = table->buckets[index];
  Entry *prev = NULL;

  while(entry) {
    if(strcmp(entry->key, key) == 0) {
      if(prev){
        prev->next = entry->next;
      } else{
        table->buckets[index] = entry->next;
      }

      free(entry->key);
      free(entry->value);
      free(entry);
      return;
    }
    prev = entry;
    entry = entry->next;
  }
}
