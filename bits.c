/*
 * Assignment: Bit Twiddling
 * Class: CSC 252 Spring 2017
 *
 * Name: <Yujie Liu>
 * Partner's Name: <Po-Chun Chiu>
 *
 * TAs: Sayak Chakraborti (schakr11@cs.rochester.edu)
 *      Kevin Gerami(kgerami@u.rochester.edu)
 *
 * Instructions:
 * Fill in the following functions and turn this file in.
 *
 * Restrictions:
 * You MAY NOT change any of the function defintions.
 * You MAY NOT define any global variables, macros, or other functions.
 * You MAY NOT use any operations not listed in the function's description.
 * You MAY NOT use any control statements (if, loops, switch, function calls).
 * You MAY NOT use any constants outside of an unsigned byte (0 - 255 (0xFF) inclusive).
 * You MAY NOT cast any variables.
 * You MAY NOT use data types other than ints.
 *
 * You MAY define local variables.
 * You MAY use the assignment versions of allowed operators (+=, |=, etc).
 * You MAY use more than one operator per line.
 *
 * Your results will be tested on a machine that:
 * Uses 2s complement, 32-bit representations of integers.
 * Performs right shifts arithmetically.
 * Has unpredictable behavior when shifting an integer by more than the word size.
 * Bits are 0-indexed and numbered in order of increasing significance (right-to-left) so the 0th bit is the rightmost bit.
 *
 * If any of the instructions or function descriptions are unclear please contact the TA (see
 * above).
 */

/*
 * evenBits: Return the word with all even-numbered bits set to 1.
 *   Legal ops: ! ~ & ^ | + << >>
 */
int evenBits(void) {
    int x = 85; //01010101
    return x | x << 8 | x << 16 | x << 24;
}

/*
 * bitAnd: Compute the bitwise-and of x and y.
 *   Example: bitAnd(3, 5) = 1
 *   Legal ops: ~ |
 */
int bitAnd(int x, int y) {
    int a = (~x)|(~y);
    return ~a;
}

/*
 * swapBytes: Swap the 0th (rightmost) and 2nd bytes of x.
 *   Example: swapBytes(0x33221100) = 0x33001122
 *   Legal ops: ! ~ & ^ | + << >>
 */
int swapBytes(int x) {
    int mask1 = 255;
    int mask2 = 255 << 16;
    int temp1 = x & mask1;
    x = x & ~ mask1;
    int temp2 = x & mask2;
    x = x & ~ mask2;
    temp1 = temp1 << 16;
    temp2 = temp2 >> 16;
    return x | temp1 | temp2;
}

/*
 * rotateLeft: Rotate x to the left by n bits. (For 0 <= n <= 31)
 *   Example: rotateLeft(0x76543210, 8) = 0x54321076
 *   Legal ops: ~ & ^ | + << >>
 */
int rotateLeft(int x, int n) {
    int mask = (1 << n) + (~1 + 1); //2^n-1
    int mask2 = mask << (32 + (~ n + 1));
    int temp = x & mask2;
    temp = temp >> (32 + ~ n + 1);
    temp = temp & mask;
    return x << n | temp;
}

/*
 * addOver: Determine if x + y overflows.
 *   Example: addOver(0x7FFFFFFE, 1) = 0
 *            addOver(0x7FFFFFFE, 2) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 */
int addOver(int x, int y) {
    int temp = (x + y) >> 31;
    x = x >> 31;
    y = y >> 31;
    //Check that temp isn't 1 when x and y are 0 or temp is 0 when x and y are 1,
    temp = !!(~temp | x | y) & (temp | ~x | ~y);
    return 1 + ~temp +1;
}

/*
 * boundedMult: Compute 2x, but return the largest positive or negative signed integer if overflow
 *              would occur.
 *   Example: boundedMult(0x00000001) = 0x00000002
 *            boundedMult(0x50000000) = 0x7FFFFFFF (bound to largest positive int)
 *            boundedMult(0xA0000000) = 0x80000000 (bound to largest negative int)
 *   Legal ops: ! ~ & ^ | + << >>
 */
int boundedMult(int x) {
    int y = x << 1; // left shifts x by 1
    int t = 1;
    t = t << 31; // left shift 31 for max positive
    t= ~t;
    int a = ((y >> 31 ^ x >> 31)) & (x >> 31 ^ t); // if overflow, y>>31 ^x>>31 to get 000 or 111 representing changing positive or negative
    //when x negative, x>>31^t = 8000...0
    //when x positive, x>>31^t = 7FFF...F
    int b = (y & ~ ((y >> 31 ^ x >> 31)));
    return a | b;

}

/*
 * absHalf: Compute |x / 2| rounding towards 0.
 *   Example: absHalf(3)  = 1
 *            absHalf(-6) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 */
int absHalf(int x) {
    int a = x & 1;
    int t = x >> 31;
    int b = (x >> 1)+ (a & t);
    int c = b >> 31;
    int answer = (b ^ c) +(~c + 1);
    return answer;
}

/*
 * lessThan: Check if x < y.
 *   Example: lessThan(4, 5) = 1
 *            lessThan(5, 4) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 */
int lessThan(int x, int y) {
    int temp = x + ~y + 1;
    return temp >> 31 & 1;
}

/*
 * multFiveEighths: Compute 5/8ths of x rounding towards 0.
 *   Example: multFiveEighths(8)  = 5
 *            multFiveEighths(-9) = -5
 *   Legal ops: ! ~ & ^ | + << >>
 */
int multFiveEighths(int x) {
    int a = x >> 31;
    int abs = (x^a) + ~a + 1; //get the absolute value of x;
    int b = (abs >>3);
    b = b + (b<<2); // b = 5 * x/8(rounded to 0);
    int c = abs & 7;// c = the lost digits of dividing by 8;
    c = (c + (c<<2)) >> 3;
    b = b + c;
    b = (b^a) + (a&1);//from absolute value to signed value;
    return b;
}

/*
 * isPwr2: Check if x is a power of 2. Assume x > 0.
 *   Example: isPwr2(2) = 1
 *            isPwr2(3) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 */
int isPwr2(unsigned int x) {
    int a = x + (~1 + 1);
    int b = a & x;
    return !b ;
}
