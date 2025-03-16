#include <stdio.h>
#include <string.h>
#include "parser.h"

void parse_command(Database *db, const char *input) {
  char command[10], key[256], value[256];

  if(sscanf(input, "%s %s %255[^\n]", command, key, value) >= 2) {
    if(strcmp(command, "SET") == 0) {
      db_set(db, key, value);
      printf("::::: DATA STORED :::::\n\n");
    } else if( strcmp(command, "GET") == 0) {
      char *result = db_get(db, key);
      printf("%s\n\n", result ? result : "::: DATA NOT FOUND :::\n\n");
    } else if(strcmp(command, "DEL") == 0) {
      db_del(db, key);
      printf(":::: DATA DELETED ::::\n\n");
    } else {
      printf(":::: INVALID COMMAND ::::\n\n");
    }
  } else {
    printf(":::: INVALID INPUTS ::::\n\n");
  }
}
