// binary_arithmetic_operations.h
//
// Interface functions for serial binary multiplication

#include <stdlib.h>

#ifndef __SERIAL_BINARY_MULTIPLICATION__
#define __SERIAL_BINARY_MULTIPLICATION__

#ifdef DEBUG
  #define D
#else
  #define D for (;0;)
#endif

typedef struct
{
  char sum;
  char carry_out;
} full_adder_output_t;


/**
 * Function: initialize_with_zeros
 * -------------------------------
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
char *initialize_with_zeros(const size_t operand_len);

/**
 * Function: full_adder
 * --------------------
 * Implements the full-adder's functionality.
 *
 * INPUTS
 *  char a : first operand can only be 0 or 1
 *  char b : second operand can only be 0 or 1
 *  char carry_in: carry-in can only be 0 or 1
 * OUTPUT
 *  full_adder_output_t struct containing the two ouputs:
 *  char sum and char carry_out
 */
full_adder_output_t full_adder(char a, char b, char carry_in);

/**
 * Function: ripple_binary_addition
 * --------------------------------
 * Implements the ripple-carry adder's functionality.
 *
 * INPUTS
 *  char *first_operand : a null terminated string containing
 *                        the binary representation of the
 *                        first operand with operand_len-bits
 *                        All characters must be '0' or '1'
 *  char *second_operand : a null terminated string containing
 *                        the binary representation of the
 *                        second operand with operand_len-bits
 *                        All characters must be '0' or '1'
 *  char *carry_out : a reference to the carry_out of the adder
 *  operand_len : the number of bits (size of strings) 
 *                of the two operands
 * RETURNS
 *  a null terminated string of size operand_len-bits
 *  representing the sum of the input operands.
 */
char *ripple_binary_addition
(
  const char *first_operand,
  const char *second_operand,
  char *carry_out,
  const size_t operand_len
);
  
/**
 * Function: serial_binary_multiplication
 * --------------------------------------
 * Implements the radix-2 multiplication.
 *
 * INPUTS
 *  char *first_operand : a null terminated string containing
 *                        the binary representation of the
 *                        first operand with operand_len-bits
 *  char *second_operand : a null terminated string containing
 *                        the binary representation of the
 *                        second operand with operand_len-bits
 *  operand_len : the number of bits (size of strings) 
 *                of the two operands
 * RETURNS
 *  a null terminated string of size (2*operand_len)-bits
 *  representing the product of the input operands.
 */
char *serial_binary_multiplication
(
  const char *first_operand,
  const char *second_operand,
  const size_t operand_len
);

#endif
