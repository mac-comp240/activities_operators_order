# Data Activity 7: Operators and Byte Order
## Put your name(s) here

In this activity, you will explore the bitwise and logical operators, shifting, and integer byte order.
- You will create a C program from scratch to check bitwise and logical operators
- You will create a C program from scratch to ... shifting 
- ???
- You will update a Makefile to include multiple files and executables



## Provided Code

There are multiple code files for this activity, and you will create new files
as well! There are multiple executables generated by this code. You will update 
the Makefile so that we can make all the executables by running `make all`:

- `Makefile`
    - a makefile to automate the compilation process (you will need to update this)
- `binary_convert.c` and `binary_convert.h`
    - Library containing functions for converting numbers to a string of 0's and 1's
- `mask.c`
    - Starter code for experimenting with binary masks
- `shifts.c`
    - Starter code for experimenting with shift operators
- `bytes.c`
    - 
- `show-bytes.c`
    - A library file with code to display the bytes of an integer


### A Makefile for a multi-program project

When a single project has multiple executables, it is common to have one Makefile that can compile them all. By convention, we do this by making the default label in the file be `all`, with the executables as its dependencies. It comes first in the Makefile.

Thus to compile the whole project, including all executables, we use: `make` or `make all`

By convention, we also make a last label called `clean` which removes all the executables. We use `make clean` to tidy up the folder.

In between, each executable has its own label, dependencies and is then compiled based on its own indented command(s).

**You will edit the Makefile to make it have this behavior.**

Recall that Makefiles require a tab character before a command under a given target, 
not spaces. If you have trouble getting your Makefile to work and it *looks* correct, 
start by checking whether you have a tab or spaces!

## Your Tasks

### Task 1: Bit-wise vs. logical operators

**Problem Definition:** Suppose `x` and `y` are _unsigned integers one byte long_ , with the values 0x66 and
0x39 respectively. We want to understand how the bitwise and logical operators would work in combination on these values.

- First, look at the table below and work out, by hand, what the value of each expression should be.

<table border="0"> <tr> <th>Expression</th> <th>Value</th> </tr> <tr> <td>x &
y</td> <td></td> </tr> <tr> <td>x | y</td> <td></td> </tr> <tr> <td>~x | ~y</td>
<td></td> </tr> <tr> <td>x & !y</td> <td></td> </tr> <tr> <td>x && y</td>
<td></td> </tr> <tr> <td>x || y</td> <td></td> </tr> <tr> <td>!x || !y</td>
<td></td> </tr> <tr> <td>x && ~y</td> <td></td> </tr> </table>

- Create a new C code file named `bit_logical.c`. Be sure to include all the libraries you need, and include a `main` function defined as we have done in other code examples. You will need to include the `binary_convert.h` file.
    - Be sure to put your name and a description of the code at the 
top of the file
    - The `main` function should return 0 at the end
    - Think carefully about the **type** of `x` and `y`

- Modify the `Makefile` so that it compiles the `bit_logical.c` file and its helper `binary_convert.c` to an executable called `bit_logical`.

- Your `main` function should test each of the expressions in the table above. 
    - As a first step, write a series of `printf` statements,using the appropriate functions from `binary_convert.c` to generate the binary representation of `x`, `y`, and the result of the expression. Output the values in a format like the one shown below. (Avoid memory leaks!)
    - **I recommend that you write a helper function to print one operation (the 4 lines for each expression shown below)!**
    - Add `assert` statements for each expression, based on the result you calculatd earlier. Test to see if the results match!

```
0110 0110 & 
0011 1001 
---------
0010 0000     20

0110 0110 | 
0011 1001 
--------- 
0111 1111     7f

1001 1001 | 
1100 0110 
--------- 
1101 1111     df
```

    


### Task 2: Shifting

**Problem Definition:** You will predict and examine the effects of the shift operator on signed and unsigned integers, specifically the ones given in the table below.

<table> <tr> <td>x</td> <td></td> <td>x&lt&lt3</td> <td></td> <td>Logical
x>>2</td> <td></td> <td>Arithmetic y>>2</td> <td></td> </tr> <tr> <td>Hex</td>
<td>Binary</td> <td>Hex</td> <td>Binary</td> <td>Hex</td> <td>Binary</td>
<td>Hex</td> <td>Binary</td> </tr> <tr> <td>0xC3</td> <td></td> <td></td>
<td></td> <td></td> <td></td> <td></td> <td></td> </tr> <tr> <td>0x75</td>
<td></td> <td></td> <td></td> <td></td> <td></td> <td></td> <td></td> </tr> <tr>
<td>0x87</td> <td></td> <td></td> <td></td> <td></td> <td></td> <td></td>
<td></td> </tr> <tr> <td>0x66</td> <td></td> <td></td> <td></td> <td></td>
<td></td> <td></td> <td></td> </tr> </table>

