section .text
    global get42
    global my_strlen
    global my_putstr
    global my_strcmp

get42:
    push rbp
    mov rbp, rsp

    mov rax, 42
    leave
    ret

my_strlen:
    push rbp
    mov rbp, rsp

    mov rax, 0
    start_my_strlen:
    cmp byte [rdi], 0

    je end_my_strlen
    add rax, 1
    add rdi, 1
    jmp start_my_strlen
    
    end_my_strlen:
    leave
    ret

my_putstr:
    push rbp
    mov rbp, rsp

    mov r14, rdi
    start_my_putstr:
    cmp byte [r14], 0

    je end_my_putstr
    mov rax, 1
    mov rdi, 1
    mov rdx, 1
    mov rsi, r14
    add r14, 1
    syscall 
    jmp start_my_putstr

    end_my_putstr:
    leave
    ret

my_strcmp:
    push rbp
    mov rbp, rsp
    mov rax, 0

    start_my_strcmp:
    mov r9b, byte [rdi]
    cmp r9b, byte [rsi]

    jne end_my_strcmp
    
    check_null:
    cmp byte [rdi], 0

    je end_my_strcmp
    add rdi, 1
    add rsi, 1
    jmp start_my_strcmp

    end_my_strcmp:
    mov r8b, byte [rdi]
    sub r8b, byte [rsi]
    mov al, r8b
    leave
    ret

