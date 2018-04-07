// binary_arithmetic_operations.c

#include "binary_arithmetic_operations.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#ifdef DEBUG
  #define D
#else
  #define D for (;0;)
#endif

/**
 * Allocate operand_len consecutive bytes of memory in the heap
 * and fill it with the character '0'. It is used to represent
 * a binary number with operand_len.
 * e.g., for operand_len = 4, we get the array:
 *  '0', '0', '0', '0', '\0'
 *
 * INPUT
 *  size_t operand_len : number of bits of a binary number
 * RETURN
 *  a null terminated string containing operand_len '0' 
 *  characters
 */  
static char *initialize_with_zeros(const size_t operand_len)
{
  char *buffer = (char *)malloc(operand_len+1);
  buffer = memset(buffer, '0', operand_len);
  buffer[operand_len] = '\0';
  return buffer;
}


char *serial_binary_multiplication
(
  const char *first_operand,
  const char *second_operand,
  const size_t operand_len
)
{
  assert(strlen(first_operand) == operand_len);
  assert(strlen(second_operand) == operand_len);

  return NULL;
}

char *ripple_binary_addition
(
  const char *first_operand,
  const char *second_operand,
  char *carry_out,
  const size_t operand_len
)
{
  assert(strlen(first_operand) == operand_len);
  assert(strlen(second_operand) == operand_len);

  char *sum = initialize_with_zeros(operand_len); 
  char full_adder_carry_in = 0;
  full_adder_output_t full_adder_output;

  for (int i = operand_len - 1; i >= 0; i--)
  {
    D printf("First  %i  ", first_operand[i] - '0');
    D printf("Second %i  ", second_operand[i] - '0'); 
    D printf("Carry_in %i\n", full_adder_carry_in); 
    full_adder_output = full_adder
                        (
                          first_operand[i] - '0',
                          second_operand[i] - '0',
                          // In first iteration carry_in is 0
                          full_adder_carry_in
                        );
    sum[i] = full_adder_output.sum + '0';
    full_adder_carry_in = full_adder_output.carry_out;
    D printf("Sum = %i\n", full_adder_output.sum);
    D printf("Carry_out %i\n", full_adder_output.carry_out);
  }
  *carry_out = full_adder_output.carry_out + '0';
  return sum; 
}


full_adder_output_t full_adder(char a, char b, char carry_in)
{
  full_adder_output_t result;
  result.sum = (a + b + carry_in) % 2;
  result.carry_out = (a + b + carry_in) / 2;
  return result;
}