- First, predict the values for the table above by hand
    - Assume that `x` is an unsigned integer one byte long
    - Assume that `y` holds the same binary value as `x`, just as a signed integer rather than an unsigned one

- Examine the starter code file, `shifts.c`
    - It contains code to print a version of the table above, just
    for the first row of the table
- Add the executable `shifts` to the Makefile, and the command to compile it (it should look similar to the `bit_logical` part)
    - Be sure to add `shifts` to the dependencies for `all` so that it is automatically compiled when we `make all`
- Compile and run `shifts.c` and observe the results

- Add to the code in `shifts.c` so that it prints all the examples from the table above
    - **Work smart!** Do not simply cut and paste the code that prints one line of the table. Instead, develop a function that can take in `x` and `y` and essentially does what the first example code does. Then call that function. Be sure to declare the function at the top of your file
    - **Work smarter!** (Optional) Improve your helper function sto have it take in 2 more parameters: how much to shift left and how much to shift right

- Add `assert` statements to check whether your by-hand values match the values computed by the program



### Task 3: Masking of bits

**Problem Definition:**  Given an unsigned int x and an unsigned int y, determine the C expression that
will yield an unsigned int consisting of the least significant byte of x and all but the least significant bytes of y. For example, if x is 0x03AABE41 and y is 0x082CE3F6, the resulting value would be 0x82CE341.

To do this, we will build **masks**, which are bit patterns, for example a series of ones followed by a series of zeros. We can then use bitwise operations between mask and number to isolate certain parts of the number, and to put together the final result.

- Examine the starter code file `masks.c`, and add an entry for an executable, `masks`, in the `Makefile` (similar to the previous tasks)

- Complete the definition of `least1x_most3y` to produce the correct result
    - Make an unsigned int called `mask` and use it with bitwise AND and bitwise OR, combined with `x` and `y`
    - return the final number

- Add tests of your function to `main`, using the test function     `testit`. Test thoroughly! Don't forget our mantra about
testing: try 0, 1, the maximum unsigned int, and several values in between.
    - Using hexadecimal numbers for the tests will make developing assertions easier.

### Task 4: Integer Byte Order

**Problem Description:** We want to explore how different bytes of data are ordered: `int`, floating-point, pointers, and strings. This code uses a library file containing functions for printing each byte of a piece of data, in the order the bytes are actually stored inside the computer.


- Read the code in `bytes.c` and its library, `show-bytes.c`.
- Add an entry to the Makefil to compile this program (model it on the `bit_logical` entry)
- Run the program, and compare its outputs to the code.
    - Answer this questions either here or in the Google Doc: Is this computer big-endian or little-endian?
    - What do you learn about `float` and pointer types from the output?
- The `show_twos_comp` function displays a `short` value and its negative; work out what the negative of the given value is, and double-check that the output is correct
- Examine the string outputs more closely
    - Open this [Manual page for ascii characters.](http://man7.org/linux/man-pages/man7/ascii.7.html) Make sure that your browser window is wide enough to display the acsii table nicely. This is from a typical linux manual page, or 'man page' for short. You can use this to see all of the ascii character codes
used in strings.  

The command `man` is short for manual.  It is used to provide more information
for various commands and other information in unix. You can try other commands
in your own terminal on the server, e.g.

	man gcc

	man ls

	man bash   (a long page about the terminal shell called bash that you are typing in)

	man man


Using `showbytes.c`, answer the following question in your text file:
  
* How is the storage of each byte of a string different from the storage of the
  bytes of an int? Consider the topic of Endianness again. Are strings Endian?

### Note

Strings have one extra character added to them called a *trailing null byte*.
The end of the string is signaled by having this one last character that is
always a zero, which is not used for any ascii character. All strings have this
and we need to account for it in our code, as we store strings as arrays of
characters.

Modify the function `string_leg()` to also print the trailing null byte of a
string. Discuss this with your neighbor--how should you do this? Also change the
string to add some other character from the ascii table other than a letter or
number. Verify that you observe the correct ascii code for it.

## 3.  Also try this: 

Try changing the printf statement in the `show_bytes` function to look like this:

	printf("%p\t0x%.2x\n",start+i, start[i]);

`%p` tells printf to print the pointer address. `start` is pointing to the
zeroth element of an array of bytes. 

Answer these questions in your text file:

* What does this changed print statement do?

* How is the value for the pointer increasing in this loop? Discuss in terms of
  bytes.

## 4. Make the code work for long ints

Add a function to show all the bytes of a `long` variable. Change `main()` to
use it.
