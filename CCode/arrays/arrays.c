//
//  arrays.c
//  CCode
//
//  Created by abedalkareem omreyh on 11/12/2021.
//

#include "arrays.h"
#define DAYS 7

void arrays(void) {
  int numbers[10];
  numbers[0] = 5;
  printf("%i \n", numbers[0]);

  printf("Enter 8 numbers: \n");
  for(int i = 1; i <= 9; i++) {
    scanf("%i", &numbers[i]);
  }

  printf("Items: \n");
  int items[] = {10, 5, 6, 2, 1};
  for(int i = 0; i <= 5; i++) {
    printf("%i \n", items[i]);
  }

  printf("MoreItems: \n");
  int moreItems[10] = {10, 5, 6, 2, 1}; // [10, 5, 6, 2, 1, 0, 0, 0, 0, 0]
  printf("%i \n", moreItems[9]);

  printf("Data: \n");
  int data[10] = {[9] = 9, [5] = 5, [6] = 6, [2] = 2, [1] = 1}; // [0, 1, 2, 0, 0, 5, 6, 0, 0, 9]
  printf("%i \n", data[9]);

  printf("Days: \n");
  int days[DAYS] = {1, 2, 3, 4, 5, 6, 7};
  for(int i = 0; i < DAYS; i++) {
    printf("%i \n", days[i]);
  }
}

void twoDimensionalArray(void) {
  int numbers[3][4] = {
    {10, 20, 30, 40},
    {11, 21, 31, 41},
    {12, 22, 32, 42}
  };
  printf("numbers[0][1]: %i \n", numbers[0][1]);

  int moreNumbers[4][5] = {
    {10, 20, 30}, // 10, 20, 30, 0, 0
    {11, 21, 31}, // 11, 21, 31, 0, 0
    {12, 22, 32}, // 12, 22, 32, 0, 0
    {13, 23, 33} // 13, 23, 33, 0, 0
  };
  printf("moreNumbers[0][4]: %i \n", moreNumbers[0][4]);

  int matrix[4][3] = { [0][0] = 1, [1][1] = 5, [2][2] = 9 };
  printf("matrix[0][0]: %i \n", matrix[0][0]);
}
