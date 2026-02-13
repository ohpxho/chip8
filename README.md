# CHIP8

A chip 8 emulator in C.

### Notes

- CHIP-8 programs are strictly hexadecimal based. [1]
- Intructions are **two-bytes** in length and is represented using 4 hex digits. And stored in the memory in **big-endian** order. [1]

### Memory

- **0x000-0x1FF**: Reserved for the interpreter. [2]
- **0x200-0xFFF**: Program memory, where application code is loaded [2]
- **Font Data**: First 80 bytes store built-in hex font sprites for numbers and letters (0-F). [2]
- **The final 352 bytes of memory(starts at 0x6A0 for 2048 bytes of RAM) are reserved for varialbles and display refresh** (This segment of memory should be used by programs running on CHIP 8)

### Registers

- **16 8-bit general purpose registers (v0-vf)**
  - **vf** is a flag for checking carry or collisions. [2]
- **16-bit index register (I)**: For storing memory address
- **16-bit program counter (PC)**: Points to the current instruction

### Stack

- For handling subroutines
- It supports up to **16 level** of calls. [2]

### Display

- Graphics are rendered using prites
- Sprites are 8 pixels wide and 1-15 pixels in height.
- **Resolution**: 64x32 pixels
- No colors or monochrome
- Sprites are **XORed** with the existing screen pixels.

### Input

### Timers

### Reference

1. https://github.com/mattmikolay/chip-8/wiki
2. https://cfiraguston.medium.com/chip-8-a-classic-computing-simplicity-c2e314bd9803
3. Cowgod's CHIP-8 Technical Reference (pdf)
