/*Filename: A4.c *
*Part of: Fourth A290 Assignment *
*Created by: Won Yong Ha *
*Created on: 6/13/2016 *
*Last Modified by: Won Yong Ha *
*Last Modified on: 6/16/2016 *
*/ 

/*Importing Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------------------------------------------------------------*/
/*Cricket*/

/*Linked List structure type*/
/*Structure declaration*/
/*team_t*/
typedef struct team {
  char teamName[99];
  char memberInfo_name[11][99];
  float avg[11];
  int memSize;
  struct team* next;
} team_t;

/*Prototype Function*/
void printMember(team_t* teams);
void memberInfo(team_t* teams, int num);
void namingTeam(team_t* teams, int num);
void Cricket();

/*namingTeam Function*/
void namingTeam(team_t* teams, int num) {

  /*Declare variables*/
  char name[99];
  team_t* current = teams;

  /*while loop*/
  /*Getting the name of team(s)*/
  while(num != 0) {

    /*Print the question*/
    printf("Enter the name(s) of the teams: ");
    scanf("%s", &name); //getting name

    /*if statement*/
    /*Check the size of list*/
    if(num == 1) {
      /*Insert the name*/
      strcpy(current->teamName, name);
      current->memSize = 0; //initialize the size
      num--;
    }
    else {
      /*Insert the name*/
      strcpy(current->teamName, name); //insert the name;
      current->memSize = 0; //initialize the size;
      current->next = malloc(sizeof(team_t)); //initialize the next linked element
      current = current->next;
      current->next = NULL; //initialize the next element
      num--;
    }
  }

  /*Organization gap line*/
  printf("\n");

}

/*memberInfo function*/
void memberInfo(team_t* teams, int num) {

  /*Declare variables*/
  char member_Name[99];
  char team_Name[99];
  int pos = 0, count = 1;
  float b_avg;
  team_t* current = teams;

  /*while loop*/
  /*Inserting the member information*/
  while(count <= num) {

    /*Print the question*/
    printf("Enter the %d Player name, Team name, and batting average: ", count);
    scanf("%s %s %f", &member_Name, &team_Name, &b_avg); //getting answer

    /*while loop*/
    /*Checking the team*/
    while(current != NULL) {

      /*if statement*/
      if(strcmp(current->teamName, team_Name) == 0) {

	/*Store variables*/
	pos = current->memSize;
	strcpy(current->memberInfo_name[pos], member_Name); //save name
	current->avg[pos] = b_avg; //store average
	
	/*Member size increase*/
	pos++;
	current->memSize = pos;

	break; //break the while loop
      }

      /*Next team*/
      current = current->next;
    }

    /*Increase the count*/
    count++;

    /*Reinitialize the current*/
    current = teams;
  }

  /*Organize gap line*/
  printf("\n\n");

}

/*printMemeber Function*/
void printMember(team_t* teams) {

  /*Declare variables*/
  int mSize = 0, count;
  team_t* current = teams;

  /*Print the statement*/
  printf("Listing of player and batting average according to team names::\n");

  /*while loop*/
  while(current != NULL) {
    printf("%s-\n", current->teamName);
    mSize = current->memSize; //initialize the mSize
    count = 0; //initialize the count
    /*while loop*/
    while(count < mSize) {
      printf("\t%s\t%f\n", current->memberInfo_name[count], current->avg[count]);
      count++;
    }

    /*Orgnaize gap line*/
    printf("\n");

    /*Next team*/
    current = current->next;
  }

}

/*Cricket Function*/
void Cricket() {

  /*Declare variable*/
  int num_teams, num_players;
  team_t* realTeams = malloc(sizeof(team_t));

  /*Print the question*/
  printf("Enter the number of teams you with to record: ");
  scanf("%d", &num_teams); //getting value

  /*Getting name of teams*/
  namingTeam(realTeams, num_teams);

  /*Print the question*/
  printf("Enter the TOTAL number of players for all teams: ");
  scanf("%d", &num_players);

  /*Getting member infomation*/
  memberInfo(realTeams, num_players);

  /*Print the teams*/
  printMember(realTeams);

}


/*----------------------------------------------------------------*/
/*LinkedList*/

/*Linked List structure type*/
/*Structure declaration*/
typedef struct node {
  int value;
  struct node* next;
} node_t;

/*Global variables for Linked List*/
int size = 0;
node_t* realList;

