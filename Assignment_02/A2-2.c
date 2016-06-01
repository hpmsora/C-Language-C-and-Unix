/*Filename: A2.c * 
 *Part of: Assignment 2 A290 *
 *Created by: Won Yong Ha * 
 *Created on: 5/25/2015 * 
 *Last Modified by: Won Yong Ha * 
 *Last Modified on: 5/29/2016 * 
*/ 

/*Import C Library*/
#include <stdio.h>
#include <string.h>


/*Array Function*/
void arrays() {

  /*Declare variables*/
  int size, count = 0;

  printf("Enter the size of the arrays:\n");
  scanf("%d", &size);

  /*Declare arrays*/
  int first_num_arr[size], second_num_arr[size];

  /*Asking and getting first array elements*/
  printf("Enter elements of the first array:\n");
  while(count < size && scanf("%d", &first_num_arr[count]) != EOF)
    count++; //increase the count
  count = 0; //re-initialize the count

  /*Asking and getting second array elements*/
  printf("Enter elements of the second array:\n");
  while(count < size && scanf("%d", &second_num_arr[count]) != EOF)
    count++; //increase the count
  count = 0; //re-initialize the count

  /*Declare arrays*/
  int result[size * 2], unresult[size * 2];

  /*Declare a varialbe*/
  int res_count = 0, res_size = 0, unres_size = 0, unres_count = 0;

  /*Comparing*/
  //First Arr
  while(count < size) { //check and fit in the size
    while(res_count < res_size) { //check the counts
      if(result[res_count] == first_num_arr[count]) {
	//unresult list
	while(unres_count < unres_size) {
	  if(unresult[unres_count] == first_num_arr[count]) //check the duplication
	    break; //breatk the latest while loop
	  unres_count++; //increase the count;
        }
	if(unres_count == unres_size) { //adding on the list
	  unresult[unres_count] = first_num_arr[count];
	  unres_size++; //increase the size
	}
	unres_count = 0; //re-initialize the count
	break; //break the latest while loop
      }
      res_count++; //increase the count
    }
    //result list
    if(res_count == res_size) { //adding on the list
      result[res_count] = first_num_arr[count];
      res_size++; //increase the size
    }
    res_count = 0; //re-initialize the count
    count++; //increase the count
  }
  count = 0; //re-initialize the count for second array
  //Second Arr
  while(count <size) { //check and fit in the size
    while(res_count < res_size) { //check the counts
      if(result[res_count] == second_num_arr[count]) {
	//unresult list
        while(unres_count < unres_size) {
          if(unresult[unres_count] == second_num_arr[count]) //check the duplication
            break; //break the latest while loop
          unres_count++; //increase the count
        }
        if(unres_count == unres_size) { //adding on the list
          unresult[unres_count] = second_num_arr[count];
	  unres_size++; //increase the size
        }
        unres_count = 0; //re-initialize the count
        break; //break the latest while loop
      }
      res_count++; //increase the count
    }
    //result list
    if(res_count == res_size) { //adding on the list
      result[res_count] = second_num_arr[count];
      res_size++; //increase the size
    }
    res_count = 0; //re-initialize the count
    count++; //increase the count
  }

  /*Declare a variable*/
  int i;

  /*Print the intersection result*/
  printf("The intersection of two arrays is: ");
  for(i = 0; i < unres_size; i++) {
    printf("%d", unresult[i]); //print the unresult
  }

  /*Print the union result*/
  printf("\nThe union of two arrays is: ");
  for(i = 0; i < res_size; i++) {
    printf("%d", result[i]); //print the result
  }
  printf("\n\n\n");

}


/*Matrices Function*/
void matrices(int input[4][5], int output[5][4]) {

  /*Declare varialbes*/
  int i = 0, j = 0;

  /*Print input matrix*/
  printf("The original matrix was:\n");
  while(i < 4) { //check the row size
    while(j < 5) { //check the column size
      printf("%d ", input[i][j]); //print the element
      j++; //increase j count
    }
    printf("\n");
    i++; //increase i count
    j = 0; //Re-initialize j
  }

  /*Re-initialize*/
  i = 0;
  j = 0;

  /*Transposing*/
  while(i < 4) { //check the row size
    while(j < 5) { //check the column size
      output[j][i] = input[i][j]; //swap the values
      j++; //increae the j count
    }
    j = 0; //Re-initialize j 
    i++; //increase the i count
  }

  /*Re-initialize*/
  i = 0;
  j = 0;

  /*Print output matrix*/
  printf("\n");
  printf("The transposed matrix is:\n");
  while(i < 5) { //check the row size
    while(j < 4) { //check the column size
      printf("%d ", output[i][j]); //print the element
      j++; //increase the j count
    }
    printf("\n");
    i++; //increase the i count
    j = 0; //Re-initialize j 
  }
  printf("\n\n");
}


