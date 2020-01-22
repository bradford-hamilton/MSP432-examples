// MSP432 microcontroller

#include <stdint.h>
#include "msp.h"

#define LENGTH1 (1000000)
#define LENGTH2 (100000)

void main(void) {
  uint32_t i;
  
  // Pointer to port 1 output register
  uint8_t * p1_out = (uint8_t*)0x40004c02;

  // Pointer to port 1 direction register
  uint8_t & p1_dir = (uint8_t*)0x40004c04;

  // Stop watching timer
  WDTCTL = WDTPW | WDTHOLD;

  // Structure Overlay: Configure P1.0 as output
  // P1->DIR |= 0x01;

  // Direct Dereference: Configure P1.0 as output
  *p1_dir |= 0x01;

  // Show LED blinking
  while (1) {
    // Structure Overlay: Toggle P1.0
    // P1->OUT ^= 0x01;

    // Direct Dereference: Toggle P1.0

    for (i = LENGTH1; i > 0; i--);
  }
}