//
//  bit_manipulation.c
//  CCode
//
//  Created by abedalkareem omreyh on 27/03/2022.
//

#include "bit_manipulation.h"
#include "math.h"

// A byte has 8 bits.
// each 0 or 1 represents 1 bit.
// 0 means bit turned off.
// 1 means bit truned on.
//
// the right most bit of a byte known as least significant or low order bit.
// the left most bit of a byte known as most significant or high order bit.
//
// changing a bit's value to 1 is referred to as setting the bit.
// changing a but's value to 0 is referred to as resetting a bit.
//
// Negative numbers (signed). computers represent such numbers using "twos complement" notation.
// the leftmost bit represent the sign bit.
// if this bit is 1 the number is negative, if it's 0 then the number is positive.
// te rest of the bits represent the value of the number.
//
// to convert -5 to binary, 1 is added, which gives -4.
// 4 expressed in binary is 00000100.
// complementing the bits produces 11111011.
//
// to convert back a negative number to decimal.
// first complement all of the bits.
// covert the result to decimal.
// change the sign of the resullt.
// then subtract 1.
//
// Bit-field
// Declares a class data member with explicit size, in bits.
// Adjacent bit-field members may (or may not) be packed
// to share and straddle the individual bytes.
// struct S
// {
//    // three-bit unsigned field, allowed values are 0...7
//    unsigned int b : 3;
// };

int convertBinaryToDecimal(long long n);
long long convertDecimalToBinary(int n);

void start(void) {
  int n;
  long long result = 0;

  printf("Enter the number \n");
  scanf("%d", &n);

  result = convertDecimalToBinary(n);

  printf("result: %lld", result);

}

// 1011
// % = 1
// / = 101
// number = 1
//
// % = 1
// / = 10
// number = 3
//
// % = 0
// / = 1
// number = 3
//
// % = 1
// / = 0
// number = 11

int convertBinaryToDecimal(long long n) {
  int decimalNumber = 0;
  int i = 0;
  int remainder = 0;

  while (n != 0) {
    remainder = n % 10;
    printf("remainder: %d \n", remainder);
    n = n / 10;
    printf("n: %lld \n", n);
    decimalNumber += remainder * pow(2, i);
    printf("decimalNumber: %d \n\n", decimalNumber);
    i++;
  }

  return decimalNumber;
}

long long convertDecimalToBinary(int n) {
  long long binaryNumber = 0;
  int remainder, i = 1;

  while (n!=0) {
    remainder = n%2;
    n = n / 2;
    binaryNumber += remainder * i;
    i = i * 10;
  }

  return binaryNumber;
}

void getRGB(void) {
  #define BYTE_MASK 0Xff
  printf("%i", BYTE_MASK);
  unsigned long color = 0x002a162f;
  unsigned char blue, green, red;
  red = color & BYTE_MASK;
  green = (color >> 8) & BYTE_MASK;
  blue = (color >> 16) & BYTE_MASK;
}


struct packed_struct {
  unsigned int :3; // unnamed bit, used for padding. (3 bits). /* Skips 3 bits in the layout */
  unsigned int f1:1; // f1 (1 bit)
  unsigned int f2:1;
  unsigned int f3:1;
  unsigned int type:8; // type (8 bits)
  unsigned int index:18;
};

void packeddata(void) {
  struct packed_struct packed_data;
  packed_data.type = 7;

  if (packed_data.f1) {
    printf("true");
  }
}

// primary colors
#define BLUE 4
#define GREEN 2
#define RED 1

// mixed colors
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)


