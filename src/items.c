#include <stdio.h>
#include "items.h"


struct Item item_get_empty_item(void) {
  struct Item empty_item = {0, "EMPTY", "", "", MISC, {{0}}};

  return empty_item;
}


struct Item item_get_item_from_bin(enum ItemType type, int id) {
  // check each id; fseek back to top of each struct; use binary search;
  FILE *itembin;
  if(type == WEAPON) itembin = fopen("./data/weapons.bin", "rb");
  if(type == HEALING) itembin = fopen("../data/healing.bin", "rb");
  // TODO!! ADD NEW FILES ^

  struct Item result;
  int temp;
  long left_offset = 0;
  fseek(itembin, 0, SEEK_END);
  long right_offset = ftell(itembin) - sizeof(struct Item);
  
  while(left_offset <= right_offset) {
    long middle_offset = (right_offset + left_offset) / 2;
    middle_offset -= middle_offset % sizeof(struct Item);
    fseek(itembin, middle_offset, SEEK_SET);
    fread(&temp, sizeof(int), 1, itembin);
    if(temp == id) {
      fseek(itembin, -sizeof(int), SEEK_CUR);
      fread(&result, sizeof(struct Item), 1, itembin);
      fclose(itembin);
      return result;
    } else if(temp < id) {
      left_offset = middle_offset + sizeof(struct Item);
    } else if(temp > id) {
      right_offset = middle_offset - sizeof(struct Item);
    }
  }
  fclose(itembin);
  puts("ERROR: Requested item with invalid ID");
  return item_get_empty_item();
}


// debug

void item_print_item(struct Item item) {
  printf("id: %d\nname: %s\n", item.itemid, item.name);
}
