
CXX = gcc
CXXFLAGS = -Og -std=c99 -Wall -pedantic

all : test_ripple_addition test_serial_multiplication

test_serial_multiplication: test_serial_multiplication.o binary_arithmetic_operations.o
	$(CXX) $^ -o test_serial_multiplication

test_ripple_addition: test_ripple_addition.o binary_arithmetic_operations.o
	$(CXX) $^ -o test_ripple_addition

test_serial_multiplication.o: test_serial_multiplication.c binary_arithmetic_operations.h
	$(CXX) -c test_serial_multiplication.c

binary_arithmetic_operations.o: binary_arithmetic_operations.h
	$(CXX) -c binary_arithmetic_operations.c

clean:
	rm -f *.o
	rm test_ripple_addition test_serial_multiplication
