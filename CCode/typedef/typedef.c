//
//  typedef.c
//  CCode
//
//  Created by abedalkareem omreyh on 23/03/2022.
//

#include "typedef.h"

typedef char NewType;
typedef char* String;

void printHi(void) {
  String hi = "hi";
  printf("%s", hi);
}
