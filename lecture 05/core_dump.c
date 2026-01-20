int main(void) {
    *(int*)0 = 1;   // write to address 0 -> segfault -> core dump
}

