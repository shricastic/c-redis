#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"
#include "parser.h"

void print_banner(){
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\n");
    printf("     $$$$$$\\            $$$$$$$\\                  $$\\  $$\\           \n");
    printf("    $$  __$$\\           $$  __$$\\                 $$ \\  __|          \n");
    printf("    $$ /  \\__|          $$ |  $$ | $$$$$$\\   $$$$$$$ |  $$|  $$$$$$$ \\ \n");
    printf("    $$ |       $$$$$$\\  $$$$$$$  |$$  __$$\\ $$  __$$ |  $$| $$  _____| \n");
    printf("    $$ |        \\_____| $$  __$$< $$$$$$$$| $$ /  $$ |  $$| \ $$$$$$ \  \n");
    printf("    $$ |  $$\\           $$ |  $$ |$$ ____|  $$ |  $$ |  $$|  \ ____$$ \ \n");
    printf("    \\$$$$$$  |          $$ |  $$ |\\ $$$$$$$ \\ $$$$$$$|  $$| $$$$$$$ | \n");
    printf("     \\______/          \\__|  \\__| \\ ______|  \\ ______| ___| \\ ______/ \n");
    printf("\n");
    printf(":::::::::::::::::::::::::  Made with <3 by Shri. :::::::::::::::::::::::::\n");
    printf("\n");
    printf("\n");

}


int main() {
  Database *db = db_init();
  char input[512];

  print_banner();

  while(1) {
    printf("C-Redis > ");
    
    if(!fgets(input, sizeof(input), stdin)) break;
    if(strncmp(input, "EXIT", 4) == 0) break;
    
    parse_command(db, input);
  }

  db_free(db);
  return 0;
}
