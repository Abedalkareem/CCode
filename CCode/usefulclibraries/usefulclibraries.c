//
//  usefulclibraries.c
//  CCode
//
//  Created by abedalkareem omreyh on 23/05/2022.
//

#include "usefulclibraries.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

// exit()
// if you want to force the termination of a program earlier.
// when an error condition is detected by a program.
//
// it will be always invoked automatically upon return from main.
//
// any open files are automaticallly closed by the system.
// flushes all output streams
// closes all open streams
// closes temporary files created by calls to the standard I/O function tmpfile()
//
// the integer value status is called the exit status and has the same meaning as the value returned from main.
// EXIT_FAILURE (symbolic constant) represents an integer value that you can use to indicate the program has failed (non-zero).
// EXIT_SUCCESS (symbolic constant) represents an integer value that can use to indicate it has succeeded (0).
//
// atexit() function
// the atexit() function allows you to specify particular functions to be called when exit() executes
// must register the functions to be called on exit.
//
// takes as an argument a pointer to a function (the function name)
//
// int atexit(void (*function)(void));
//
// to use the atexit function
// pass itthe address of the function you want called on exit.
// registers this function in a list of functions to be executed when exit() is called
//
// abort() function
// the abort function causes abnormal program termination
// reises the SIGABRT signal
// returns an implementation defined code indicating unsuccessful termination.
// functions passed to atexit are not called.
//
// qsort() function (quick sort).
// the first argument is a pointer to the begining of the array to be sorted.
// the second argument is the number of items to be sorted.
// the third argument is the size of each element
// the final argument is the address of the function to be used for comparing elements.
// the comparison function should return the following:
// a positive integer if the first item should follow the second value
// a zero if the two items are the same.
// a negative integer if the second item should follow the first.
//

int comp_ints(const void *p1, const void *p2);

void tryqsort(void) {
  int data[5] = {54, 3, 12, 9, 24};
  qsort(data, 5, sizeof(int), comp_ints);
  
  for(int i = 0; i < 5; i++)
    printf("%i\n", data[i]);
}

int comp_ints(const void *p1, const void *p2) {
  const int i1 = *(const int *) p1;
  const int i2 = *(const int *) p2;
  return i1 - i2;
}

// Conversion
void tryconversion(void) {
  char a[10] = "100";
  int aint = atoi(a); // atoi stands for ASCII to integer, converts string to integer.
  printf("%i", aint);
  
  char b[10] = "3.14";
  float bfloat = atof(b);
  printf("%f", bfloat);
  
  char c[10] = "1000000000";
  long clong = atol(c);
  printf("%li", clong);
  
  char d[] = "3.1466xyz", *end;
  double dvalue = 0;
  dvalue = strtod(d, &end); // end here it will point to "x" from the "xyz" part.
  printf("%f", dvalue);
  
  char e[] = "3.1466 6.0", *eend;
  double evalue1 = 0;
  double evalue2 = 0;
  evalue1 = strtod(e, &eend); // eend here it will point to " " from the " 6.0" part.
  evalue2 = strtod(eend, NULL);
  printf("%f", evalue1); // 3.1466
  printf("%f", evalue2); // 6.0
}

// randoom
// rand()
// returns a random number in the range [0, RAND_MAX]
// RAND_MAX is defined in <stdlib.h> and has a minimum value of 32767.
//
// If random numbers are generated with rand() without first calling srand(),
// your program will create the same sequence of numbers each time it runs.
//
// The srand() function sets the starting point for producing a series of pseudo-random integers.
// If srand() is not called, the rand() seed is set as if srand(1) were called at program start.
// Any other value for seed sets the generator to a different starting point.
//
// The pseudo-random number generator should only be seeded once, before any calls to rand(),
// and the start of the program. It should not be repeatedly seeded,
// or reseeded every time you wish to generate a new batch of pseudo-random numbers.
//
// Standard practice is to use the result of a call to srand(time(0)) as the seed.
// However, time() returns a time_t value which vary everytime and hence the pseudo-random number vary for every program call.
//
//
void tryRand(void) {
  
  srand((unsigned) time(0));
  
  int brand = rand();
  printf("%i", brand);
}

// system()
// allows you to execute programs on the console/shell
// -1 on error, else the status of the command.
//
// void *memcpy(void *restrict s1, const void *restrict s2, size_t n);
// void *memmove(void *s1, const void *s2, size_t n);
// you can't assign one array to another, so usually loops used to copy. memcpy() and memmove()
// offers the feature. both of these functions copy n bytes from the kocation pointed to bt s2 to
// the location pointetd to by s1.
// both return the value of s1.
//
// the difference between the two of them:
// memcpy is free to assume that there is no overlap between the two memory ranges.
// memmove does not make that assumption, copying takes place as if all the bytes are first copied to a temporary
// buffer before being copied to the final destination.
//
// if you use memcpy when there are overlapping ranges then the behavior is undefined.
// it might work or it might not.

