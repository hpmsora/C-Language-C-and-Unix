/*Filename: callinggunc.c *
 *Part of: Second A290 program *
 *Created by: Won Yong Ha *
 *Created on: 5/23/2016 *
 *Last Modified by: Won Yong Ha *
 *Last Modified on: 5/25/2016 *
 */

#include <stdio.h>

//function loops
int loops(void)
{
  /*Delcare 2 variables*/
  int i,x;
  /*Initialize x*/
  x=0;
  /*for loop: runs for values of i = 0, 1, 2, and 3*/
  printf("This is a ‘for’ loop\n");
  
  /*Initialize i and start a for loop*/
  for (i=0; i<4; i++)
    {
      x=x+i;
      printf("%d\n",x); //print result
    }

  /*while loop runs until i is less than 7, but what is the starting value of i for this
    loop?*/
  printf ("This is a ‘while’ loop\n");

  /*Start a while loop until i is smaller than 7*/
  while (i<7)
    {
      x=x+i;
      i++;
      printf("%d\n",x); //print result
    }
  /*do-while loop runs until i is less than 9, but runs at least once. What is the starting
    value of i for this loop?*/
  printf ("This is a ‘do-while’ loop\n");

  /*Start do-while loop until i is smaller than 9*/
  do
    {
      x=x+i;
      i++;
      printf("%d\n",x); //prrint result
    }
  while (i<9);

  //Finish the function
  return(0);
}

//function conditionals
int conditionals(void)
{
  /*Declare 2 variables*/
  int i,x;
  /*Initialize x*/
  x=0;

  /*Initialize i and start a for loop*/
  for (i=0; i<5; i++)
    {
      if (i%2 == 0 || i == 1) //if statement whether i is 1 or even number
	x=x+i;
      else //if statment false
	x=x-i;
      printf("%d\n",x); //printing result
    }

  //Finish the function
  return(0);
}

//function firstswap
void firstswap()
{
  /*Declare 4 variables*/
  int i,j,k,swap;
  /* Array “c” of chars with 8 cells*/
  char c[8];
  /*Initialize first 5 cells with values. Other 3 are empty*/
  c[0]='f'; c[1]='r'; c[2]='o'; c[3]='g'; c[4]=0;
  
  printf("Initial values for first 5 cells: %c,%c,%c,%c,%c\n",c[0],c[1],c[2],c[3],c[4]);
  /*Initialize i and start a for loop*/
  for (i=0; i<4; i++)
    {
      /*Initialize k as equal to incremented i*/
      k=i;
      /*Initialize j as one greater than i and k*/
      for (j=i+1; j<4; j++)
	if (c[j]-c[k] < 10) /*What does this means or do?*/
	  k=j;
      //---------------
      /*Swapping process*/
      swap=c[i];
      c[i]=c[k];
      c[k]=swap;
      //---------------
    }

  //print result
  printf("Final values: i: %d, j: %d, k: %d, swap: %d\n",i,j,k,swap);
  printf("Final values for first 5 cells after we swap: %c,%c,%c,%c,%c\n",c[0],c[1],c[2],c[3],c[4]);
}

//main: calling function
int main(void)
{
  //print conditionals
  printf("THIS IS MY CONDITIONALS FUNCTION.\n\n");
  conditionals(); //call function conditionals

  //print loops
  printf("THIS IS MY LOOPS FUNCTION.\n\n");
  loops(); //call function loops

  //print firstswap
  printf("THIS IS MY FIRST ARRAY FUNCTION.\n\n");
  firstswap(); //call function firstswap

  //Finish the function
  return(0);
}
