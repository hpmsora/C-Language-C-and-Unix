/*Filename: A3.c *
 *Part of: Third A290 program *
 *Created by: Won Yong Ha *
 *Created on: 6/6/2016 *
 *Last Modified by: Won Yong Ha *
 *Last Modified on: 6/6/2016 *
 */

/*Importing Libraries*/
#include <stdio.h>
#include <string.h>
#include <math.h>

/*printStatement Function*/
void printStatement() {

  printf("\n");
  printf("\t\tMain Menu\n");
  printf("\t\t---------\n");
  printf("1. Perform Left Bit Shift Operation (one value)\n");
  printf("2. Perform Right Bit Shift Operation (one value)\n");
  printf("3. Perform Binary AND Operation (two values)\n");
  printf("4. Perform Binary OR Operation (two values)\n");
  printf("5. Perform Binary One's Complement (~) Operation (one value)\n");
  printf("6. Perform Binary XOR Operation (two values)\n");
  printf("7. Quit\n");

}

/*option_1_LeftBit Function*/
void option_1_LeftBit() {

  /*Declare variables*/
  int num, shift, num_origin;
  int count = 0;
  int PosOrNeg = 1; //1 -> Pos  0 -> Neg
  int num_binary[32] = {0};
  int num_binary_temp[32] = {0};

  /*Print question and get numbers*/
  printf("\nEnter a base 10 Interger: ");
  scanf("%d", &num);
  num_origin = num;
  printf("\nEnter number of places to shift bit: ");
  scanf("%d", &shift);

  /*num to binary*/
  /*Check wether positive or negetive number*/
  if(num < 0) {
    num *= -1;
    num++;
    PosOrNeg = 0;
  }

  /*While loop*/
  while(num != 0) {
    num_binary_temp[count] = num % 2;
    num /= 2;
    count++;
  }

  /*for loop*/
  /*neg check*/
  if(PosOrNeg == 0) {
    for(count = 0; count < 32; count++) {
      if(num_binary_temp[count] == 0)
	num_binary_temp[count] = 1;
      else
	num_binary_temp[count] = 0;
    }
  }

  /*for loop*/
  /*reverse array*/
  for(count = 0; count < 32; count++)
    num_binary[count] = num_binary_temp[31 - count];

  /*Print binary*/
  printf("\n\n\tEntered Integer: ");
  for(count = 0; count < 32; count++)
    printf("%d", num_binary[count]);
  printf("  (base 10 %d)\n", num_origin);

  /*for loop*/
  /*Initialize the num_binary*/
  for(count = 0; count < 32; count++)
    num_binary[count] = 0;

  /*for loop*/
  /*shifting left with reverse array*/
  for(count = 0; count < (32 - shift); count++)
    num_binary[31 - count - shift] = num_binary_temp[count];

  /*for loop*/
  /*calculate num*/
  for(count = 31; count >= 0; count--)
    num += num_binary[count] * (int) pow(2, 31 - count);

  /*Print binary*/
  printf("\tLeft Shifted   : ");
  for(count = 0; count < 32; count++)
    printf("%d", num_binary[count]);
  printf("  (base 10 %d)\n", num);
}

/*option_1_LeftBit Function*/
void option_2_RightBit() {

  /*Declare variables*/
  int num, shift, num_origin;
  int count = 0;
  int PosOrNeg = 1; //1 -> Pos  0 -> Neg
  int num_binary[32] = {0};
  int num_binary_temp[32] = {0};

  /*Print question and get numbers*/
  printf("\nEnter a base 10 Interger: ");
  scanf("%d", &num);
  num_origin = num;
  printf("\nEnter number of places to shift bit: ");
  scanf("%d", &shift);

  /*num to binary*/
  /*Check wether positive or negetive number*/
  if(num < 0) {
    num *= -1;
    num--;
    PosOrNeg = 0;
  }

  /*While loop*/
  while(num != 0) {
    num_binary_temp[count] = num % 2;
    num /= 2;

    count++;
  }

  /*for loop*/
  /*neg check*/
  if(PosOrNeg == 0) {
    for(count = 0; count < 32; count++) {
      if(num_binary_temp[count] == 0)
	num_binary_temp[count] = 1;
      else
	num_binary_temp[count] = 0;
    }
  }

  /*for loop*/
  /*reverse array*/
  for(count = 0; count < 32; count++)
    num_binary[count] = num_binary_temp[31 - count];

  /*Print binary*/
  printf("\n\n\tEntered Integer: ");
  for(count = 0; count < 32; count++)
    printf("%d", num_binary[count]);
  printf("  (base 10 %d)\n", num_origin);

  /*for loop*/
  /*Initialize the num_binary*/
  for(count = 0; count < 32; count++)
    num_binary[count] = 0;

  /*for loop*/
  /*shifting left with reverse array*/
  for(count = 0; count < (32 - shift); count++)
    num_binary[31 - count] = num_binary_temp[count + shift];

  /*for loop*/
  /*calculate num*/
  for(count = 31; count >= 0; count--)
    num += num_binary[count] * (int) pow(2, 31 - count);

  /*Print binary*/
  printf("\tRight Shifted  : ");
  for(count = 0; count < 32; count++)
    printf("%d", num_binary[count]);
  printf("  (base 10 %d)\n", num);
}