/*Prototype Functions*/
void modigyAny(node_t* list);
void deleteMiddle(node_t* list);
void insertMiddle(node_t* list);
void deleteBegin(node_t* list);
void deleteEnd(node_t* list);
void inserBegin(node_t* list);
void insertEnd(node_t* list);
void printLinkedList(node_t* list);
void printInitialStatement();
void printOption();
void LinkedList();

/*insertEnd Function*/
void insertEnd(node_t* list) {

  /*Declare variables*/
  int val;
  node_t* current = list;

  /*Print the question*/
  printf("Enter your node in the list\n");
  scanf("%d", &val); //getting the value

  /*if statment*/
  if(size == 0) {
    current->value = val; //insert the number
  }
  else {
    /*Change to current to node to ending node*/
    while(current->next != NULL) {
      current = current->next;
    }
    /*Creat new node*/
    current->next = malloc(sizeof(node_t));
    current = current->next; //change the current node to next node
    current->value = val; //insert the number
    current->next = NULL;
  }

  /*Increase the size*/
  size++;

  /*Print the list*/
  printLinkedList(list);

}

/*insertBegin Function*/
void inserBegin(node_t* list) {

  /*Declare variable*/
  int val;
  node_t* current = list;
  node_t* adding = malloc(sizeof(node_t));

  /*Print the question*/
  printf("Enter the value for the node you want to insert at the beginning\n");
  scanf("%d", &val); //getting the value

  /*if statment*/
  if(size == 0) {
    current->value = val; //insert the number
  }
  else {
    adding->value = val; //insert the value on adding node
    adding->next = list; //make the adding value to point the list
    realList = adding; //change the root
    list = realList;
  }

  /*Increase the size*/
  size++;

  /*Print the list*/
  printLinkedList(list);

}

/*deleteEnd Function*/
void deleteEnd(node_t* list) {

  /*Declare variables*/
  int sub_size = size;
  node_t* current = list;

  /*if Statement*/
  if(sub_size != 0) {

    /*while loop*/
    /*Find the second end of the list*/
    while(sub_size != 1) {
      current = current->next;
      sub_size--; //decrease the sub_size
    }

    /*Erase the last element*/
    current->next = NULL;
  }

  /*if Statement*/
  if(size != 0) //check the size
    size--; //decrease the size

  /*Print the list*/
  printLinkedList(list);

}

/*deleteBegin Function*/
void deleteBegin(node_t* list) {

  /*Decalre variables*/
  int sub_size = size;
  node_t* current = list;

  /*if Statement*/
  if(sub_size != 0)
    list = list->next; //delete the first element

  /*if Statement*/
  if(size != 0) //check the size
    size--; //decrease the size

  /*Print the list*/
  printLinkedList(list);

}

/*insertMiddle Function*/
void insertMiddle(node_t* list) {

  /*Declare variables*/
  int val, pre_val;
  node_t* current = list;
  node_t* current_next_temp = malloc(sizeof(node_t));
  node_t* adding = malloc(sizeof(node_t));

  /*Print the question*/
  printf("Enter the value of the node after which you want to insert a new node\n");
  scanf("%d", &pre_val); //getting value
  printf("Enter the value of new node\n");
  scanf("%d", &val); //getting value

  /*while loop*/
  /*Inifinte while loop for searching*/
  while(1) {

    /*if statment*/
    /*Checking the validation of the pre_value*/
    if(current == NULL) {
      printf("The previous value is not valid\n");
      break;
    }
    else{
      if(current->value == pre_val) { //match the pre_value

	/*Reseve the next node*/
	current_next_temp = current->next;

	/*Initialize the adding node*/
	adding->value = val;

	/*Insert the node*/
	current->next = adding;
	adding->next = current_next_temp;

	/*Inceasing the size*/
	size++;

	/*Breakt the while loop*/
	break;
      }
      else
	current = current->next; //continue searching
    }
  }

  /*Print the list*/
  printLinkedList(list);

}

