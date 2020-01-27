#include <stdint.h>
#include "msp.h"
#include "memory.h"

// Constants
#define ARRAY_MAX (16)
#define MEMOVE_LENGTH (8)
#define LENGTH1 (100000)
#define LENGTH2 (10000)

// Function prototype for a simple LED blink function that doesn't return
void blink_led_forever();

// Source array for memory move
uint8_t array1 [ARRAY_MAX];

// Desination array for memory move
uint8_t array2 [ARRAY_MAX];

void main(void) {
  volatile uint32_t i = 0;

  // Stop watchdog timer
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

  // Configure P1.0 as output
  P1->DIR |= BIT0;

  // Initialize memory for a memory dump debugging example
  for (i = 0; i < ARRAY_MAX; i++) {
    array[i] = i;
  }
  my_memset(array2, ARRAY_MAX, 0xff);

  // Create a NOP instruction for a breakpoint;
  __NOP();
  
  my_memmove(array1, array2, MEMOVE_LENGTH);

  // Create a NOP instruction for a breakpoint
  __NOP();

  // This code does not return
  blink_led_forever();
}

void led_blink_forever() {
  uint32_t i;

  // Infinite loop that toggles P1.0 (LED) followed by a small delay, creating an infinite blink
  while (1) {
    P1->OUT ^= BIT0;               // Toggle P1.0 on/off using XOR
    for (i = LENGTH1; i > 0; i--); // Delay
  }
}