/*option_3_AndOpr Function*/
void option_3_AndOpr() {

  /*Declare variables*/
  int num_1, num_2, num_origin_1, num_origin_2;
  int num = 0;
  int count = 0;
  int PosOrNeg_1 = 1;  //1 -> Pos  0 -> Neg
  int PosOrNeg_2 = 1;  //1 -> Pos  0 -> Neg
  int num_binary[32] = {0};
  int num_binary_1[32] = {0};
  int num_binary_2[32] = {0};
  int num_binary_temp_1[32] = {0};
  int num_binary_temp_2[32] = {0};

  /*Print question and get numbers*/
  printf("\nEnter two base 10 Integers, separated by a space: ");
  scanf("%d %d", &num_1, &num_2);

  /*Save original value*/
  num_origin_1 = num_1;
  num_origin_2 = num_2;

  /*num to binary*/
  /*Check wether positive or negetive number*/
  if(num_1 < 0) {
    num_1 *= -1;
    num_1--;
    PosOrNeg_1 = 0;
  }

  /*Check wether positive or negetive number*/
  if(num_2 < 0) {
    num_2 *= -1;
    num_2--;
    PosOrNeg_2 = 0;
  }

  /*While loop*/
  while(num_1 != 0) {
    num_binary_temp_1[count] = num_1 % 2;
    num_1 /= 2;
    count++;
  }

  /*Reinitialize variable*/
  count = 0;

  /*While loop*/
  while(num_2 != 0) {
    num_binary_temp_2[count] = num_2 % 2;
    num_2 /= 2;
    count++;
  }

  /*for loop*/
  /*neg check num 1*/
  if(PosOrNeg_1 == 0) {
    for(count = 0; count < 32; count++) {
      if(num_binary_temp_1[count] == 0)
	num_binary_temp_1[count] = 1;
      else
	num_binary_temp_1[count] = 0;
    }
  }

  /*for loop*/
  /*neg check num 2*/
  if(PosOrNeg_2 == 0) {
    for(count = 0; count < 32; count++) {
      if(num_binary_temp_2[count] == 0)
	num_binary_temp_2[count] = 1;
      else
	num_binary_temp_2[count] = 0;
    }
  }

  /*for loop*/
  /*reverse array*/
  for(count = 0; count < 32; count++) {
    num_binary_1[count] = num_binary_temp_1[31 - count];
    num_binary_2[count] = num_binary_temp_2[31 - count];
  }

  /*Print binary num 1*/
  printf("\n\n\tEntered Integer 1: ");
  for(count = 0; count < 32; count++)
    printf("%d", num_binary_1[count]);
  printf("  (base 10 %d)\n", num_origin_1);

  /*Print binary num 2*/
  printf("\tEntered Integer 2: ");
  for(count = 0; count < 32; count++)
    printf("%d", num_binary_2[count]);
  printf("  (base 10 %d)\n", num_origin_2);

  /*for loop*/
  /*AND's calculation*/
  printf("\tAND'ed           : ");
  for(count = 0; count < 32; count++) {
    if(num_binary_1[count] == num_binary_2[count])
      num_binary[count] = num_binary_1[count];
    else
      num_binary[count] = 0;
  }

  /*for loop*/
  /*print the binary*/
  for(count = 0; count < 32; count++)
    printf("%d", num_binary[count]);

  /*for loop*/
  /*calculate num*/
  for(count = 31; count >= 0; count--)
    num += num_binary[count] * (int) pow(2, 31 - count);

  /*Print the number*/
  printf("  (base 10 %d)", num);

}

