//
//  dma.c
//  CCode
//
//  Created by abedalkareem omreyh on 25/01/2022.
//

#include "dma.h"
#include <stdlib.h>
#include <string.h>

//
// dynamic memory allocation reserves space in a memory area called the heap.
//
// the stack is another place where memory is allocated.
// function arguments and local variables in a function are stored in stack.
// when the execution of a function end, the space allocated to store arguments and local
// variables is freed.
//
// the memory in the heap is different in that it is controlled by you
// - when you allocate memory on the heap, it is up to you to keep track of when the memory
// you have allocated is no longer required.
// - you must free the space you have allocated to allow it to be reused.
//
// A memory leak occurs when you allocate some meemory dynamically
// and you do not retain the refrence to it, so you are unable to release it.

void doThings(void) {
  // malloc
  int *pNumber = (int*) malloc(100); // 100 bytes / the int is 4 bytes (assuming), it will be enogh for 25 int.
  int *betterPNumber = (int*) malloc(25 * sizeof(int)); // a better way to do it.

  if(!betterPNumber && !pNumber) { // to check if the memory not allocated, if null then there is an issue.
    // exit maybe?
  }

  // calloc
  int *count = (int*) calloc(75, sizeof(int)); // 75 ints, and the size is int.
  // calloca offers a couple of advantages over malloc,
  // - it allocates memory as a number of elements of a given size.
  // - it initializes the memory that is allocated so that all bytes are zero.

  // realloc
  // enables you to reuse or exted memory that you previously allocated using malloc or calloc.
  char *str = (char*) malloc(6 * sizeof(char));
  strcpy(str, "abed");
  str = realloc(str, 13 * sizeof(char)); // change the memory from 100 to 200.
  strcat(str, "alkareem");
  printf("%s \n", str);

  free(str);
  str = NULL;
  free(pNumber);
  pNumber = NULL;
  free(betterPNumber);
  betterPNumber = NULL;
}
