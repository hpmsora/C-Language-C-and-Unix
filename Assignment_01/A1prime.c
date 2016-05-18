/*Filename: A1prime.c *
 *Part of: Assignment 1 A290 program *
 *Created by: Won Yong Ha *
 *Created on: 5/17/2016 *
 *Last Modified by: Won Yong Ha *
 *Last Modified on: 5/17/2016 *
 */

#include <stdio.h>

//function isPrime
// returning whether the number is prime or not
// 0 -> not prime
// 1 -> prime
int isPrime(int x) {

  //declare variable
  // for counting
  int count = 2;

  //start a first while loop
  while (count != x) {
    //x mod count 0 min x can be dividable.
    if (x % count == 0)
      //return 0 -> not prime
      return 0; //break the while loop and finish the function
    //increasing count
    count++; //count = count + 1;
  }
  //No dividable
  //return 1 -> prime
  return 1; //finish the function
}

//main function
int main() {

  //declare variable
  // storing value
  int value;

  //start infinite while loop for keep asking the number
  while(1) {
    //print the question and receive the number
    printf("Enter a number to check if it is a prime number:\n\n");
    //scan the number and store in value
    scanf("%d", &value); //store to value

    //extra line for convinient
    printf("\n");
    
    //check the prime
    if(isPrime(value))
      //prime -> print
      printf("The number %d is a prime number.\n\n", value);
    else {
      //not prime -> print
      printf("The number %d is not a prime number.\n\n", value);
      return 0; //break the while loop and finish the function
    }
  }
}
