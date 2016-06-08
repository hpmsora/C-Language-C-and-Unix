/*Filename: P3.c *
 *Part of: Third A290 program *
 *Created by: Won Yong Ha *
 *Created on: 6/7/2016 *
 *Last Modified by: Won Yong Ha *
 *Last Modified on: 6/7/2016 *
 */

/*Imported Libraries*/
#include <stdio.h>
#include <string.h>
#include <math.h> 

/*bitmodels Function*/
int bitmodels() {

  /*Declaring some variables of different types */
  unsigned char a;
  unsigned char b,c;
  unsigned char d,e;
  char f;
  int i;
  
  /*Various bitwise operations*/
  /*~*/
  a=17;
  a=~a;
  /*Print the result*/
  printf("bitwise NOT of 17\n");
  printf("%d\n",a);

  /*&*/  
  b=17;
  c=22;
  b=b & c;
  /*Print the result*/
  printf("bitwise AND of 17 and 22\n");
  printf("%d\n",b);
  d=17;
  e=22;

  /*|*/
  d=d | e;
  /*Print the result*/
  printf("bitwise OR of 17 and 22\n");
  printf("%d\n",d);

  /*| <<*/
  f=17;
  f=f | (1 << 3); /* set bit #3 */
  /*Print the result*/
  printf("Sets bit #3 in 17, new value is 17+8=25\n");
  printf("%d\n",f);

  /*& ~ <<*/
  f=f & (~(1<<4)); /* clear bit #4 */
  /*Print the result*/
  printf("Clears bit #4 in 25, new value is 25-16=9\n");
  printf("%d\n",f);
  printf("Reads i-th bit in current value of f (which is the base10 number 9),\nplus a loop that prints every bit in 8-bit space\n");

  /*Print all elements*/
  for (i=7; i>=0; i--)
    printf("%d ",(f&(1<<i)) >> i); /* read i'th bit */
  printf("\n");
  printf("Current value of a\n");
  for (i=7; i>=0; i--)
    printf("%d ",(a&(1<<i)) >> i); /* read i'th bit */
  printf("\n");
  printf("Current value of d\n");
  for (i=7; i>=0; i--)
    printf("%d ",(d&(1<<i)) >> i); /* read i'th bit */
  printf("\n");
  printf("Current value of e\n");
  for (i=7; i>=0; i--)
    printf("%d ",(e&(1<<i)) >> i); /* read i'th bit */
  printf("\n");

  /*Finishing the function*/
  return (0);
}

/*pointers Function*/
int pointers() {

  /*Declaring some variables of different types */
  int count, x;
  int *count_p;
  char letter;
  char *letter_p = &letter;

  /*Assigning specific values to the declared variables */
  count=10;
  count_p=&count;
  x=*count_p;
  letter = 'Q';

  /*Let's print the contents of count and x*/
  printf("Here's is the step-by-step output from the integer pointer example\n");
  /*Let's confirm the values of count and x*/
  printf("count = %i and x = %i\n", count, x);
  /*Let's change count using the pointer count_p*/
  *count_p = 42;
  /*Let's print the contents of count and x again*/
  printf("count = %i and x = %i\n", count, x);
  /*Let's change count to the value of x*/
  count = x;
  /*Let's print the contents of count and x again*/
  printf("count = %i and x = %i\n", count, x);

  printf("Here's is the step-by-step output from the character pointer example\n");
  /*Let's confirm the values of letter and letter_p*/
  printf("letter = %c and letter_p = %c\n", letter, *letter_p);
  /*Let's change letter but not letter_p*/
  letter = '/';
  /*Let's print the contents of letter and letter_p again*/
  printf("letter = %c and letter_p = %c\n", letter, *letter_p);
  /*Let's change letter_p but not letter*/
  *letter_p = '!';
  /*Let's print the contents of letter and letter_p again*/
  printf("letter = %c and letter_p = %c\n", letter, *letter_p);
  
  /*Finishing the function*/
  return (0);x=*count_p;

}

/*morepointers Function*/
int morepointers() {

  /*Declaring some variables of different types */
  int firsti, secondi;
  int *firsti_p, *secondi_p;

  /*Assigning specific values to the declared variables */
  firsti=5;
  firsti_p=&firsti;
  secondi = *firsti_p / 2 + 10;
  secondi_p = firsti_p;

  /*Let's print the outcome of our first set of int and int pointers*/
  printf("Here the output from the first integer pointer example\n");

  /*Let's confirm all the values*/
  printf("firsti = %i, secondi = %i, value of firsti_p = %i and value of secondi_p = %i\n", firsti, secondi, *firsti_p, *secondi_p);
  
  /*Finishing the function*/
  return (0);

}

