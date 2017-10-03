/*
 * Assignment: Bit Twiddling
 * Class: CSC 252 Spring 2017
 *
 * TAs: Sayak Chakraborti (schakr11@cs.rochester.edu)
 *      Kevin Gerami(kgerami@u.rochester.edu)
 *
 * You may use this program to write tests for your solutions in bits.c.
 */

#include <stdio.h>
#include <stdlib.h>
#include "bits.h"

int main(int argc, char **argv) {
    /* Write your tests here. */
    printf("evenBits: %0x\n", evenBits());
    printf("bitAnd: %d\n",bitAnd(3,5));
    printf("swapBytes example: %0x == 0x33001122\n",swapBytes(0x33221100));
    printf("swapBytes: %0x\n", swapBytes(0x332F11AC));
    printf("rotateLeft: %0x\n", rotateLeft(0x72FA3228, 20));
    printf("addOver: %d\n", addOver(0x7FFFFFFE, 1));
    printf("addOver: %d\n", addOver(0x7FFFFFFE, 0x7FFFFFFE));
    printf("addOver: %d\n", addOver(2, 1));
    printf("addOver: %d\n", addOver(0x80000000, -10));
    printf("addOver: %d\n", addOver(0x7FFFFFFE, 1));
    printf("addOver: %d\n", addOver(0x7FFFFFFE, 2));
    printf("absHalf: %d\n",absHalf(0));
    printf("absHalf: %d\n",absHalf(-5));
    printf("absHalf: %d\n",absHalf(66));
    printf("absHalf: %d\n",absHalf(0x80000000));
    printf("lessThan: %d\n",lessThan(0x80000000, 1));
    printf("lessThan: %d\n",lessThan(10, 2));
    printf("lessThan: %d\n",lessThan(10, -2));
    printf("lessThan: %d\n",lessThan(-1, 2));
    printf("lessThan: %d\n",lessThan(-1, -2));
    printf("lessThan: %d\n",lessThan(3, 3));
    printf("power of 2: %d\n", isPwr2(2));
    printf("power of 2: %d\n", isPwr2(3));
    printf("power of 2: %d\n", isPwr2(4));
    printf("power of 2: %d\n", isPwr2(255));
    printf("bounded multiplication: %x\n", boundedMult(0xA0000000));
    printf("bounded multiplication: %x\n", boundedMult(0x8A000000));
    printf("bounded multiplication: %x\n", boundedMult(0x00000002));
    printf("multFiveEighths: %d\n", multFiveEighths(-9));
    printf("multFiveEighths: %d\n", multFiveEighths(9));
    printf("multFiveEighths: %d\n", multFiveEighths(-8));
    printf("multFiveEighths: %d\n", multFiveEighths(8));
    printf("multFiveEighths: %d\n", multFiveEighths(10));
    printf("multFiveEighths: %d\n", multFiveEighths(7));
    printf("multFiveEighths: %d\n", multFiveEighths(-6));
    printf("multFiveEighths: %d\n", multFiveEighths(6));
    printf("multFiveEighths: %d\n", multFiveEighths(-5));
    printf("multFiveEighths: %d\n", multFiveEighths(5));
    printf("multFiveEighths: %d\n", multFiveEighths(-4));
    printf("multFiveEighths: %d\n", multFiveEighths(4));
    printf("multFiveEighths: %d\n", multFiveEighths(-3));
    printf("multFiveEighths: %d\n", multFiveEighths(3));
    printf("multFiveEighths: %d\n", multFiveEighths(-2));
    printf("multFiveEighths: %d\n", multFiveEighths(2));
    printf("multFiveEighths: %d\n", multFiveEighths(0x7FFFFFFF));
    printf("multFiveEighths: %d\n", multFiveEighths(0x80000000));
    printf("lessThan: %d\n",lessThan(6,5));
    printf("absHalf: %d\n",absHalf(0));
    printf("absHalf: %d\n",absHalf(-5));
    printf("absHalf: %d\n",absHalf(66));
    printf("absHalf: %d\n",absHalf(0x80000000));
    printf("absHalf: %d\n",absHalf(0x7FFFFFFF));
    // printf("hey\n");
    // int r=0xFFF;
    // for(int i =-r; i <= r; i++){
    //   if(multFiveEighths(i) == i*5/8){
    //     // printf("%d\t%d\t%d\n", i, multFiveEighths(i),i*5/8);
    //   }else{
    //     // printf("doesn");
    //     printf("%d*\t%d\t%d\n", i, multFiveEighths(i),i*5/8);
    //   }
    // }

    return 0;
}
