//
//  strings.c
//  CCode
//
//  Created by abedalkareem omreyh on 20/12/2021.
//

#include "strings.h"
#include <strings.h>
#include <stdlib.h>

void nullChar(void) {
  // Hi, How are you?
  //|H|i|,| |H|o|w| |a|r|e| |y|o|u|?|\0|

  // printf("Hi, \0 How are you?"); // output: "Hi, "

  // char myString[20]; Can save 19 char as the last space for the \0 (null character).

  char word[] = {'H', 'i', ' ', '!'};
  printf("%s \n", word);

  // char s[100];
  // s = "hi"; // WILL NOT WORK.
}

void constants(void) {
  // define
  // # define APP_KEY "key"

  const int MONTHS = 12;
  printf("%i", MONTHS);
}

void functions(void) {
  char hello[] = "Hello World!";
  printf("String length: %lu \n", strlen(hello));

  strcpy(hello, "Hello World?");
  printf("New string: %s \n", hello);

  char var[] = "Hi All";
  strncpy(var, hello, sizeof(var) - 1); // -1 for the null char.
  printf("var string: %s \n", var);

  char secondName[] = "Omreyh";
  char full[100] = "Abedalkareem ";
  strcat(full, secondName);
  printf("String: %s \n", full);

  char src[4], dest[3];
  strcpy(src, "Hi");
  strcpy(dest, "By");
  strncat(src, dest, 1);
  printf("Src: %s \n", src);

  // 0 if two strings are equal.
  // -1 if first string less than second.
  // 1 if first string grater than second string.
  printf("strcmp(A, A): %i \n", strcmp("A", "A")); // 0
  printf("strcmp(A, B): %i \n", strcmp("A", "B")); // -1
  printf("strcmp(B, A): %i \n", strcmp("B", "A")); // 1
  printf("strcmp(C, A): %i \n", strcmp("C", "A")); // 1
  printf("strcmp(Z, a): %i \n", strcmp("Z", "a")); // -1
  printf("strcmp(apples, apple): %i \n", strcmp("apples", "apple")); // 1

  if (strncmp("astronomy", "astro", 5) == 0) {
    printf("Found: astronomy! \n");
  }

  if (strncmp("astounding", "astro", 2) == 0) {
    printf("Found: astounding! \n");
  }
}

void srarch(void) {
  char str[] = "Hello World!";
  char ch = 'q';
  char *pGot_char = NULL;
  pGot_char = strchr(str, ch);
  printf("%s", pGot_char);

  char wordToFind[] = "World";
  char *value = NULL;
  value = strstr(str, wordToFind);
  printf("%s", value);
}

void token(void) {
  char str[80] = "hello - how - are - you";
  const char s[2] = "-";
  char *token;

  // get first token
  token = strtok(str, s);

  while (token != NULL) {
    printf("%s\n", token);

    token = strtok(NULL, s);
  }
}

void convert(void) {
  char number[] = "55";
  int i = atoi(number); // convert to int
  double d = atof(number); // convert to double
  long l = atol(number); // convert to long
  long ll = atoll(number); // convert to long long

  printf("%i, %f %li, %li", i, d, l, ll);
}
