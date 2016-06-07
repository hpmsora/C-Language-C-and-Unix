/*Filename: A3.c *
 *Part of: Third A290 program *
 *Created by: Won Yong Ha *
 *Created on: 6/6/2016 *
 *Last Modified by: Won Yong Ha *
 *Last Modified on: 6/6/2016 *
 */

/*Importing Libraries*/
#include <stdio.h>

/*printStatement Function*/
void printStatement() {

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

  int num, shift;

  printf("Enter a base 10 Interger: ");
  scanf("%d", &num);
  printf("Enter number of places to shirft bit: ");
  scanf("%d", &shift);

}

/*functionOption Function*/
void functionOption(int op) {

  if(op == 1) {
    option_1_LeftBit();
  }
  else if(op == 2) {
  }
  else if(op == 3) {
  }
  else if(op == 4) {
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