/*Declaring function prototype as needed */
int division(int numerator, int denominator, int *dividend, int *remainder);

/*pointerfunction Function*/
int pointerfunction() {
  
  /*int variables for main that will be used in call of division*/
  int x,y,d,r;
  x=9;
  y=2;
  printf("address of d: %u\n",&d); /*address where dividend in function should point*/
  printf("address of r: %u\n",&r); /*address where remainder in function should	point*/
  division(x,y,&d,&r);
  printf("%d/%d = %d with %d remainder\n",x,y,d,r);
  printf("x=%d\n",x);
  
  /*Finishing the function*/
  return(0);
  
}

/*division Function*/
/*This is the division function, with 2 int variables and 2 int pointer variables*/
int division(int numerator, int denominator, int *dividend, int *remainder)
{
  printf("address stored in dividend: %u\n",dividend);
  printf("address stored in remainder: %u\n",remainder);
  
  if (denominator < 1)
    return(0);
  *dividend=numerator/denominator;
  *remainder=numerator%denominator;
  numerator=7;
}

/*pointerarithmetic Function*/
int pointerarithmetic() {

  /*Declaring some variables of different types */
  char ca[3],*cp;
  int ia[3],*ip;

  /*Assigning specific values to the declared variables */
  ca[0]='A';
  ca[1]='B';
  ca[2]='c';
  cp=&(ca[0]);
  ia[0]=1234;
  ia[1]=5678;
  ia[2]=9999;
  ip=&(ia[0]);

  /*Show output, then use pointers, then show output again. */
  printf("char pointer cp points to value = %c\n",*cp);
  printf("ca[2] = %c\n", ca[2]);
  printf("int pointer ip points to value = %i\n", *ip);
  printf("ia[2] = %i\n",ia[2]);

  /*Editting the array elements*/
  *(cp+2) = 'Q';
  *(ip+2) = 33;

  /*Print the result*/
  printf("Results after we apply pointer arithmetic.\n");
  printf("ca[2] = %c\n",ca[2]);
  printf("ia[2] = %i\n",ia[2]);

  /*Finishing the function*/
  return (0);

}

/*pointerarray Function*/
int pointerarray() {

  /*Declare variables*/
  double array[10];
  double *d_ptr;
  double value;
  int i,offset;

  /*Initializint the array*/
  for (i=0; i<10; i++)
    array[i]=(double)i+10.0; /* access memory using array index and fill cells with #s*/
  d_ptr=&(array[0]); /* access memory location of first array cell using pointer*/
  
  /*while loop*/
  while (1) //continuing asking until break
    {
      printf("\nAddress(hex)\tAddress(base10)\tValue\n");
      /*for loop*/
      for (i=0; i<10; i++) //printing all elements in the array
	printf("%p\t%u\t%lf\n",&(array[i]),&(array[i]),array[i]);
      
      /*Shwoing the options*/
      printf("Enter offset value (0 0 to quit): "); //getting options
      scanf("%d %lf",&offset,&value); //receving the option

      if (offset == 0 && value == 0.0) //checking the value
	break; /* break out of loop */
      
      if (offset < 0 || offset > 9)
	{
	  printf("Offset out of bounds\n");
	  continue; /* go back to start of loop */
	}
      /* Three ways to do the same thing */
      /*NOTE FROM JEFF: First one listed will be the one used at compile time
	To test each one, change order, or comment out all but one*/
      array[offset]=value; /* using array syntax */
      /* *(d_ptr+offset)=value; using pointer syntax */
      /* *(array+offset)=value; using mixed syntax */
    }

  /*Finishing the function*/
  return (0);

}

/*organizing Function*/
void organizing() {
  /*Printing organization tools*/
  printf("\n");
  printf("---------------------------------------------------------\n");
}

/*main Function*/
int main() {

  /*Calling the functions*/
  organizing();
  printf("\t/*bitmodels*/\n\n");
  bitmodels(); //calling bitmodels function
  printf("\n");

  organizing();
  printf("\t/*pointers*/\n\n");
  pointers(); //calling pointers function
  printf("\n");

  organizing();
  printf("\t/*morepointers*/\n\n");
  morepointers(); //calling morepointers function
  printf("\n");

  organizing();
  printf("\t/*pointerfunction*/\n\n");
  pointerfunction(); //calling pointerfunction function
  printf("\n");

  organizing();
  printf("\t/*pointerarithmetic*/\n\n");
  pointerarithmetic(); //calling pointerarithmetic function
  printf("\n");

  organizing();
  printf("\t/*pointerarray*/\n\n");
  pointerarray(); //calling pointerarray function
  printf("\n");

  /*Last Organizing*/
  printf("\n");

  /*Finishing the Function*/
  return 0;
}
