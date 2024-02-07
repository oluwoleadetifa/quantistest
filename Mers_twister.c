#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Mersenne Twister parameters
#define MT_N 624
#define MT_M 397
#define MT_MATRIX_A 0x9908b0dfUL
#define MT_UPPER_MASK 0x80000000UL
#define MT_LOWER_MASK 0x7fffffffUL
#define MT_TEMPERING_MASK_B 0x9d2c5680UL
#define MT_TEMPERING_MASK_C 0xefc60000UL
#define MT_TEMPERING_SHIFT_U(y) (y >> 11)
#define MT_TEMPERING_SHIFT_S(y) (y << 7)
#define MT_TEMPERING_SHIFT_T(y) (y << 15)
#define MT_TEMPERING_SHIFT_L(y) (y >> 18)

unsigned long mt[MT_N];
int mti = MT_N + 1;

// Initialize the PRNG with a seed
void init_genrand(unsigned long s) {
    mt[0] = s & 0xffffffffUL;
    for (mti = 1; mti < MT_N; mti++) {
        mt[mti] = (1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti);
        mt[mti] &= 0xffffffffUL;
    }
}

// Generate a pseudorandom unsigned long integer
unsigned long genrand_int32(void) {
    unsigned long y;
    static unsigned long mag01[2] = {0x0UL, MT_MATRIX_A};

    if (mti >= MT_N) {
        int kk;

        if (mti == MT_N + 1)
            init_genrand(5489UL);

        for (kk = 0; kk < MT_N - MT_M; kk++) {
            y = (mt[kk] & MT_UPPER_MASK) | (mt[kk + 1] & MT_LOWER_MASK);
            mt[kk] = mt[kk + MT_M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (; kk < MT_N - 1; kk++) {
            y = (mt[kk] & MT_UPPER_MASK) | (mt[kk + 1] & MT_LOWER_MASK);
            mt[kk] = mt[kk + (MT_M - MT_N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[MT_N - 1] & MT_UPPER_MASK) | (mt[0] & MT_LOWER_MASK);
        mt[MT_N - 1] = mt[MT_M - 1] ^ (y >> 1) ^ mag01[y & 0x1UL];
        mti = 0;
    }

    y = mt[mti++];
    y ^= MT_TEMPERING_SHIFT_U(y);
    y ^= MT_TEMPERING_SHIFT_S(y) & MT_TEMPERING_MASK_B;
    y ^= MT_TEMPERING_SHIFT_T(y) & MT_TEMPERING_MASK_C;
    y ^= MT_TEMPERING_SHIFT_L(y);

    return y;
}

int main() {
    // Use time() to generate a seed based on current time
    unsigned long seed = (unsigned long)time(NULL);

    // Initialize PRNG with the generated seed
    init_genrand(seed);

    // Generate and print pseudorandom numbers
    printf("Random numbers generated using Mersenne Twister PRNG:\n");
    for (int i = 0; i < 10; i++) {
        printf("%lu\n", genrand_int32());
    }

    return 0;
}
