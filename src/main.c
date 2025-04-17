#include <stdio.h>
#include <string.h>
#include "harold.h"
#include "settings.h"
#include "raylib.h"
#include "items.h"


int main(void) {
  item_print_item(item_get_item_from_bin(WEAPON, 3));

  // InitWindow(DisplayWidth, DisplayHeight, "Homeless Simulator: Harold's Adventure");
  // SetTargetFPS(FPS);
  //
  // while(!WindowShouldClose()) {
  //   BeginDrawing();
  //
  //   ClearBackground(RAYWHITE);
  //
  //   EndDrawing();
  // }
  //
  // CloseWindow();

  return 0;
}
