/*Filename: A1deprec.c *
 *Part of: Assignment 1 A290 program *
 *Created by: Won Yong Ha *
 *Created on: 5/17/2016 *
 *Last Modified by: Won Yong Ha *
 *Last Modified on: 5/17/2016 *
 */

#include <stdio.h>

int main() {

  //declare variable for storing value
  int p_price; //price value
  float years, depre; //years and depre value

  //asking value and receiving
  printf("Enter the purchase price, years of service, annual depreciation:\n");
  scanf("%d %f %f", &p_price, &years, &depre); //getting and storing value

  //calculating and print the value
  printf("The salvage value of the item is %f\n", p_price -  (depre * years));

  //finishing program
  return 0;
}
