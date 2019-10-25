# Ex 9 

In a two's complement number system, `x &= (x-1)` deletes the rightmost 1-bit in `x`. Explain why. Use this observation to write a faster version of `bitcount()`.


__A:__ If `x` is even, then `x-1` will clear the rightmost 1-bit to 0, and set the rest of the bits to the right to 1. An AND operation will return 0 and keep the rest of the bits.

If `x` is odd then it will set the rightmost bit to 0. 