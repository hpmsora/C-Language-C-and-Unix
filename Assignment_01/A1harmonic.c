/*Filename: A1harmonic.c *
 *Part of: Assignment 1 A290 program *
 *Created by: Won Yong Ha *
 *Created on: 5/17/2016 *
 *Last Modified by: Won Yong Ha *
 *Last Modified on: 5/19/2016 *
 */

#include <stdio.h>

//calculate function
float calculate(float x) {

  //declare varialbe
  // for storing sumation and initialize as 0
  float sum = 0.0;

  //start while loop
  //until x reach 0
  while (x > 0) {
    //sum the number
    sum = sum + 1/x;
    //reducing x
    x--; //decreacing by 1 each time
  }
  //returning sum value and finishing the function
  return sum;
}

//main function
int main() {

  //decalre variable
  int value;

  //ask question
  printf("Enter a value to calculate the value of this harmonic series: ");

  //scaning the number
  scanf("%d", &value); //store to variable "value"

  //while loop start
  // until value reach 0
  while(value <= 0) {
    //keep printing and aksing question
    printf("\nPlease enter a POSITIVE Number: ");
    //scanning the value
    scanf("%d", &value); //store to variable "value"
  }

  //printing final value
  printf("\nThe value for the series is: %f.\n\n", calculate(value));

  //finishing the function
  return 0;
}
