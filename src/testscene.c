#include "raylib.h"
#include "testscene.h"
#include "chunks.h"

#define CHUNK_AMOUNT 9
static struct Chunk chunks[CHUNK_AMOUNT];


static void init_background(void) {
}

static void unload_background(void) {
}

void testscene_init(void) {
  init_background();
}

void testscene_unload(void) {
  unload_background();
}