/*Calculations Function*/
void calculations() {

  /*Initial Comments Printing*/
  printf("Begin Calculations\n");
  printf("\n");
  printf("Initialize your Accumulator with data of the form\n");
  printf("\"number\" \"S\" which sets the Accumulator to the value of your number\n");
  printf("\n");
  printf("To exit, enter a number and then \"E\".");
  printf("This Calculator is not designed to deal with non-numeric values.");
  printf("Please, no letters or puncuation.\n");

  /*Declare variables*/
  int count = 0;
  double accum = 0;
  float var, var_first, var_second;
  int length, x;
  int num_char = 0; //0 -> char / 1 -> num
  int deci_count = 0;
  /*Declare arrys*/
  char varr[25];
  char* letter = "A";

  /*Calculation*/
  while(strcmp(letter, "E") != 0) {
    while(scanf("%s", varr)) {
      /*First Step*/
      if(count == 0) { //check the order
        length = strlen(varr);
        for(x = 0; x < length; x++) { //check the whether number or character
          if(!isdigit(varr[x]) && !((varr[x] == '.') && (deci_count == 0))) { //double check for float point
            num_char = 0; //Initialize cahr number
	    deci_count = 0; //Initialize deci_count
            break; //break the latest loop
          }
	  if((varr[x] == '.') && (deci_count == 0)) //checking for float point
	    count++;
	  if(varr[x] == '.') { //second checking for float point
	    deci_count++; //increasing deci_count
	  }
        }
        if(x == length) { //check the number or not
          num_char = 1;
        }
        if(num_char == 1) { //if number put in the first var
	  if(deci_count == 1) {
	    printf("%s\n", varr);
	    sscanf(varr, "%f", &var_first); //casting to double
	    printf("%f\n", var_first);
	  }
	  else {
	    var_first = atoi(varr); //change to integer value
	  }
          count = 1; //change to go to second step
        }
        else {
          printf("Unknown operator.\n"); //check whether unknown command
        }
	deci_count = 0;
      }
      /*Second Step*/
      else if(count == 1) {
	length = strlen(varr);
	for(x = 0; x < length; x++) { //check the whether number or character
	  if(!isdigit(varr[x])) {
	    num_char = 0; //initialize the char number
	    break; //break the latest loop
	  }
	}
	if(x == length) {
	  num_char = 1; //change the char number condition
	}
	/*Operator Checking*/
	if(num_char == 0) { //check whether number or character
	  if(strcmp(varr, "+") == 0) { // " + "
	    accum = accum + var_first;
	  }
	  else if(strcmp(varr, "-") == 0) { // " - "
	    accum = accum - var_first;
	  }
	  else if(strcmp(varr, "*") == 0) { // " * "
	    accum = accum * var_first;
          }
	  else if(strcmp(varr, "/") == 0) { // " / "
	    if(var_first == 0)
	      printf("Can not divide by 0.\n"); //checking validation of division
	    else
	      accum = accum / var_first;
          }
	  else if(strcmp(varr, "S") == 0) { // " S "
	    accum = var_first;
          }
	  else if(strcmp(varr, "E") == 0) { // " E "
	    letter = "E";
	    break; //break the latest loop and finish the Function
          }
	  else {
	    printf("Unknown operator.\n"); //Unknown operator
	  }
	}
	printf("Value in the Accumulator = %f\n", accum); //print the current accumulator
	count = 0; //Change the order to first step
      }
    }
  }

  /*Print the Ending Statement*/
  //End of the calculation
  printf("End of Calculation.\n");
  printf("\n\n");
}


/*Calling Function*/
int main() {
  
  /*Declare arrays*/
  int arr1[4][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {10, 9, 8, 7, 6}, {5, 4, 3, 2, 1}};
  int arr2[5][4];

  /*Calling all functions*/
  arrays();
  matrices(arr1, arr2);
  calculations();
  
  /*Finish the function*/
  return 0;
}
