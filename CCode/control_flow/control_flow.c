//
//  control_flow.c
//  CCode
//
//  Created by abedalkareem omreyh on 11/12/2021.
//

// setjmp() and longjmp() mainly used to implement exception handling in c (error recovery situations).
// setjmp can be used like try.
// longjmp can be used like throw.

#include "control_flow.h"
#include <setjmp.h>

void controlFlow(void) {
  int x;
  int y = 10;

  printf("Enter the x number \n");
  scanf("%i", &x);
  if (x < y) {
    printf("x < %i \n", y);
  } else {
    printf("x >= %i \n", y);
  }

  if (x < y)
    printf("x < %i \n", y);
  else if (x == y)
    printf("x == %i \n", y);
  else
    printf("x > %i \n", y);


  printf("%s \n", x < y ? "x < y" : "x >= y");

  if (x < y)
    printf("Hi!");
   else
     ; // null statement

  // comma operator
  while (x < 200)
    (void)(y+= 50), ++x; // comma operator

  int z = 1;

  int j = ((void)(5), 3); // j = 3 (will take the write value)
  printf("%i", j);

  x = ((void)(y = 3), (z= ++y + 2) + 5);

  for (x = 0, j = 0; x != 1000; x++, j-=10)
    ;

  (void)(printf("abedalkareem")), // comma operator
  (void)(printf("fayyad")), // comma operator
  printf("omreyh");
}

void switchControlFlow(void) {
  int x;
  printf("Enter a number between 1 and 5 \n");
  scanf("%i", &x);
  switch (x) {
    case 1:
      printf("Hey");
      break;
    case 2:
      printf("Bye");
      break;
    case 3:
      printf("Ok!");
      break;
    case 4:
      printf("No!");
      break;
    case 5:
      printf("That's too much");
      break;
    default:
      break;
  }
}

void goTo(void) {
  int num,i=1;
  printf("Enter the number whose table you want to print?");
  scanf("%d",&num);

  table:

  printf("%d x %d = %d\n",num,i,num*i);

  i++;

  if(i<=10)
  goto table;
}

void loops(void) {
  // for
  for (int i = 0; i <= 10; i++) {
    printf("%i \n", i);
  }

  for (int i = 1, j = 1; i <= 10; i++, j += 2)
    printf("i = %i, j = %i \n", i, j);

  // infinite for loop
  // for (;;)
  // printf("Oh!");

  // do while
  int r = 0;
  do {
    r++;
    printf("r: %i \n", r);
  } while (r != 10);

  // while
  int y;
  printf("\nEnter a number:");
  while (scanf("%i", &y)) {
    printf("It's %i \n", y);
  }
}

jmp_buf buf;

void functioon(void) {
  printf("function");
  longjmp(buf, 40);

//  printf("will not reach here because longjmp");
}

void setjmplongjmp(void) {
  int i = setjmp(buf);
  printf("i=%i\n", i); // will print 40
  if (i != 0) {
    printf("back from functioon");
  } else {
    printf("first time");
    functioon();
  }
}
