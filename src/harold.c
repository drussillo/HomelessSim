#include <stdlib.h>
#include "items.h"

#define INVENTORY_SIZE 20

static int health;
static struct Item inventory[10];

void clear_inventory(void) {
  struct Item empty_item = {"EMPTY"};
  for(int i = 0; i < INVENTORY_SIZE; i++) {
    inventory[i] = empty_item;
  }
}

void load_inventry(void) {
  FILE *inventory = fopen("data/inventory", "r");

  fclose(inventory);
}

void save_inventory(void) {
  FILE *inventory = fopen("data/inventory", "w");

  fclose(inventory);
}

void add_inventory(struct Item new_item) {
  for(int i = 0; i < 10 && strcmp(inventory[i].name, "EMPTY") == 0; i++) {
  }
}
