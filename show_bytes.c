/*
 * Library of functions to display the bytes of different kinds of
 * data. 
 * 
 *  original source:  Bryant and O'Hallaran
 *  updated by: Libby Shoop
 *  updated in 2023 by: Susan Fox
 */

#include <stdio.h>   // printf
#include <string.h>  // strlen


/****************  begin show-bytes section ********************************/
// This typedef is called byte pointer because an unsigned char is one byte
// and an unsigned char * is denoting a pointer to a byte
typedef unsigned char *byte_pointer; 

/*
 * Beginning at the byte pointed to by start, print the hexedecimal
 * values of the next len bytes.
 */
void show_bytes(byte_pointer start, int num_bytes) {
    int i;
    for (i = 0; i < num_bytes; i++)
		printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");

}

/*
 * Wrapper around show_bytes for an input integer parameter, x.
 * 
 */
void show_int(int x) {
    // since x is an int, &x is a pointer to its first byte
    // sizeof operator returns the number of bytes of the given type
    show_bytes((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

/*
 * Wrapper around show_bytes for an input float parameter, x.
 * 
 */
void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float)); //line:data:show_bytes_amp2
}

/*
 * Wrapper around show_bytes for an input void* parameter, x.
 * 
 * A pointer of type void * represents the address of an object in memory,
 * but not its type. Here we use it as a means of displaying the hexadecimal
 * value of the bytes representing an actual pointer to a position in memory.
 * 
 */
void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *)); //line:data:show_bytes_amp3
}

/****************  end show-bytes section   ***********************************/


/*
 *  What will the result of this function reveal about how the bytes of an
 *  integer are stored?
 */
void show_byte_at_a_time(int val) {
	byte_pointer valp = (byte_pointer) &val;
	show_bytes(valp, 1);   // Show one byte
	show_bytes(valp, 2);   // Show two bytes
	show_bytes(valp, 3);   // Show three bytes
	show_bytes(valp, 4);   // Show four bytes
}


/*
 *  negative values of short and int data types have
 *  two's complement representation.
 */
void show_twos_comp(short x) {
    short mx = -x; 
    
    show_bytes((byte_pointer) &x, sizeof(short)); 
    show_bytes((byte_pointer) &mx, sizeof(short)); 
}

