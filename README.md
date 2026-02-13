# CHIP8

A chip 8 interpreter in C.

> Chip-8 is a simple, interpreted, programming language which was first used on some do-it-yourself computer systems in the late 1970s and early 1980s. [3]

### Notes

- CHIP-8 programs are strictly hexadecimal based. [1]
- Intructions are **two-bytes** in length and is represented using 4 hex digits. And stored in the memory in **big-endian** order. [1]

### Memory

- **4KB (4,096 bytes)** in size
- **0x000-0x1FF**: Reserved for the interpreter. [2]
- **0x200-0xFFF**: Program memory, where application code is loaded [2]
- **Font Data**: First 80 bytes store built-in hex font sprites for numbers and letters (0-F). [2]
- **The final 352 bytes of memory are reserved for varialbles and display refresh** (This segment of memory should be used by programs running on CHIP 8)

```
+------------------+ 0xFFF (4095) End of Chip-8 RAM
|                  |
|                  |
|                  |
|   Chip-8         |
|   Program/Data   |
|   Space          |
|   0x200-0xFFF    |
|                  |
|                  |
|                  |
+- - - - - - - - - + 0x600 (1536) Start of ETI 660 Chip-8 programs
|                  |
|                  |
+------------------+ 0x200 (512) Start of most Chip-8 programs
|                  |
|   Reserved for   |
|   Interpreter    |
|   0x000-0x1FF    |
|                  |
+------------------+ 0x000 (0) Start of Chip-8 RAM

(Cowgod's CHIP-8 Technical Reference)
```

### Registers

- **16 8-bit general purpose registers (v0-vf)**
  - **vf** is a flag for checking carry or collisions. [2]
- **16-bit index register (I)**: For storing memory address
- **16-bit program counter (PC)**: Points to the current instruction
- **16-bit stack pointer (SP)**: Point to the most top level of the stack.
- **2 8-bit for sound and delay time**: When non-zero, they are automatically decremented at a rate of 60Hz

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

- **16 key** hexadecimal keypad

```
+---+---+---+---+
| 1 | 2 | 3 | C |
+---+---+---+---+
| 4 | 5 | 6 | D |
+---+---+---+---+
| 7 | 8 | 9 | E |
+---+---+---+---+
| A | 0 | B | F |
+---+---+---+---+
```

### Timers

#### Delay

- The delay timer is active whenver the delay timer is not zero.
- It does nothing but subtract one to the dt register until it reaches 0 at rate of 60hz.

#### Sound

- The sound timer is active whenver the sound timer is not zero.
- Decrements the st register by one until it reaches 0.
- When st is not zero, the chip 8 buzzer will sound whatever that is.

### Reference

1. https://github.com/mattmikolay/chip-8/wiki
2. https://cfiraguston.medium.com/chip-8-a-classic-computing-simplicity-c2e314bd9803
3. Cowgod's CHIP-8 Technical Reference (pdf)
