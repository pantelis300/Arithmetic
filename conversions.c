// conversions.c

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "binary_arithmetic_operations.h"

char *uint2binary(uint64_t uint, size_t binary_len)
{
  char *binary_num = initialize_with_zeros(binary_len);
  int bit_index = binary_len - 1;

  if (uint == 0) return binary_num;

  while (uint > 0)
  {
    assert(bit_index >= 0);
    binary_num[bit_index--] = (uint % 2) + '0';
    uint /= 2;
  }
  return binary_num; 
}

uint64_t binary2uint(const char *bin_num, size_t binary_len)
{
  uint64_t uint = 0;
  uint64_t coefficient = 1;

  uint = bin_num[binary_len-1] - '0';

  for (int i = binary_len-2; i >= 0; i--)
  {
    coefficient *= 2;
    uint += coefficient * (bin_num[i] - '0');
  }
  return uint;
}


  
