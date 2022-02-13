//
//  cast_and_sizeof.c
//  CCode
//
//  Created by abedalkareem omreyh on 10/12/2021.
//

#include "cast_and_sizeof.h"

void castNumbers(void) {
  float number = 12.55;
  int intNumber = number;
  printf("cast %i \n", intNumber);

  printf("20 / 14 %i \n", 20 / 14); // 1
  printf("20 / 14.0 %f \n", 20 / 14.0); // 1.428571
  printf("20 / 14.0 %d \n", (int) 20.5 / (int) 14.5); // 1, type cast operator has a higher precedence.
}

void sizeOfOperator(void) {
  // sizeof is an operator.
  // evaluated at compile time and not run time, unless a variable length array is used as an argument.
  printf("sizeof(int) %lu \n", sizeof(int));
  printf("sizeof(long long) %lu \n", sizeof(long long));
  printf("sizeof(long int) %lu \n", sizeof(long int));
  printf("sizeof(long) %lu \n", sizeof(long));
  printf("sizeof(long double) %lu \n", sizeof(long double));
  printf("sizeof(float) %lu \n", sizeof(float));
  printf("sizeof(double) %lu \n", sizeof(double));
  printf("sizeof(int) %lu \n", sizeof(5 + 4));
}
