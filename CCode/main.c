//
//  main.c
//  CCode
//
//  Created by abedalkareem omreyh on 27/11/2021.
//

#include <stdio.h>
#include "pointers/pointers.h"

int main(int argc, const char * argv[]) { // arguments count, arguments vector.
  printf("Number of arguments %i \n", argc);
  for(int i = 0; i < argc; i ++) {
    printf("Argument %i %s \n", i, argv[i]);
  }

  pointers();
  return 0;
}
