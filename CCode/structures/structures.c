//
//  structures.c
//  CCode
//
//  Created by abedalkareem omreyh on 26/01/2022.
//

#include "structures.h"

//
// "today.day"
// The . called member selection operator, or the dot operator.
//

struct date {
  int year;
  int month;
  int day;
};

struct time {
  int hour;
  int minutes;
};

void useit(void) {
  struct date today;
  today.day = 15;
  today.month = 12;
  today.year = 2010;

  struct date tomorrow = {2010, 12, 16};
  struct date tdatomorrow = {2010, 12}; // year and month.
  struct date afterMonth = {.year = 2010, .month = 1, .day = 15};
  struct date nextYear = {.year = 2011}; // year

  // compound literals:
  today = (struct date) {2010, 12, 16};
  afterMonth = (struct date) {.year = 2010, .month = 1, .day = 15};

  struct user {
    int age;
    int gender;
  } abedalkareem;

  abedalkareem.age = 55;

  struct { // un named structure
    int color;
    int speed;
  } car;

  car.color = 4455654;

  struct date myDates[10];
  myDates[1].month = 5;
  printf("%i \n", myDates[1].month); // will print 5.

  struct date newDates[3] = { {5, 12, 2015}, {6, 12, 2015}, {7, 12, 2015} };
  struct date newDates2[3] = { [2] = {5, 12, 2015}}; // just the thired one.
  struct date newDates3[3] = { [1].day = 1, [1].month = 12, [1].year = 2015};

  struct newdate {
    int numberOfDays;
    char name[3];
  };

  struct newdate myMonth = {5, {'f', 'f', 'f'}};
  struct newdate myMonth2 = {5, "fff"};
  printf("%s \n", myMonth2.name); // will print 5.

  struct timeAndDate {
    struct date currentDate;
    struct time currentTime;
  };

  struct timeAndDate event;
  event.currentDate.day = 5;
  event.currentTime.hour = 3;

  struct timeAndDate newEvent = {{5, 10, 2020}, {3, 30}}; // month, time
  struct timeAndDate newEvent2 = {{5, 10, 2020}, {.minutes = 3, .minutes = 30}}; // month, time

  // nested structures
  struct datex {
    struct timex {
      int hour;
      int minutes;
    } mytime;

    int year;
    int month;
    int day;
  };

  struct date *datePtr;
  datePtr = &today;
  (*datePtr).day = 5;
  // better way
  datePtr->day = 5; // this will derefrence without *.
  printf("%i \n", datePtr->day); // will print 5.

  struct intPtr {
    int *p1;
    int *p2;
  };

  struct intPtr pointrts;
  int i1 = 100, i2;

  pointrts.p1 = &i1;
  pointrts.p2 = &i2;

  *pointrts.p2 = 55;

  struct names { // here it will create memory
    char firts[20];
    char last[20];
  };

  struct pnames { // here not, we need to use malloc
    char *firts;
    char *last;
  };

}

void doSomethingX(struct date someDate) {
  printf("%i \n", someDate.day);
}

void doAnotherthing(struct date *someDate) {
  printf("%i \n", someDate->day);
}

struct date function(void) {
  return (struct date) {5, 6, 1993};
}
