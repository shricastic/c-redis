#ifndef DB_H
#define DB_H 

#include "hashtable.h" 

typedef struct {
  HashTable *store;
} Database;

Database *db_init();
void db_free(Database *db);

void db_set(Database *db, const char *key, const char *value);
char *db_get(Database *db, const char *key);
void db_del(Database *db, const char *key);


#endif // !DB_H
