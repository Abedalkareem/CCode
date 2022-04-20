//
//  io.c
//  CCode
//
//  Created by abedalkareem omreyh on 31/01/2022.
//

#include "io.h"
#include <stdlib.h>

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
//
// gets deprecated and fgets deprecated. use getline.
// The gets() function is unsafe because it does not perform
// bounds checking on the size of its input.
//
// fgets() is dangerous because if the input data contains
// a null character, you can't tell..
//
// fflush: clean the buffer/file.

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

  while (!feof(pfile)) {
    fgets(string, 60, pfile);
    printf("%s", string);
  }

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

//  ungetc(ch, pfile) will return back the char to  the stream.
}

void readForomFileUsingGetC(void) {
  char ch = '\0';
  FILE *fp;

  if ((fp = fopen("file.txt", "rw"))) {
    ch = getc(fp);

    while (ch != EOF) {
      ch = getc(fp);
    }

    fclose(fp);
  }
}

void readForomFileUsingSTDIN(void) {
  char ch = '\0';

  ch = getc(stdin);
  printf("char %c", ch);
}

void readFromGetChar(void) {
  printf("%c", getchar());

  int ch = 0;
  while ((ch = getchar()) != EOF) {
    printf("%c", ch);
  }
}

void readForomFileUsingFGetC(void) {
  char ch = '\0';
  FILE *fp;

  if ((fp = fopen("file.txt", "rw"))) {
    ch = fgetc(fp);

    while (ch != EOF) {
      ch = fgetc(fp);
    }

    fclose(fp);
  }
}

void writeToFileUsingPutC(void) {
  FILE *fp;
  if ((fp = fopen("file.txt", "rw"))) {
    putc('w', fp);

    fclose(fp);
  }
}

void writeToFileUsingPutCStdOut(void) {
  putc('w', stdout);
  // putchar has the stdout by default.
  // fputc write a char to file.
}

void readFromGetLine(void) {
  char *buffer = NULL;
  size_t bufsize = 32;
  size_t characters;

  buffer = (char *)malloc(bufsize * sizeof(char));

  if (buffer == NULL) {
    exit(1);
  }

  characters = getline(&buffer, &bufsize, stdin);

  printf("chars read: %zu", characters);
  printf("text: %s", buffer);
}

void useSprintF(void) {
  char string[100];
  sprintf(string, "Hello, this is the number: %i", 55);
  printf("%s", string);

  char string2[100];
  int a = 10, b = 20, c = 0;
  c = a + b;
  sprintf(string2, "Sum of %i and %i is %i ", a, b, c);
  printf("%s", string2);

  // fprintf() is same as sprintf put takes file.
}

void useStderr(void) {
  FILE *fp;
  if ((fp = fopen("file.txt", "rw"))) {
    putc('w', fp);

    fclose(fp);
  } else {
    fprintf(stderr, "Can't open the file.");
  }
}

void useFscanF(void) {
  FILE *fp = NULL;
  char buff[255];

  fp = fopen("data.txt", "r");

  while (fscanf(fp, "%s", buff) != EOF) {
    printf("%s ", buff);
  }

  fclose(fp);
}

void useSscanF(void) {
  char *str = "Hi all 55";
  char name[10], title[10];
  int age = 0, ret = 0;
  // scan from a string to a variables.
  ret = sscanf(str, "%s %s %d", name, title, &age);

  printf("%s", name); // hi
  printf("%s", title); // all
  printf("%i", age); // 55
}
