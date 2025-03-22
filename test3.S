.section .data
  buffer:   .fill 256, 1, 0
  filename: .asciz "test3_6.txt"
  message:  .asciz "\nHello KSE!\n"
  new_line: .asciz "\n"

.section .text
  .global _start

_start:
    ldr x0, =buffer
    mov x1, #256
    mov x8, #17
    svc #0

    mov x0, #1
    ldr x1, =buffer
    mov x2, #20
    mov x8, #64
    svc #0

    mov x0, #1
    ldr x1, =new_line
    mov x2, #14
    mov x8, #64
    svc #0

    mov x0, #-100
    ldr x1, =filename
    mov x2, #0x241
    mov x3, #0755
    mov x8, #56
    svc #0
    mov x9, x0

    ldr x1, =message
    mov x2, #20
    mov x8, #64
    svc #0

    mov x0, x9
    mov x1, #0744
    mov x8, #52
    svc #0

    mov x0, x9
    mov x8, #57
    svc #0

    mov x0, #1
    mov x8, #93
    svc #0
