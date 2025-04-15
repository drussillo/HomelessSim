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

void harold_load_inventory(void) {
  FILE *inventory_file = fopen("data/inventory", "r");
  char temp[81];

  for(int i = 0; i < INVENTORY_SIZE; i++) {
    fgets(temp, 81, inventory_file);
    if(strcmp(temp, "EMPTY\n") == 0) {
      fgets(temp, 81, inventory_file);
      fgets(temp, 81, inventory_file);
      fgets(temp, 81, inventory_file);
    } else {
      // name
      temp[strlen(temp) - 1] = '\0';
      strcpy(inventory[i].name, temp);
      // description
      fgets(temp, 81, inventory_file);
      temp[strlen(temp) - 1] = '\0';
      strcpy(inventory[i].description, temp);
      // drawable
      fgets(temp, 81, inventory_file);
      temp[strlen(temp) - 1] = '\0';
      strcpy(inventory[i].drawable, temp);
      // type
      fgets(temp, 81, inventory_file);
      enum ItemType type = atoi(temp);
      inventory[i].type = type;
      // data
      if(type == WEAPON) {
        fgets(temp, 81, inventory_file);
        inventory[i].data.weapon.damage = atoi(temp);
        fgets(temp, 81, inventory_file);
        inventory[i].data.weapon.uses_left = atoi(temp);
        fgets(temp, 81, inventory_file);
        inventory[i].data.weapon.crit_chances = atoi(temp);
      } else if(type == HEALING) {
        fgets(temp, 81, inventory_file);
        inventory[i].data.healing.health_delta = atoi(temp);
      }
    }
  }
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
        fprintf(inventory_file, "%d\n", inventory[i].data.weapon.crit_chances);
        break;
      case HEALING:
        fprintf(inventory_file, "%d\n", inventory[i].data.healing.health_delta);
        break;
      case MISC:
        break;
    }
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
    fprintf(stdout, "%s\n", inventory[i].name);
    fprintf(stdout, "%s\n", inventory[i].description);
    fprintf(stdout, "%s\n", inventory[i].drawable);
    fprintf(stdout, "%d\n", inventory[i].type);
    switch(inventory[i].type) {
      case WEAPON:
        fprintf(stdout, "%d\n", inventory[i].data.weapon.damage);
        fprintf(stdout, "%d\n", inventory[i].data.weapon.uses_left);
        fprintf(stdout, "%d\n", inventory[i].data.weapon.crit_chances);
        break;
      case HEALING:
        fprintf(stdout, "%d\n", inventory[i].data.healing.health_delta);
        break;
      case MISC:
        break;
    }
  }
}
