#include <stdio.h>
#include <string.h>
#include "harold.h"
#include "raylib.h"
#include "items.h"


int main(void) {
  const int DisplayWidth = 720;
  const int DisplayHeight = 720;
  const int FPS = 60;

  InitWindow(DisplayWidth, DisplayHeight, "Homeless Simulator: Harold's Adventure");
  SetTargetFPS(FPS);

  while(!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
