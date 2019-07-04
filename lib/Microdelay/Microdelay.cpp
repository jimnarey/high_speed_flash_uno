#include <Arduino.h>
#include <Microdelay.h>

// 1 cycle takes 0.0000000625s
// 16 cycles takes 1us
// Assume a function takes 4 cycles (0.0000000625s) with no arguments
// 2 cycles to push each 8bit register from the CPU to memory and assume this happens for every byte passed as arguments
// 2 cycles to pull each saved byte from memory back to CPU registers


Microdelay::Microdelay()
{

}

void Microdelay::delay1us()
{
// 4 assumed cyles to call + 12
asm(
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    );
}

void Microdelay::delay2us()
{
// 4 assumed cyles to call + 28
asm(
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    );
}
void Microdelay::delay3us()
{
// 4 assumed cyles to call + 44
asm(
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    "nop \n"
    );
}