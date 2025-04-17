#ifndef CHUNKS_H
#define CHUNKS_H

#include <stdbool.h>
#include "items.h"
// #include "NPCs.h"
// #include "Sprites.h"

enum ObjectType {
  ITEM,
  NPC,
  SPRITE,
  CHUNKPTR
};

union ObjectData {
  struct Item *item;
  // struct *NPC npc;
  // struct Sprite *sprite;
  // struct Chunk *chunkptr;
};

struct Object {
  enum ObjectType type;
  union ObjectData data;
  bool draw;
  int posx;
  int posy;
};

struct Chunk {
  int chunkid;  // functions like an index
  int object_amount;
  char background[81];
  struct Object *objects;
};

#endif // !CHUNKS_H
