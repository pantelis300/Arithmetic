// test_ripple_addition.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include "binary_arithmetic_operations.h"
#include "conversions.h"

#define OPERAND_LENGTH 8U

void test_full_adder();
void test_ripple_binary_addition();
void test_conversions();

int main()
{
  test_full_adder();
  test_conversions();
  test_ripple_binary_addition();
  printf("test_ripple_adder: ALL TESTS PASSED\n");
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
  printf("test_full_adder: ALL TESTS PASSED\n");
}


void test_ripple_binary_addition()
{
  uint64_t first_uint, second_uint, expected_sum_uint;
  char *first_binary; 
  char *second_binary; 
  char *actual_sum_binary;
  uint64_t actual_sum_uint;
  char carry_out;

  const uint16_t MAX_UINT = 1 << (OPERAND_LENGTH-1);
  for (first_uint = 0; first_uint < MAX_UINT; first_uint++)
  {
    for (second_uint = 0; second_uint < MAX_UINT; second_uint++)
    {
      expected_sum_uint = first_uint + second_uint;
      D printf("expected_sum_uint: %llu + %llu = %llu\n",
        (long long unsigned)first_uint,
        (long long unsigned)second_uint,
        (long long unsigned)expected_sum_uint);
      first_binary = uint2binary(first_uint, OPERAND_LENGTH); 
      second_binary = uint2binary(second_uint, OPERAND_LENGTH); 
      actual_sum_binary = ripple_binary_addition
                            (
                              first_binary,
                              second_binary,
                              &carry_out,
                              OPERAND_LENGTH
                            );
      D printf("actual_sum_binary: %s + %s = %s",
              first_binary, second_binary, actual_sum_binary);
      actual_sum_uint = binary2uint(actual_sum_binary,
                                      OPERAND_LENGTH);
      free(actual_sum_binary);
      free(first_binary);
      free(second_binary);
      D printf(" - actual_sum_uint: %llu\n", 
              (long long unsigned)actual_sum_uint);
      assert(actual_sum_uint == expected_sum_uint);
    }
  }
  printf("test_ripple_binary_addition: ALL TESTS PASSED\n");
}


void test_conversions()
{
  int uint;
  char *binary_num;
  for (uint = 0; uint < 256; uint++)
  {
    binary_num = uint2binary(uint, OPERAND_LENGTH);
    D printf("\n%3d = %s\n", uint, binary_num);
    assert(binary2uint(binary_num, strlen(binary_num)) == uint);
    free(binary_num);
  }
  printf("test_conversions: ALL TESTS PASSED\n");
}
