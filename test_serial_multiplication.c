// test_serial_multiplication.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include "binary_arithmetic_operations.h"
#include "conversions.h"

#define OPERAND_LENGTH 8U

int main()
{
  char first_operand[]  = "00000011";
  char second_operand[] = "00000110";
  char *product;
  char carry_out;

  printf("First Operand:  %s\n", first_operand);
  printf("Second Operand: %s\n", second_operand);

  product = serial_binary_multiplication
            (
              first_operand,
              second_operand,
              OPERAND_LENGTH
            );
  printf("Serial Multiplication: ");
  printf("%s * %s = %s = ",
      first_operand, second_operand, product);
  printf("%llu\n", 
    (long long unsigned)binary2uint(product, 2*OPERAND_LENGTH));
  return 0;
}
