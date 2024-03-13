.globl factorial

.data
n: .word 8

.text
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

factorial:
    addi t0, x0, 1    # Initialize the result (t0) to 1
    addi t1, x0, 1    # Initialize the counter (t1) to 1

factorial_loop:
    bgt t1, a0, end_factorial  # If the counter is greater than the input number, end the loop
    mul t0, t0, t1    # Multiply the result by the counter
    addi t1, t1, 1    # Increment the counter
    j factorial_loop  # Jump back to the start of the loop

end_factorial:
    addi a0, t0, 0    # Copy the result into a0 for returning
    jr ra             # Return from the function
