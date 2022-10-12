//
//  union.c
//  CCode
//
//  Created by abedalkareem omreyh on 21/04/2022.
//

#include "union.h"

// A union is a special data type available in C that allows to store different data types in the same memory location. You can define a union with many members, but only one member can contain a value at any given time. Unions provide an efficient way of using the same memory location for multiple-purpose.

union Xata {
  int i;
  float f;
  char str[20];
}; // Xata will occupy 20 bytes of memory space because  this is the maximum
// space which can be occupied by a character string.

union car {
  int i_value;
  float f_value;
  char c_value[40];
};

struct owner {
  char name[12];
};

struct leasecompany {
  char name[40];
  char headquarters[40];
};

struct car_data {
  char make[15];
  int status;
  union {
    struct owner owncar;
    struct leasecompany leasecar;
  }; // anonymous union
};

void tryUnion(void) {
  union car car1, *car2;
  printf("Memory size occupied by car: %zu\n", sizeof(car1));

  car1.i_value = 5;
  car2 = &car1;
  car2->i_value = 3;

//  union car car3 = {.i_value = 15};
}
