// test_serial_multiplication.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_arithmetic_operations.h"

#define OPERAND_LENGTH 8U

int main()
{
  char first_operand[]  = "00000011";
  char second_operand[] = "00000010";
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

  free(product);

  return 0;
}
