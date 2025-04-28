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
  CHUNKID,
  FLAG
};

union ObjectSubtype {
  void *none;
  enum ItemType item;
  // enum NPCType npc;
  // enum SpriteType sprite;
  // ...
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
  union ObjectSubtype subtype;
  int id;
  union ObjectData data;
  bool draw;
  int posx;
  int posy;
};

void object_load_data(struct Object object);

void object_unload_data(struct Object object);

#endif // !OBJECTS_H
