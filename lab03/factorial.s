.globl factorial

.data
n: .word 8

.text
# Don't worry about understanding the code in main
# You'll learn more about function calls in lecture soon
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

# factorial takes one argument:
# a0 contains the number which we want to compute the factorial of
# The return value should be stored in a0
factorial:
    addi t0, x0, 1    # Initialize t0 to 1 (for the result)
    Loop:
        beq a0, x0, Final  # If a0 is 0, go to Final (factorial(0) = 1)
        mul t0, t0, a0     # Multiply t0 by a0 (accumulate result)
        addi a0, a0, -1    # Decrement a0 by 1
        j Loop             # Repeat the loop
    Final:
        mv a0, t0          # Move result from t0 to a0
        jr ra  
