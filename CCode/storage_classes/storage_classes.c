//
//  storage_classes.c
//  CCode
//
//  Created by abedalkareem omreyh on 22/03/2022.
//

#include "storage_classes.h"
#include "storage_classes_test.h"

// C storage classes:
// - auto: like local variables.
// - register: it's used to define local variables that should be stored in a register instead of RAM
// (make it faster than a normal varibale stored in memory (RAM)).
// You can't use address of opreator on it (&) becuase it's not in the memory.
// - extern: means that the variable defined elsewhere not in the same block where it used.
// functions contained in separats files can communicate through external variables.
// the extern storage class is used to give a refernce of a global variable that is visible to
// all the program files.
// - static: if it used on a gloabl variable or a function it means that global function or
// varibale can be used only from the same file, if it used with local variable it means to
// keep the variable existence during the life-time of program.
// static varibale allocate memory on the heap not stack.
//
// Splited into two storage durations:
// automatic storage duration
// static storage duration
//
// a processor register (CPU register) is one of a small set of data holding places that are part
// of the computer processor. a register may hold an instruction, a storge address, or any kind of data.

extern int number; // extern global variable, it will use the one in storage_classes_test.

static int newNumber = 1; // can be accessed only from this file.

extern void printNumber(void); // extern function, it will use the one in storage_classes_test.

int playAgain(void);

static void playSomething(void) { // can be used only from this file. can't be extern.
  printf("%i", newNumber);
}

void play(void) {
  auto int x = 0;
  int y = 1; // by default it's auto.
  printf("%i, %i", x, y);

  number = 555;

  printNumber();

  register int ww = 123;
  printf("%i", ww);

  printf("%i", playAgain()); // 1
  printf("%i", playAgain()); // 2
  printf("%i", playAgain()); // 3
  printf("%i", playAgain()); // 4
}

int playAgain(void) {
  static int count = 0; // static storage type.
  int anotherCount = 0; // auto stroage type.

  count++; // it will keep increasing.
  anotherCount++; // always will be 1.

  return count;
}
