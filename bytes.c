/*
 * Program to experiment with different data, displayinb their bytes
 * Some code comes from Bryant & Halloran
 * Modified 2023: Susan Fox
 */

#include <stdio.h>   // printf
#include <string.h>  // strlen

#include "show_bytes.h"

void test_show_bytes(int val);

/*
 */
int main() {
    int val;
    
    val = 0xAABBCCDD;
    printf("\n-------- %x -------\n", val);
    printf("test_show_bytes(val):\n");
    test_show_bytes(val);
    printf("showbyte_at_a_time(val):\n");
    show_byte_at_a_time(val);

    val = 0x87654321;
    printf("\n-------- %x -------\n", val);
    printf("test_show_bytes(val):\n");
    test_show_bytes(val);
    printf("showbyte_at_a_time(val):\n");
    show_byte_at_a_time(val);

	val = 0x12345678;
    printf("\n-------- %x -------\n", val);
    printf("test_show_bytes(val):\n");
    test_show_bytes(val);
    printf("showbyte_at_a_time(val):\n");
    show_byte_at_a_time(val);

    short sval = 0x30FF;
    printf("\n-------- %x -------\n", sval);
    printf("calling show_twos_comp\n");
    show_twos_comp(sval);

  	const char *s = "ABCDEF";
    printf("\n-------- %s -------\n", s);
	show_bytes((byte_pointer) s, strlen(s)); 

    s = "abcedef";
    printf("\n-------- %s -------\n", s);
	show_bytes((byte_pointer) s, strlen(s)); 


    return 0;
}



/*
 *  Given an integer, show the hexadecimal values of each byte of these values:
 *    1. the int itself
 *    2. the int after being cast to a float  (a potentially dangerous operation)
 *    3. the pointer where this int is stored in memory
 */
void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}
