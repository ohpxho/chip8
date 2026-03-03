#include "chip8.h"
#include <SDL2/SDL.h>
#include <raylib.h>
#include <stdlib.h>

#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32
#define FPS 60
#define LEN(x) (sizeof(x) / sizeof((x)[0]))

uint8_t mem[4096];
uint8_t stack[256];
uint8_t screen[SCREEN_HEIGHT][SCREEN_WIDTH];

void MapFonts() {
  const uint8_t fonts[][5] = {
      {0xF0, 0x90, 0x90, 0x90, 0xF0}, // 0
      {0x20, 0x60, 0x20, 0x20, 0x70}, // 1
      {0xF0, 0x10, 0XF0, 0x80, 0xF0}, // 2
      {0xF0, 0x10, 0xF0, 0x10, 0xF0}, // 3
      {0x90, 0x90, 0xF0, 0x10, 0x10}, // 4
      {0xF0, 0x80, 0xF0, 0x10, 0xF0}, // 5
      {0xF0, 0x80, 0xF0, 0x90, 0xF0}, // 6
      {0xF0, 0x10, 0x20, 0x40, 0x40}, // 7
      {0xF0, 0x90, 0xF0, 0x90, 0xF0}, // 8
      {0xF0, 0x90, 0xF0, 0x10, 0xF0}, // 9
      {0xF0, 0x90, 0xF0, 0x90, 0x90}, // A
      {0xE0, 0x90, 0xE0, 0x90, 0xE0}, // B
      {0xF0, 0x80, 0x80, 0x80, 0xF0}, // C
      {0xE0, 0x90, 0x90, 0x90, 0xE0}, // D
      {0xF0, 0x80, 0xF0, 0x80, 0xF0}, // E
      {0xF0, 0x80, 0xF0, 0x80, 0x80}, // F
  };

  int rowlen = LEN(fonts);
  int collen = LEN(fonts[0]);
  int offset = 0x50; // conventional
  for (int i = 0; i < rowlen; i++) {
    for (int j = 0; j < collen; j++) {
      mem[offset] = fonts[i][j];
      offset += 1;
    }
  }
}

void InitScreen() {
  InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "Chip8");
  SetTargetFPS(FPS);
}

void HandleKeyboardEvent(SDL_Event *event) {
  while (SDL_PollEvent(event)) {
    if (event->type != SDL_KeyboardEvent) {
      return;
    }

    SDL_KeyboardEvent *key = &event->key;

    switch (key->type) {}
  }
}

void boot() {
  MapFonts(); // setup fonts in mem
  InitScreen();
}

void ClearScreen() {}

void Exit() { CloseWindow(); }

int main() {
  boot();

  while (!WindowShouldClose()) {
    SDL_Event event;
    HandleKeyboardEvent(&event);
  }
  return 0;
}
