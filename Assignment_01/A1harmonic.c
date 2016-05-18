/*Filename: A1harmonic.c *
 *Part of: Assignment 1 A290 program *
 *Created by: Won Yong Ha *
 *Created on: 5/17/2016 *
 *Last Modified by: Won Yong Ha *
 *Last Modified on: 5/17/2016 *
 */

#include <stdio.h>

//calculate function
float calculate(int x) {

  double sum = 0;
  while (x != 0) {
    sum = sum + 1/(float)x;
    x--;
  }
  return sum;
}

//main function
int main() {

  int value;

  printf("Enter a value to calculate the value of this harmonic series:\n\n");

  scanf("%d", &value);

  while(value <= 0) {
    printf("\nPlease enter a POSITIVE Number: ");
    scanf("%d", &value);
  }

  printf("\nThe value for the series is: %f.\n\n", calculate(value));

  return 0;
}
