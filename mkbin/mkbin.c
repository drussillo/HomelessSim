#include <stdio.h>
#include <string.h>
#include "items.h"


void mkweapons(void) {
  struct Item weapon0;
  weapon0.itemid = 0;
  strcpy(weapon0.name, "Dirty Needle");
  strcpy(weapon0.description, "Used needle. Extra poison damage (AIDS).");
  strcpy(weapon0.drawable, "drawables/used_needle1.png");
  weapon0.type = WEAPON;
  weapon0.data.weapon.damage = 38;
  weapon0.data.weapon.uses_left = 5;
  weapon0.data.weapon.crit_chances = 25;

  struct Item weapon1;
  weapon1.itemid = 1;
  strcpy(weapon1.name, "Broken Bottle");
  strcpy(weapon1.description, "A bottle, but broken. WARNING: sharp edges!");
  strcpy(weapon1.drawable, "drawables/broken_bottle1.png");
  weapon1.type = WEAPON;
  weapon1.data.weapon.damage = 13;
  weapon1.data.weapon.uses_left = 20;
  weapon1.data.weapon.crit_chances = 15;

  struct Item weapon2;
  weapon2.itemid = 2;
  strcpy(weapon2.name, "Fent");
  strcpy(weapon2.description, "Bag of magical fentanyl powder. Causes OD as soon as you throw it on someone.");
  strcpy(weapon2.drawable, "drawables/fentbag1.png");
  weapon2.type = WEAPON;
  weapon2.data.weapon.damage = 999999;
  weapon2.data.weapon.uses_left = 1;
  weapon2.data.weapon.crit_chances = 0;

  // FILE *weaponsbin = fopen("../data/weapons.bin", "wb");
  // FILE *weaponsbin = fopen("../data/inventory.bin", "wb");
  fwrite(&weapon0, sizeof(struct Item), 1, weaponsbin);
  fwrite(&weapon1, sizeof(struct Item), 1, weaponsbin);
  fwrite(&weapon2, sizeof(struct Item), 1, weaponsbin);
  fclose(weaponsbin);
}


int main(void) {
  // mkweapons();

  return 0;
}
