//
//  data_types.c
//  CCode
//
//  Created by abedalkareem omreyh on 27/11/2021.
//

#include <stdbool.h>
#include "data_types.h"

// bits in memory are grouped into sets of eight.
// each eight bits = byte.
// each byte labled with a number (address).
// in c all types are primitive types because we don't have have objects.

void declaration(void) {
  int x;
  int y, z;
  int b = 50, c = 40;

  x = 5;
  y = 10;
  z = 15;

  int a = b + c;

  printf("%i", a);
}

void types(void) {

  // int
  int a = 5;
  a = 0xFFEF0D;
  printf("%i \n", a);

  // float
  float b = 5.5;
  b = 3.;
  b = -.0001;
  b = 1.7e4; // 1.7 x 10 to the power of 4
  printf("%f \n", b);
  printf("%.2f \n", b);

  // bool
  _Bool isOk = 0;
  bool notOk = true;
  printf("%i, %i \n", isOk, notOk);

  // double
  double c = 5.6;
  c = .6;
  printf("%g \n", c);
  printf("%e \n", c);

  // char
  char d = 'd';
  d = 55;
  printf("%c \n", d);

  // short, long, unsigned
  short int sx = 5;
  short sy = 3;

  long int lx = 10000000;
  long ly = 10000000;

  unsigned int ux = 1;
  unsigned uy = 1;

  long long int llx = 55;
  llx = 55L;

  printf("%i, %i, %li, %li, %i, %i, %lli \n", sx, sy, lx, ly, ux, uy, llx);
}

void enums(void) {
  enum colors {
    red, blue, green
  };

  enum direction {
    up, bottom, left = 10, right // 0, 1, 10, 11
  };

  enum colors primeryColor = red;
  printf("%u", primeryColor);
}
