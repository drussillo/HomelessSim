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
  char name[21];
  char description[81];
  char drawable[81];
  enum ItemType type;
  union ItemData data;
};

#endif // !ITEM_H
