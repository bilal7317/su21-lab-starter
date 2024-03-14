.text 
.align 2         
# Begin code section

main:
    
    la t1, num                  # Load the address of 'num' into t1
    lw a1, 0(t1)                # Load the value of 'num' into a1
    
    la s1, result               # Load the address of 'result' into s1

    call factorial              # Call the 'factorial' function
    
    sw a0, 0(s1)                # Store the calculated factorial in 'result'
    
    j write_tohost              # Jump to 'write_tohost'

factorial:
    
    # Input: n in a1, Output: n! in a0

    addi  sp, sp, -8            # Reserve space on the stack
    sw ra, 0(sp)                # Preserve the return address
    li t0, 1                    # Temporary value for checking if num <= 1
    ble a1, t0, return_1        # If num is 0 or 1, return 1
    sw a1, 4(sp)                # Push 'num' onto the stack
    addi a1, a1, -1             # Compute num-1 for the next recursive call
    call factorial              # Recursive call to 'factorial' with num-1
    lw t0, 4(sp)                # Load 'num' into t0
    mul a0, t0, a0              # Compute num * factorial(num-1)
    j done                      # Jump to 'done'
    
return_1:
    li a0, 1                    # Return 1

done:
    lw ra, 0(sp)                # Restore the return address from the stack
    addi sp, sp, 8              # Free the reserved stack space
    ret                         # Return to the caller

# End code section

write_tohost:

li x1, 1

sw x1, tohost, t5

j write_tohost

.data 

# Begin data section
num: .word 8
result: .word 0

# End data section

.align 12

.section ".tohost","aw",@progbits;                            

.align 4; .global tohost; tohost: .dword 0;                     

.align 4; .global fromhost; fromhost: .dword 0;