void tryOthers(void) {
  system("mkdir /usr/tmp/data");
  
  getenv("ENV_VALUE"); // get the environment variables.
  
  const char src[50] = "http://www.tutorialspoint.com";
  char dest[50];
  strcpy(dest,"Heloooo!!");
  printf("Before memcpy dest = %s\n", dest);
  memcpy(dest, src, strlen(src)+1);
  printf("After memcpy dest = %s\n", dest);
  
  char dest2[] = "oldstring";
  const char src2[]  = "newstring";
  
  printf("Before memmove dest = %s, src = %s\n", dest2, src2);
  memmove(dest2, src2, 9);
  printf("After memmove dest = %s, src = %s\n", dest2, src2);
  
  char* dup = strdup(src);
  printf("%s", dup);
  char* dup2 = strndup(src, 4);
  printf("%s", dup2); // http
}

// time
// clock() function returns amount of processor time used by the program.
// time() function returns the number of seconds from an arbitrary epoch.
// ctime() and asctime() retunre current date and day of time as function value.
// gmtime() converts time value into Coordinated Universal Time (UTC).
// localtime() returnes structure of type struct tm
// can be passed as an argument to asctime() function.
// asctime() and ctime() functions return current date and time of day.
// the ctime() function mayb call asctime() to perform it's work
//
//

// clock_t is a typedef of long int and is defined in the time.h header.
// It is used to store the processor time in terms of the number of CPU cycles passed since the start of the process.
// To convert the number of CPU clock cycles into seconds, we need to use the CLOCKS_PER_SEC constant, which is also defined in the time.h header.
// The function clock() defined in the time.h header returns the number of elapsed CPU clock cycles.

void tryTimes(void) {
  clock_t start, end, duration;
  start = clock();
  
  for(int i=0; i<6000000; i++){
    printf("%i", 100);
  }
  end = clock();
  
  duration = (end - start);
  
  printf("Processor cycles taken : %f cycles\n", (float)duration);
  printf("Processor time taken : %f seconds\n", (float)duration/CLOCKS_PER_SEC);
  
  
  time_t start_t, end_t;
  double diff_t;
  
  printf("Starting of the program...\n");
  time(&start_t);
  
  printf("Sleeping for 5 seconds...\n");
  sleep(5);
  
  time(&end_t);
  diff_t = difftime(end_t, start_t);
  
  printf("Execution time = %f\n", diff_t);
  
  
  // to get the today date as a astring using the ctime function
  // char *ctime(const time_t *timer);
  // accepts a pointer to a time_t variable as an argument that contains a calendar time value returned by the time() function
  // returns a pointer to a 26-character string containing the day, the date, the time, and the year, which is termainated by a
  // newline and '\0'.
  //
  
  time_t calendar = time(NULL);
  struct tm* time_data;
  time_data = localtime(&calendar);
  
  printf("Today is %d, %d, %d", time_data->tm_wday,
         time_data->tm_mon,
         time_data->tm_year);
  
  // asctime generates a string representation of a tm structure
  time_t time_ptr;
  time(&time_ptr);
  printf("%s", asctime(localtime(&time_ptr)));
  
  
  // The C library function time_t mktime(struct tm *timeptr) converts the
  // structure pointed to by timeptr into a time_t value according to the local time zone.
  
  time_t ret;
  struct tm info;
  char buffer[80];
  
  info.tm_year = 2001 - 1900;
  info.tm_mon = 7 - 1;
  info.tm_mday = 4;
  info.tm_hour = 0;
  info.tm_min = 0;
  info.tm_sec = 1;
  info.tm_isdst = -1;
  
  ret = mktime(&info);
  if( ret == -1 ) {
    printf("Error: unable to make time using mktime\n");
  } else {
    strftime(buffer, sizeof(buffer), "%c", &info );
    printf("%s", buffer);
  }
  
  // The C library function struct tm *gmtime(const time_t *timer)
  // uses the value pointed by timer to fill a tm structure with the values that represent
  // the corresponding time, expressed in Coordinated Universal Time (UTC) or GMT timezone.
  
  time_t rawtime;
  struct tm *info2;
  
  time(&rawtime);
  /* Get GMT time */
  info2 = gmtime(&rawtime );
  
#define BST (+1)
#define CCT (+8)
  
  printf("Current world clock:\n");
  printf("London : %2d:%02d\n", (info2->tm_hour+BST)%24, info2->tm_min);
  printf("China  : %2d:%02d\n", (info2->tm_hour+CCT)%24, info2->tm_min);
  
}
