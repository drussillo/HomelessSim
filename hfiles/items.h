#ifndef ITEM_H
#define ITEM_H

enum ItemType {
  WEAPON,
  HEALING,
  MISC
};


union ItemData {
  struct {
    int damage;
    int uses_left;
    int crit_chances;
  } weapon;
  struct {
    int health_delta;
  } healing;
};

struct Item {
  int itemid;
  char name[21];
  char description[81];
  char drawable[81];
  enum ItemType type;
  union ItemData data;
};

struct Item item_get_empty_item(void);

struct Item item_get_item_from_bin(enum ItemType, int id);

//debug
void item_print_item(struct Item item);

#endif // !ITEM_H
