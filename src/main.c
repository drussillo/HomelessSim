#include <stdio.h>
#include <string.h>
#include "harold.h"
#include "items.h"


int main(void) {
  harold_clear_inventory();

  struct Item test;
  strcpy(test.name, "test item");
  strcpy(test.description, "This is a debug item.");
  test.drawable = "drawablepath";
  test.type = MISC;
  test.data = (union ItemData){0};

  harold_add_inventory(test);
  harold_print_inventory();

  return 0;
}
