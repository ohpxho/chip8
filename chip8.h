#ifndef CHIP8_H
#define CHIP8_H

typedef enum {
  EXEC,       // Execute machine language subroutine at address x (accepts an
              // argument)
  CLRSCRN,    // Clear the screen
  RET,        // Return from a subroutine
  JUMP,       // Jump to address x (accepts an argument)
  EXECSUB,    // Execute subroutine starting at address x (accepts an argument)
  SKIPEQSVX,  // Skip the following instruction if the value of register VX
              // equals x (accepts an argument)
  SKIPNEQSVX, // Skip the following instruction if the value of register VX is
              // not equal to x (accepts an argument)
  SKIPVXEQVY, // Skip the following instruction if the value of register VX is
              // equal to the value of register VY
  STRVX,      // Store number x in register VX (accepts an argument)
  ADDVX,      // Add the value x to register VX (accepts an argument)
} Opcodes;

#endif // CHIP8_H
