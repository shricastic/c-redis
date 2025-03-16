#include <stdlib.h>
#include <string.h>
#include "db.h"

Database *db_init(){
  Database *db = malloc(sizeof(Database));
  db->store = ht_create();
  return db;
}

void db_free(Database *db){
  ht_free(db->store);
  free(db);
}

void db_set(Database *db, const char *key, const char *value){
  ht_insert(db->store, key, value);
}

char *db_get(Database *db, const char *key){
  return ht_search(db->store, key);
}

void db_del(Database *db, const char *key){
  ht_delete(db->store, key);
}
