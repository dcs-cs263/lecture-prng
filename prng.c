#include <stdio.h>

char state = 0b1101100;
int count[128];

void shift() {
    // retrieve the three bits
    char a = (state & 0b0001000) >> 3;
    char b = (state & 0b0000100) >> 2;
    char c = (state & 0b0000010) >> 1;

    // calculate the new bit
    char n = a ^ (b ^ c);

    // update the register
    state = (state >> 1) | (n << 6);
}

char random() {
    shift();
    return state;
}

int main() {
    int i = 1000;
    int nonZero = 0;

    // generate i-many random numbers
    for(;i>0;i--) {
        char n = random();

        // increment the counter for n
        count[n]++;
    }

    // print the results
    for(i=0;i<128;i++) {
        printf("count[%d]=%d\n", i, count[i]);
        if(count[i] > 0) nonZero++;
    }

    // print the number of non-zero counts
    printf("Non-zero: %d\n", nonZero);

    // success
    return 0;
}
