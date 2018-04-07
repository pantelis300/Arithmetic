// binary_arithmetic_operations.h
//
// Interface functions for serial binary multiplication

#include <stdlib.h>

#ifndef __SERIAL_BINARY_MULTIPLICATION__
#define __SERIAL_BINARY_MULTIPLICATION__

typedef struct
{
  char sum;
  char carry_out;
} full_adder_output_t;


full_adder_output_t full_adder(char a, char b, char carry_in);


char *ripple_binary_addition
(
  const char *first_operand,
  const char *second_operand,
  char *carry_out,
  const size_t operand_len
);
  

char *serial_binary_multiplication
(
  const char *first_operand,
  const char *second_operand,
  const size_t operand_len
);

#endif
