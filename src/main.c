#include <stdio.h>
#include <string.h>
#include "harold.h"
#include "items.h"


int main(void) {
  struct Item test1;
  strcpy(test1.name, "test item");
  strcpy(test1.description, "This is a debug item.");
  strcpy(test1.drawable, "drawablepath/img.png");
  test1.type = MISC;
  test1.data = (union ItemData){0};

  struct Item test2;
  strcpy(test2.name, "Dirty Needle");
  strcpy(test2.description, "Used needle. Extra poison damage (AIDS).");
  strcpy(test2.drawable, "drawables/used_needle1.png");
  test2.type = WEAPON;
  test2.data.weapon.damage = 38;
  test2.data.weapon.uses_left = 5;
  test2.data.weapon.crit_chances = 25;

  struct Item test3;
  strcpy(test3.name, "Broken Bottle");
  strcpy(test3.description, "A bottle, but broken. WARNING: sharp edges!");
  strcpy(test3.drawable, "drawables/broken_bottle1.png");
  test3.type = WEAPON;
  test3.data.weapon.damage = 13;
  test3.data.weapon.uses_left = 20;
  test3.data.weapon.crit_chances = 15;

  harold_clear_inventory();
  // harold_add_inventory(test1);
  // harold_add_inventory(test2);
  // harold_add_inventory(test3);
  // harold_save_inventory();
  harold_load_inventory();
  harold_print_inventory();


  return 0;
}
