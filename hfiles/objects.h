#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdbool.h>
#include "items.h"
// #include "NPCs.h"
// #include "sprites.h"
// #include "flags.h"

enum ObjectType {
  ITEM,
  NPC,
  SPRITE,
  CHUNKPTR,
  FLAG
};

union ObjectData {
  struct Item *item;
  // struct *NPC npc;
  // struct Sprite *sprite;
  // struct Chunk *chunkptr;
  // struct Flag *flag;
};

struct Object {
  enum ObjectType type;
  enum ItemType subtype;
  int id;
  union ObjectData data;
  bool draw;
  int posx;
  int posy;
};

#endif // !OBJECTS_H
