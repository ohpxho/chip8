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
  STRVYVX,    // Store the value of register VY in register VX
  SETVXORVY,  // Set VX to VX OR VY
  SETVXANDVY, // Set VX to VX AND VY
  SETVXXORVY, // Set VX to VX XOR VY
  ADDVYVX,    // Add the value of register VY to register VX
              // Set VF to 01 if a carry occurs
              // Set VF to 00 if a carry does not occur
  SUBVYVX,    // Subtract the value of register VY from register VX
              // Set VF to 00 if a borrow occurs
              // Set VF to 01 if a borrow does not occur
  STRVYRSHFT1VX, // Store the value of register VY shifted right one bit in
                 // register VX¹ Set register VF to the least significant bit
                 // prior to the shift VY is unchanged
  SETVXSUBVY,    // Set register VX to the value of VY minus VX
                 // Set VF to 00 if a borrow occurs
                 // Set VF to 01 if a borrow does not occur
  STRVYLSHFT1VX, // Store the value of register VY shifted left one bit in
                 // register VX¹ Set register VF to the most significant bit
                 // prior to the shift VY is unchanged
  SKIPVXNEQVY, // Skip the following instruction if the value of register VX is
               // not equal to the value of register VY
  STRI,        // Store memory address x in register I (accepts an argument)
  JUMPV0,      // Jump to address x + V0 (accepts an argument)
  RAND, // Set VX to a random number with a mask of x (accepts an argument)
  DRAW, // Draw a sprite at position VX, VY with N bytes of sprite data starting
        // at the address stored in I
        // Set VF to 01 if any set pixels are changed to unset, and 00 otherwise
  SKIPKEYPRESS,    // Skip the following instruction if the key corresponding to
                   // the hex value currently stored in register VX is pressed
  SKIPKEYNOTPRESS, // Skip the following instruction if the key corresponding to
                   // the hex value currently stored in register VX is pressed
  STRVXDT,         // Store the current value of the delay timer in register VX
  STRVXWAITKEYPRESS, // Store the current value of the delay timer in register
                     // VX
  SETDTVX,           // Set the delay timer to the value of register VX
  SETSTVX,           // Set the sound timer to the value of register VX
  ADDIVX,            // Add the value stored in register VX to register I
  SETIVX, // Set I to the memory address of the sprite data corresponding to the
          // hexadecimal digit stored in register VX
  STRBCD, // Store the binary-coded decimal equivalent of the value stored in
          // register VX at addresses I, I + 1, and I + 2
  SAVE,   // Store the values of registers V0 to VX inclusive in memory starting
          // at address I
          // I is set to I + X + 1 after operation²
  FILL,   // Fill registers V0 to VX inclusive with the values stored in memory
          // starting at address I I is set to I + X + 1 after operation²
} Opcodes;

#endif // CHIP8_H
