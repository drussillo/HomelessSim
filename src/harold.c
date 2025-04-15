#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harold.h"
#include "items.h"

#define INVENTORY_SIZE 10

static int health;
static struct Item inventory[10];

void harold_clear_inventory(void) {
  struct Item empty_item = {"EMPTY", "", "", MISC, {{0}}};
  for(int i = 0; i < INVENTORY_SIZE; i++) {
    inventory[i] = empty_item;
  }
}

void harold_load_inventry(void) {
  FILE *inventory_file = fopen("data/inventory", "r");

  fclose(inventory_file);
}

void harold_save_inventory(void) {
  FILE *inventory_file = fopen("data/inventory", "w");
  for(int i = 0; i < INVENTORY_SIZE; i++) {
    fprintf(inventory_file, "%s\n", inventory[i].name);
    fprintf(inventory_file, "%s\n", inventory[i].description);
    fprintf(inventory_file, "%s\n", inventory[i].drawable);
    fprintf(inventory_file, "%d\n", inventory[i].type);
    switch(inventory[i].type) {
      case WEAPON:
        fprintf(inventory_file, "%d\n", inventory[i].data.weapon.damage);
        fprintf(inventory_file, "%d\n", inventory[i].data.weapon.uses_left);
        break;
      case HEALING:
        fprintf(inventory_file, "%d\n", inventory[i].data.healing.health_delta);
        break;
      case MISC:
        break;
    }
    printf("\n");
  }
  fclose(inventory_file);
}


void harold_add_inventory(struct Item new_item) {
  for(int i = 0; i < INVENTORY_SIZE; i++) {
    if(strcmp(inventory[i].name, "EMPTY") == 0) {
      inventory[i] = new_item;
      break;
    }
  }
}


// debug

void harold_print_inventory(void) {
  for(int i = 0; i < INVENTORY_SIZE; i++) {
    if(strcmp(inventory[i].name, "EMPTY") != 0){
      fprintf(stdout, "%s\n", inventory[i].name);
      fprintf(stdout, "%s\n", inventory[i].description);
      fprintf(stdout, "%s\n", inventory[i].drawable);
      fprintf(stdout, "%d\n", inventory[i].type);
      switch(inventory[i].type) {
        case WEAPON:
          fprintf(stdout, "%d\n", inventory[i].data.weapon.damage);
          fprintf(stdout, "%d\n", inventory[i].data.weapon.uses_left);
          break;
        case HEALING:
          fprintf(stdout, "%d\n", inventory[i].data.healing.health_delta);
          break;
        case MISC:
          break;
      }
    }
  }
}
