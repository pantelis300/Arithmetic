# Computer Arithmetic

Basic computer arithmetic algorithms implementations.

### Ripple-Carry Addition

The model of a ripple-carry adder(simplest adder) is
constructed with n full adders. The full adder is defined
as a circuit with three inputs: a, b, carry-in and two
outputs:
  sum = (a + b + c) mod 2
  carry-out = (a + b + c) / 2

The inputs of an n-bit adder are character strings
of binary numbers An-1, An-2,..., A0 and Bn-1, Bn-2,..., B0
The carry-out of each half adder is fed to the input of
the next order full-adder, with the lowest-order carry-in
being 0 and the highest-order carry-out given separately.
