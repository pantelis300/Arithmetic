// test_ripple_addition.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "binary_arithmetic_operations.h"

#define OPERAND_LENGTH 8U

void test_full_adder();

int main()
{
  char first_operand[]  = "00000011";
  char second_operand[] = "00000010";
  char *product;
  char carry_out;

  test_full_adder();
  
  product = ripple_binary_addition
  (
    first_operand, 
    second_operand, 
    &carry_out, 
    OPERAND_LENGTH);

  printf("Addition: %s + %s = %s, carry_out = %c\n",
          first_operand, second_operand, product, carry_out);
  free(product);
  return 0;
}


void test_full_adder()
{
  full_adder_output_t actual_full_adder_out;
  // A + B + Cin
  // 0 + 0 + 0 = 0, carry_out = 0
  actual_full_adder_out = full_adder(0, 0, 0);
  assert(actual_full_adder_out.sum == 0);
  assert(actual_full_adder_out.carry_out == 0);
  // 0 + 0 + 1 = 1, carry_out = 0
  actual_full_adder_out = full_adder(0, 0, 1);
  assert(actual_full_adder_out.sum == 1);
  assert(actual_full_adder_out.carry_out == 0);
  // 0 + 1 + 0 = 1, carry_out = 0
  actual_full_adder_out = full_adder(0, 1, 0);
  assert(actual_full_adder_out.sum == 1);
  assert(actual_full_adder_out.carry_out == 0);
  // 0 + 1 + 1 = 0, carry_out = 1
  actual_full_adder_out = full_adder(0, 1, 1);
  assert(actual_full_adder_out.sum == 0);
  assert(actual_full_adder_out.carry_out == 1);
  // 1 + 0 + 0 = 1, carry_out = 0
  actual_full_adder_out = full_adder(1, 0, 0);
  assert(actual_full_adder_out.sum == 1);
  assert(actual_full_adder_out.carry_out == 0);
  // 1 + 0 + 1 = 0, carry_out = 1
  actual_full_adder_out = full_adder(1, 0, 1);
  assert(actual_full_adder_out.sum == 0);
  assert(actual_full_adder_out.carry_out == 1);
  // 1 + 1 + 0 = 0, carry_out = 1
  actual_full_adder_out = full_adder(1, 1, 0);
  assert(actual_full_adder_out.sum == 0);
  assert(actual_full_adder_out.carry_out == 1);
  // 1 + 1 + 1 = 0, carry_out = 1
  actual_full_adder_out = full_adder(1, 1, 1);
  assert(actual_full_adder_out.sum == 1);
  assert(actual_full_adder_out.carry_out == 1);
}
