#ifndef CHUNKS_H
#define CHUNKS_H

#include "objects.h"
#include "items.h"


struct Chunk {
  int chunkid;  // functions like an index
  int object_amount;
  char background[81];
  struct Object *objects;
};

#endif // !CHUNKS_H
