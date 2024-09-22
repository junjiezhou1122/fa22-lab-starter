#include <stdio.h>
#include "bit_ops.h"

/* Returns the Nth bit of X. Assumes 0 <= N <= 31. */
unsigned get_bit(unsigned x, unsigned n) {
    /* YOUR CODE HERE */
    unsigned r = x >> n ;
    r = r & 1;
    return r ; /* UPDATE WITH THE CORRECT RETURN VALUE*/
}

/* Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1 */
void set_bit(unsigned *x, unsigned n, unsigned v) {
    if (v) {
        // Set the nth bit to 1
        *x |= (1U << n);
    } else {
        // Set the nth bit to 0
        *x &= ~(1U << n);
    }
}

/* Flips the Nth bit in X. Assumes 0 <= N <= 31.*/
void flip_bit(unsigned *x, unsigned n) {
    /* YOUR CODE HERE */
    // *x ^= (1U << n); 
    unsigned v = get_bit(*x, n);
    if (v == 1) {
        set_bit(x, n, 0);
    } else {
        set_bit(x, n ,1);
    }
}

