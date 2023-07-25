
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "binary_convert.h"

void print_equation(unsigned char x, unsigned char y, unsigned char r, char * op);

int main() {
    unsigned char x, y;
    x = 0x66;
    y = 0x39;

    unsigned char res;

    // BItwise AND
    res = x & y;
    print_equation(x, y, res, "&");

    res = x | y;
    print_equation(x, y, res, "|");

    res = x ^ y;
    print_equation(x, y, res, "^");

    res = ~y;
    print_equation(y, y, res, "~");

    res = x && y;
    print_equation(x, y, res, "&&");

    res = x || y;
    print_equation(x, y, res, "||");

}


void print_equation(unsigned char x, unsigned char y, unsigned char r, char * op) {
    char * bin_str;
    bin_str = char_to_bin_str(x);
    printf("%s %s\n", bin_str, op);
    free(bin_str);
    bin_str = char_to_bin_str(y);
    printf("%s\n", bin_str);
    free(bin_str);
    printf("---------\n");
    bin_str = char_to_bin_str(r);
    printf("%s     %x\n", bin_str, r);
    free(bin_str);
    printf("\n");
}
