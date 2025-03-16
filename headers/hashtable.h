#ifndef HASHTABLE_H

#define HASHTABLE_H

typedef struct Entry {
  char *key;
  char *value;
  struct Entry *next;
} Entry;

typedef struct{
  Entry **buckets;
  int size;
} HashTable;

HashTable *ht_create();

void ht_free(HashTable *table);
void ht_insert(HashTable *table, const char *key, const char *value);
char *ht_search(HashTable *table, const char *key);
void ht_delete(HashTable *, const char *key);


#endif // !HASHTABLE_H

