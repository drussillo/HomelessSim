#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harold.h"
#include "items.h"

#define INVENTORY_SIZE 10

static int health;
static struct Item inventory[10];


void harold_clear_inventory(void) {
  struct Item empty_item = {0, "EMPTY", "", "", MISC, {{0}}};
  for(int i = 0; i < INVENTORY_SIZE; i++) {
    inventory[i] = empty_item;
  }
}


void harold_add_inventory(struct Item new_item) {
  for(int i = 0; i < INVENTORY_SIZE; i++) {
    if(strcmp(inventory[i].name, "EMPTY") == 0) {
      inventory[i] = new_item;
      break;
    }
  }
}


void harold_load_inventory(void) {
  FILE *inventorybin= fopen("data/inventory.bin", "rb");

  fread(inventory, sizeof(struct Item), INVENTORY_SIZE, inventorybin);

  fclose(inventorybin);
}


void harold_save_inventory(void) {
  FILE *inventorybin = fopen("data/inventory.bin", "wb");
  fwrite(inventory, sizeof(struct Item), INVENTORY_SIZE, inventorybin);
  fclose(inventorybin);
}


// debug

void harold_print_inventory(void) {
  for(int i = 0; i < INVENTORY_SIZE; i++) {
    fprintf(stdout, "id: %d\n", inventory[i].itemid);
    fprintf(stdout, "name: %s\n", inventory[i].name);
    fprintf(stdout, "desc: %s\n", inventory[i].description);
    fprintf(stdout, "draw: %s\n", inventory[i].drawable);
    fprintf(stdout, "type: %d\n", inventory[i].type);
    switch(inventory[i].type) {
      case WEAPON:
        fprintf(stdout, "damg: %d\n", inventory[i].data.weapon.damage);
        fprintf(stdout, "uses: %d\n", inventory[i].data.weapon.uses_left);
        fprintf(stdout, "crit: %d\n", inventory[i].data.weapon.crit_chances);
        break;
      case HEALING:
        fprintf(stdout, "health: %d\n", inventory[i].data.healing.health_delta);
        break;
      case MISC:
        break;
    }
    puts("");
  }
}
