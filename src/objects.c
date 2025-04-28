#include <stdio.h>
#include <stdlib.h>
#include "objects.h"
#include "items.h"


void object_load_data(struct Object object) {
  if(object.data == NULL) {
    switch(object.type) {
      case ITEM:
        object.data.item = malloc(sizeof(struct Item));
        *object.data.item = item_get_item_from_bin(object.subtype.item, object.id);
        break;
      case NPC:
        // TODO
        break;
      case SPRITE:
        // TODO
        break;
      case CHUNKID:
        // TODO
        break;
      case FLAG:
        // TODO
        break;
      default:
        printf("ERROR: Attempted loading object data of invalid type.\n");
        break;
    }
  } else {
    printf("ERROR: Attempted loading already loaded object data.\n");
  }
}


void object_unload_data(struct Object object) {
  free(object.data);
}
