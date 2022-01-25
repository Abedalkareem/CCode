//
//  pointers.c
//  CCode
//
//  Created by abedalkareem omreyh on 06/01/2022.
//

#include "pointers.h"
#include <stddef.h>

//
// &: The address of operator.
// *: indirection operator.
// NULL == 0
// void pointer means absence of any type. (void*)
//


void pointers(void) {
  int number = 99;
  int *pnumber = &number;
  printf("%p %i \n", pnumber, number);

  int result = *pnumber + 1; // we use * to dereference an opject
  printf("%i \n", result); // 100

  printf("number's address: %p \n", &number);
  printf("pnumber's address: %p \n", &pnumber);
  printf("pnumber size: %lu \n", sizeof(pnumber));

  *pnumber += 400;
  printf("number: %i \n", number);

  long value = 9999L;
  const long *pvalue = &value;
//  *pvalue = 888L; Can't change the value. (the value is constant but not the pointer)
  printf("*pvalue: %li \n", *pvalue);

  long count = 10;
  long *const pcount = &count;
//  pcount = &value; Can't change the value. (the pointer is constant but not the value)
  *pcount = 55L;
  printf("*pcount: %li \n", *pcount);

  int myConst = 33;
  const int *const pmyConst = &myConst; // the value and pointer is constants.
  printf("*pmyConst: %i \n", *pmyConst);

  int i = 10;
  float f = 11.0;
  char ch = 'c';

  void *vpointer;

  vpointer = &i;
  printf("*vpointer: %i \n", *(int*)vpointer);
  vpointer = &f;
  printf("*vpointer: %f \n", *(float*)vpointer);
  vpointer = &ch;
  printf("*vpointer: %c \n", *(char*)vpointer);

  int values[4] = {5, 6, 7, 8};
  printf("arraySum: %i \n", arraySum(values, 4));

  char string[] = "Hi All!";
  printf("countString: %li \n", countString(string));
}

int arraySum(int array[], const int n) { // int arraySum(int * array, const int n)
  int sum = 0;
  int *ptr;
  int *const arryaEnd = array + n;
  for (ptr = array; ptr < arryaEnd; ++ptr)
    sum += *ptr;

  return  sum;
}

void copyString(char *to, char *from) {
  for ( ; *from != '\0'; ++from, ++to)
    *to = *from;
  *to = '\0';
}

void copyStringWhile(char *to, char *from) {
  while (*from)
    *to++ = *from++;

  *to = '\0';
}

long countString(char *string) { // when you pass a pointer, it's still passed by value (the pointer address will be copied to a new address). but we care about the address itself and when you updated it will update in another places. (pass by refrence).
  char *lastAddress = string;
  while (*lastAddress) {
    lastAddress++;
  }
  return lastAddress - string;
}

void doSomething(const char *param) {
//  *param = 'f'; You can't change the value as it's const.
}

void doAnotherThing(int *const param) {
//  param = 55; you can't change the value of what the pointer is poiting to.
    *param = 5; 
}
