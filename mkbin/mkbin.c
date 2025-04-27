#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "items.h"
#include "chunks.h"
#include "objects.h"
void mkweapons(void) { struct Item weapon0;
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
  strcpy(weapon2.drawable, "drawables/fentbag1.png"); weapon2.type = WEAPON;
  weapon2.data.weapon.damage = 999999;
  weapon2.data.weapon.uses_left = 1;
  weapon2.data.weapon.crit_chances = 0;

  FILE *items_weapons_bin = fopen("../data/items.weapons.bin", "wb");
  // FILE *weaponsbin = fopen("../data/harold.inventory.bin", "wb");
  fwrite(&weapon0, sizeof(struct Item), 1, items_weapons_bin);
  fwrite(&weapon1, sizeof(struct Item), 1, items_weapons_bin);
  fwrite(&weapon2, sizeof(struct Item), 1, items_weapons_bin);
  fclose(items_weapons_bin);
}


void mkchunks_testscene(void) {
  struct Chunk chunk0;
  chunk0.chunkid = 0;
  chunk0.object_amount = 2;
  strcpy(chunk0.background, "./drawables/backdrop_test.png");
  chunk0.objects = malloc(sizeof(struct Object) * chunk0.object_amount);
  chunk0.objects[0] = (struct Object){
    .type = ITEM,
    .subtype = WEAPON,
    .id = 1,  // broken bottle
    .data.item = NULL,
    .draw = true,
    .posx = 10,
    .posy = 10
  };
  chunk0.objects[1] = (struct Object){
    .type = ITEM,
    .subtype = WEAPON,
    .id = 0,  // Dirty needle
    .data.item = NULL,
    .draw = true,
    .posx = 20,
    .posy = 20
  };

  FILE *chunks_testscene_bin = fopen("../data/chunks.testscene.bin", "wb");
  fclose(chunks_testscene_bin);
}


int main(void) {
  mkweapons();
  // mkchunks_testscene();

  return 0;
}
