//
//  main.c
//  CCode
//
//  Created by abedalkareem omreyh on 27/11/2021.
//
// Process of creation a c program has many steps:
// preprocessor
// compilation
// assembler
// linker
// loader
//

#include <stdio.h>
#include "threads.h"

int main(int argc, const char * argv[]) { // arguments count, arguments vector.
  printf("Number of arguments %i \n", argc);
  for(int i = 0; i < argc; i ++) {
    printf("Argument %i %s \n", i, argv[i]);
  }

  testThreads();

  return 0;
}