void option_4_OrOpr() {

  /*Declare variables*/
  int num_1, num_2, num_origin_1, num_origin_2;
  int num = 0;
  int count = 0;
  int PosOrNeg_1 = 1;  //1 -> Pos  0 -> Neg
  int PosOrNeg_2 = 1;  //1 -> Pos  0 -> Neg
  int num_binary[32] = {0};
  int num_binary_1[32] = {0};
  int num_binary_2[32] = {0};
  int num_binary_temp_1[32] = {0};
  int num_binary_temp_2[32] = {0};

  /*Print question and get numbers*/
  printf("\nEnter two base 10 Integers, separated by a space: ");
  scanf("%d %d", &num_1, &num_2);

  /*Save original value*/
  num_origin_1 = num_1;
  num_origin_2 = num_2;

  /*num to binary*/
  /*Check wether positive or negetive number*/
  if(num_1 < 0) {
    num_1 *= -1;
    num_1--;
    PosOrNeg_1 = 0;
  }

  /*Check wether positive or negetive number*/
  if(num_2 < 0) {
    num_2 *= -1;
    num_2--;
    PosOrNeg_2 = 0;
  }

  /*While loop*/
  while(num_1 != 0) {
    num_binary_temp_1[count] = num_1 % 2;
    num_1 /= 2;
    count++;
  }

  /*Reinitialize variable*/
  count = 0;

  /*While loop*/
  while(num_2 != 0) {
    num_binary_temp_2[count] = num_2 % 2;
    num_2 /= 2;
    count++;
  }

  /*for loop*/
  /*neg check num 1*/
  if(PosOrNeg_1 == 0) {
    for(count = 0; count < 32; count++) {
      if(num_binary_temp_1[count] == 0)
	num_binary_temp_1[count] = 1;
      else
	num_binary_temp_1[count] = 0;
    }
  }

  /*for loop*/
  /*neg check num 2*/
  if(PosOrNeg_2 == 0) {
    for(count = 0; count < 32; count++) {
      if(num_binary_temp_2[count] == 0)
	num_binary_temp_2[count] = 1;
      else
	num_binary_temp_2[count] = 0;
    }
  }

  /*for loop*/
  /*reverse array*/
  for(count = 0; count < 32; count++) {
    num_binary_1[count] = num_binary_temp_1[31 - count];
    num_binary_2[count] = num_binary_temp_2[31 - count];
  }

  /*Print binary num 1*/
  printf("\n\n\tEntered Integer 1: ");
  for(count = 0; count < 32; count++)
    printf("%d", num_binary_1[count]);
  printf("  (base 10 %d)\n", num_origin_1);

  /*Print binary num 2*/
  printf("\tEntered Integer 2: ");
  for(count = 0; count < 32; count++)
    printf("%d", num_binary_2[count]);
  printf("  (base 10 %d)\n", num_origin_2);

  /*for loop*/
  /*Or's calculation*/
  printf("\tOR'ed            : ");
  for(count = 0; count < 32; count++) {
    if((num_binary_1[count] == 1) || (num_binary_2[count] == 1))
      num_binary[count] = 1;
    else
      num_binary[count] = 0;
  }

  /*for loop*/
  /*print the binary*/
  for(count = 0; count < 32; count++)
    printf("%d", num_binary[count]);

  /*for loop*/
  /*calculate num*/
  for(count = 31; count >= 0; count--)
    num += num_binary[count] * (int) pow(2, 31 - count);

  /*Print the number*/
  printf("  (base 10 %d)", num);

}

/*functionOption Function*/
void functionOption(int op) {

  if(op == 1)
    option_1_LeftBit();
  else if(op == 2)
    option_2_RightBit();
  else if(op == 3)
    option_3_AndOpr();
  else if(op == 4) {
    option_4_OrOpr();
  }
  else if(op == 5) {
  }
  else if(op == 6) {
  }
}

/*Main Function*/
int main() {

  /*Declare varialbes*/
  int option = 0;

  /*while Loop*/
  while(option != 7) { //keep while loop until option is 7
    printStatement();
    scanf("%d", &option);
    functionOption(option);
  }

  return 0;
}