/*insertMiddle Function*/
void deleteMiddle(node_t* list) {

  /*Declare variables*/
  int pre_val;
  node_t* current = list;

  /*Print the question*/
  printf("Enter the value of the node that precedes the node you want to delete\n");
  scanf("%d", &pre_val); //getting value

  /*while loop*/
  /*Inifinte while loop for searching*/
  while(1) {
    /*if statment*/
    /*Checking the validation of the pre_value*/
    if(current == NULL) {
      printf("The previous value is not valid\n");
      break;
    }
    else {
      if(current->value == pre_val) { //match the pre_value

	/*Check the valid to delete*/
	if(current->next != NULL) {
	  current->next = current->next->next; //delete the element
	  size--; //decrease the size
	}
	/*Break the while loop*/
	break;
      }
      else
        current = current->next; //continue searching
    }
  }

  /*Print the list*/
  printLinkedList(list);

}

/*modifyAny Function*/
void modifyAny(node_t* list) {

  /*Declare variables*/
  int val, modi_val;
  node_t* current = list;

  /*Print the question*/
  printf("Enter the value of the node you want to modify\n");
  scanf("%d", &val); //getting value
  printf("Enter the new value for this node:\n");
  scanf("%d", &modi_val); //getting value

  /*while loop*/
  /*Inifinite loop for searching*/
  while(1) {
    if(current == NULL) { //check the validation
      printf("Cannot find the value\n");
      break;
    }
    else {
      if(current->value == val) {
	current->value = modi_val;
	break;
      }
      else
	current = current->next;
    }
  }

  /*Print the list*/
  printLinkedList(list);
}

/*printLinkedList function*/
void printLinkedList(node_t* list) {

  /*Declare variables*/
  int sub_size = size;
  node_t* current = list;

  /*if statment*/
  /*Check the size of list*/
  if(sub_size == 0)
    printf("The list is empty"); //print 'empty' statment
  else {
    /*while loop*/
    /*print all elements in the list*/
    while(sub_size != 0) {
      printf("%d->", current->value); //print each element
      current = current->next; //change the current node to next linked node
      sub_size--;
    }
  }
  printf("\n\n"); //make extra line
}

/*printInitialStatement Function*/
void printInitialStatement() {

  /*Print the initial statment*/
  printf("This program initializes a linked list.\n");
  printf("It starts out empty, so the first thing you probably\n");
  printf("want to do is insert a node");
  printf("\n");
  printf("After that, enjoy trying the various functions.\n");
  printf("\n");
  printf("[Please note: This program is designed to accept integer values only.]\n");
  printf("\n");

}

/*printOption Function*/
void printOption() {

  /*Print the options*/
  printf("Please enter your choice\n");
  printf("1. INSERT a node at the END of linklist\n");
  printf("2. INSERT a node at the BEGINNING of linklist\n");
  printf("3. DELETE a node at the END of linklist\n");
  printf("4. DELETE a node from the BEGINNING of linklist\n"); 
  printf("5. INSERT a node in the MIDDLE of linklist\n");
  printf("6. DELETE a node from the MIDDLE of linklist\n");
  printf("7. MODIFY any node in linklist\n");
  printf("8. EXIT\n");

}

/*LinkedList Function*/
void LinkedList() {

  /*Decalre variable*/
  int opt = 0;

  /*Initialize the list*/
  realList = malloc(sizeof(node_t));
  realList->next = NULL;

  /*while loop*/
  /*infinite while loop for choose the options*/
  while(1) {
    printOption(); //Print the options
    scanf("%d", &opt); //Getting the value for option

    /*if statment*/
    /*Determine the option*/
    if(opt == 1)
      insertEnd(realList);
    else if(opt == 2)
      inserBegin(realList);
    else if(opt == 3)
      deleteEnd(realList);
    else if(opt == 4)
      deleteBegin(realList);
    else if(opt == 5)
      insertMiddle(realList);
    else if(opt == 6)
      deleteMiddle(realList);
    else if(opt == 7)
      modifyAny(realList);
    else if(opt == 8)
      break; //Break the while loop
    else
      printf("Invalid option, choose again\n");
  }

}


/*----------------------------------------------------------------*/
/*Main*/

/*Prototype Function*/
void mainMenu();

/*mainMenu Fuction*/
void mainMenu() {

  /*Print main menu*/
  printf("Main Menu\n");
  printf("1.  Cricket\n");
  printf("2.  Linked List\n");

}

/*main Function*/
int main() {

  /*Declare variables*/
  int option = 0;

  while((option != 1) && (option != 2)) {
    mainMenu();
    scanf("%d", &option);
    if(option == 1)
      Cricket();
    else if(option == 2)
      LinkedList();
    else
      printf("Please choose between 1 or 2\n\n");
  }

  /*Finishing the function*/
  return 0;
}
