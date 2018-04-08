// binary_arithmetic_operations.c

#include "binary_arithmetic_operations.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

char *initialize_with_zeros(const size_t operand_len)
{
  char *buffer = (char *)malloc(operand_len+1);
  buffer = memset(buffer, '0', operand_len);
  buffer[operand_len] = '\0';
  return buffer;
}


static char *shift_register_right_one_pos
(
  char *register_to_shift,
  char new_most_significant_bit,
  size_t register_len
)
{
  D printf("shift_reg(): reg initialy: %s\n", register_to_shift);
  for (int i = register_len-1; i >= 1; i--)
  {
    register_to_shift[i] = register_to_shift[i-1];
    D printf("shift_reg(): reg %i-iter:   %s\n", i, register_to_shift);
  }
  register_to_shift[0] = new_most_significant_bit;
  return register_to_shift;
}


char *concatenate_two_strings
(
  const char *first_str,
  const char *second_str
)
{
  size_t first_str_len  = strlen(first_str);
  size_t second_str_len = strlen(second_str);
  size_t i;
  char *concat_str = initialize_with_zeros(first_str_len +
                                           second_str_len);

  for (i = 0; i < first_str_len; i++)
    concat_str[i] = first_str[i];

  for (i = 0; i < second_str_len; i++)
    concat_str[first_str_len + i] = second_str[i];

  return concat_str;
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

  char *product_register = initialize_with_zeros(operand_len);
  char *first_op_register = strndup(first_operand, operand_len);
  char *second_op_register = strndup(second_operand, operand_len);
  char carry_out;

  for (int i = 0; i < operand_len; i++)
  {
    char first_operand_least_significant_bit = 
                    first_op_register[operand_len-1];

    if (first_operand_least_significant_bit == '1')
    {
      product_register = ripple_binary_addition
                         (
                           product_register,
                           second_op_register,
                           &carry_out,
                           operand_len
                         );
    }                     
    char product_least_significant_bit = 
                    product_register[operand_len-1];

    product_register = shift_register_right_one_pos
                       (
                         product_register,
                         carry_out,
                         operand_len
                       );
    first_op_register = shift_register_right_one_pos
                        (
                          first_op_register,
                          product_least_significant_bit,
                          operand_len
                        );
                     
    D printf("serial_binary_multiplication() %i-iter:\n", i);
    D printf("first_op_register: %s\n", first_op_register);
    D printf("second_op_register: %s\n", second_op_register);
    D printf("product_register: %s\n", product_register);
  }

  char *final_product = concatenate_two_strings
                        (
                          product_register, 
                          first_op_register
                        );
  D printf("final_product: %s\n", final_product);

  free(first_op_register);
  free(second_op_register);
  free(product_register);
  return final_product;
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
    D printf("Carry_out  = %i\n", full_adder_output.carry_out);
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
