#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// XORShift parameters
unsigned long xor_state = 1;

// XORShift PRNG function
unsigned long xor128(void) {
    unsigned long x = xor_state;
    x ^= x << 21;
    x ^= x >> 35;
    x ^= x << 4;
    xor_state = x;
    return x;
}

int main() {
    // Use time() to generate a seed based on current time
    unsigned long seed = (unsigned long)time(NULL);

    // Set seed for XORShift PRNG
    xor_state = seed;

    // Generate and print pseudorandom numbers
    printf("Random numbers generated using XORShift PRNG:\n");
    for (int i = 0; i < 10; i++) {
        printf("%lu\n", xor128());
    }

    return 0;
}
