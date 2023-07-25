/*
 *  COMP 240 example code to illustrate how we can manipulate bytes in C
 *   and see how they are stored for various data types.
 *
 *  original author:  Bryant and O'Hallaran
 *  updated by: Libby Shoop
 *  updated 2023: Susan Fox
 */


// This typedef is called byte pointer because an unsigned char is one byte
// and an unsigned char * is denoting a pointer to a byte
typedef unsigned char *byte_pointer; 

// declarations from show-bytes.c
void show_bytes(byte_pointer start, int len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *x);
void show_byte_at_a_time(int val);
void show_twos_comp();
