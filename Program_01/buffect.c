/*Filename: buffet.c *
 *Part of: First A290 program *
 *Created by: Won Yong Ha *
 *Created on: 5/10/2016 *
 *Last Modified by: Won Yong Ha *
 *Last Modified on: 5/15/2016 *
 */

#include <stdio.h>

int main() {

  /* The body of your source code will go here */

  //--------------------------------------------------
  //3. sizeof printf
  printf("sizeof(char) == %d\n", sizeof(char)); //char
  printf("sizeof(short) == %d\n", sizeof(short)); //short
  printf("sizeof(int) == %d\n", sizeof(int)); //int
  printf("sizeof(long) == %d\n", sizeof(long)); //long
  printf("sizeof(float) == %d\n", sizeof(float)); //float
  printf("sizeof(double) == %d\n", sizeof(double)); //double
  printf("sizeof(long double) == %d\n", sizeof(long double)); //long double
  printf("sizeof(long long) == %d\n", sizeof(long long)); //long long

  //--------------------------------------------------
  //4. set of 6 variable
  //declare variable
  int x,y;
  char a;
  float f,e;
  double d;
  //insert value in variable
  x=4;
  y=7;
  a='H';
  f=-3.4;
  d=54.123456789;
  e=54.123456789;

  //--------------------------------------------------
  //5. two printf
  printf("x: %d\ny: %d\na: %c\n", x, y, a);
  printf("f: %f\nd: %f\ne: %f\n", f, d, e);

  //--------------------------------------------------
  //6. 5 variable
  int r1,r2,r3,r4,r5;

  //--------------------------------------------------
  //7. 4 basic arthmetic operator
  r1=x+y;
  r2=x-y;
  r3=x/y;
  r4=x*y;
  //printf
  printf("%d %d %d %d\n",r1,r2,r3,r4);

  //--------------------------------------------------
  //8. 3 additional arthmetic operations
  r3++;
  r4--;
  r5=r4%r1;
  //printf
  printf("%d %d %d\n",r3,r4,r5);


  //--------------------------------------------------
  //9. program
  //declare varialbe
  int i,j,number; //using only 3 variable.
  //Enter number
  printf("Enter a number: ");
  //receiving number
  scanf("%d",&number);
  i=1;
  //first while loop
  while (i*i <= number)
  {
    j=1;
    //second while loop
    while (j < i)
    {
      //if: the result match
      if (i*i + j*j == number)
	//printf
	printf("Found: %d + %d\n",i*i,j*j); //printf the answer
      j++;
    }
    i++;
  }


  //--------------------------------------------------
  //check its working
  printf("Hello World\n");

  return 0;

}
