#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>

typedef struct {
  uint8_t v0;
  uint8_t v1;
  uint8_t v2;
  uint8_t v3;
  uint8_t v4;
  uint8_t v5;
  uint8_t v6;
  uint8_t v7;
  uint8_t v8;
  uint8_t v9;
  uint8_t va;
  uint8_t vb;
  uint8_t vc;
  uint8_t vd;
  uint8_t ve;
  uint8_t vf;  // flag
  uint16_t i;  // index
  uint16_t pc; // program counter
  uint16_t sp; // stack pointer
  uint8_t st;  // sound timer
  uint8_t dt;  // delay timer
} Register;

#endif // CHIP8_H
