int main(void) {
    *(int*)0 = 1;   // write to NULL -> segfault
    return 0;
}


//gcc -g -O0 -o crash coredump.c
//ulimit -c unlimited
//./crash
//coredumpctl list
//coredumpctl gdb <PID>
