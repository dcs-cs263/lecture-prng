#include <stdio.h>

char state = 0b1101100;

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
    // generate a new random number
    char a = random();
    char b = random();
    char c = random();

    // print the result
    printf("The random number is: %d!\n", a);

    // success
    return 0;
}
