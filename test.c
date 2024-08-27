#include <stdio.h>

int main() {
    unsigned int value = 255;  // 初期値1（二進数では00000001）

    printf("Initial value: %u\n", value);

    // 1ビット左にシフト
    value = value << 16;
    printf("After 1-bit left shift: %u\n", value);  // 2（二進数では00000010）

    // さらに2ビット左にシフト
    value = value << 2;
    printf("After 2-bit left shift: %u\n", value);  // 8（二進数では00001000）

    // さらに3ビット左にシフト
    value = value << 3;
    printf("After 3-bit left shift: %u\n", value);  // 64（二進数では01000000）

    // 8ビット左にシフト
    value = value << 8;
    printf("After 8-bit left shift: %u\n", value);  // 16384（二進数では0100000000000000）

    return 0;
}
