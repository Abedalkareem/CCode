//
//  io.c
//  CCode
//
//  Created by abedalkareem omreyh on 31/01/2022.
//

#include "io.h"

//  Volatile memory, in contrast to non-volatile memory,
// is computer memory that requires power to maintain the stored information.

// Two ways to write to a file:
// - text.
// - binary (like image data).

// streams can be keyboard, file, console, socket.

// The limit of the files you can open, FOPEN_MAX in stdio.h

// file modes:
// w, a, r, w+, a+, r+

// absolute path vs relative path
// An absolute path is a path that describes the location of a file or folder regardless of the current working directory; in fact, it is relative to the root directory. It contains the complete location of a file or directory, hence the name. It is also referred to as absolute pathname or full path and it always starts at the same place, which is the root directory. Absolute paths contain all the relevant information to find the resources indicated by an absolute URL. An absolute path must be used to refer to websites that are on a domain other than your home domain.
// A relative path is a path that describes the location of a file or folder in relative to the current working directory. It can be best used to refer to websites that are located on the same domain, ideally on certain sections of websites in which the documents never change relationships to each other. Unlike absolute paths, relative paths contain information that is only relative to the current document within the same website which avoids the need to provide a full absolute path. In simple words, relative path refers to a path relative to the location of the current webpage.

void letsStart(void) {
  FILE *pfile = NULL;
  char *fileName = "data.txt";
  pfile = fopen(fileName, "w+");
  if (pfile == NULL) {
    printf("Something went wrong! \n");
    return;
  }

  fputc('c', pfile); // wirte one char
  fputs("Hello! Hi how 1455", pfile);

  fprintf(pfile, "%s %s %i", "Hello", "There", 123);

//  int chara = fgetc(pfile); // read single char, you can use also "getc"
  int c;
  while ((c = fgetc(pfile)) != EOF) {
    printf("c: %c \n", c);
  }

  char string[60];
  fgets(string, 10, pfile); // to read a string
  printf("string: %s \n", string);

  char str1[10], str2[20], str3[10];
  int year;
  // file content "dsaads dasdsa dsads 1993"
  fscanf(pfile, "%s %s %s %i", str1, str2, str3, &year);

  long pos = ftell(pfile); // return the current postion in a file.
  printf("pos: %li \n", pos);
  fseek(pfile, 7, SEEK_SET); // move it 7 bytes
  printf("pos after: %li \n", pos);
  printf("str1, str2, str3, year: %s %s %s %i \n", str1, str2, str3, year);

  fseek(pfile, 0, SEEK_END); // to move the postion, SEEK_SET: begining of the file, SEEK_CUR: current postion in the file.

//  fgetpos(pfile, fpos_t *) used with fsetpos()
  fpos_t here;
  fgetpos(pfile, &here);

  fclose(pfile);
  pfile = NULL;

  char *newFileName = "datax.txt";
  rename(fileName, newFileName); // 0 if successfull else 1

  remove(newFileName);
}
