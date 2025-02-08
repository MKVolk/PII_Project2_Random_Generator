/*
* Program Name: "COP 2220 Project 2: The menace of Ludopathy"
*
* Description: A program that outputs a (especified by the user) number of sets of 6 random unique numbers 
*
* Author: Markos Calderon (N01600902)
*
* Date: October 11, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int PromptUser (void); //Prompts the user for the number of sets
void RandomSet (int setSize);//Prints a set given the number of elements to be in that set
int RangedRandom (int range, int offset);//Returns a Random number given a range and an offset
void SetIterator (int nSets, int setSize);//Prints the set title and calls the RandomSet function
void ByeBye(void); //Just colors and outputs the final message

int main (void){

  srand(time(NULL));
  int setSize = 6; //in case changing the set size of the set is useful
  int nSets = 0;

  do{
    nSets = PromptUser();
    SetIterator(nSets,setSize);
    printf("\n");
  }while(nSets != -1);

  ByeBye();

  return 0;
}

/*
* Function Name: PromptUser
*
* Input Parameters: Void type nothing
*
* Description: Prompts the user for the number of sets.
*
* Return Value: Integer Type Number
*/
int PromptUser (void){
  int userNum = 0;
  printf("\033[0;36m");
  printf("____________________________________________________\n");
  printf("Type the number of sets to generate or a -1 to quit:\nYour input: ");
  scanf(" %d", &userNum);
  printf("\n");
  printf("\033[0m");

  return userNum;
}

/*
* Function Name: RandomSet
*
* Input Parameters: 
*       setSize: Integer Type Number
*
* Description: Prints a series of 6 random numbers.
*
* Return Value: Void Type Nothing
*/
void RandomSet (int setSize){
  int number[setSize];
  int isRepeated = 0;
  for (int i = 0; i < setSize; i++){
    do{
      isRepeated = 0;
      number[i] = RangedRandom(53,1);
      for (int j = 0;j < i; j++){ //fix me pwease | Done, it was the variable increaser XD
        if(number[i] == number[j]){
          isRepeated = 1;
        }
      }
    }while(isRepeated);
  }

  for (int k = 0; k < setSize;k++){
    printf("\033[0;%dm", ((k%6)+31));
    printf("%3d ", number[k]);
    printf("\033[0m");
  }
   printf("\n");

  return;
}

/*
* Function Name: RangedRandom
*
* Input Parameters: 
*       range:  Integer Type Number
*       offset: Integer Type Number
*
* Description: Returns a random number given a range and an offset
*
* Return Value: Integer Type Number
*/
int RangedRandom (int range, int offset){
  
  return ((rand())% range) + offset ;
}

/*
* Function Name: SetIterator
*
* Input Parameters: 
*       nSets:    Integer Type Number
*       setSize:  Intteger Type Number
*
* Description: Prints all the requested sets
*
* Return Value: Void Type Nothing
*/
void SetIterator (int nSets, int setSize){
  for (int i = 0;i < nSets; i++){
    printf("Set with %2d elements number %3d: ", setSize, i+1);
    RandomSet(setSize);
  }
  return;
}

/*
* Function Name: ByeBye
*
* Input Parameters: Void Type Nothing
*
* Description: Prints the Message at The ENd of The Program
*
* Return Value: Void Type Nothing
*/
void ByeBye (void){
  printf("You decided to ");
  printf("\033[0;31m");
  printf("quit");
  printf("\033[0;35m");
  printf("\nBye bye ^^\n\n");
  printf("\033[0m");
  return;
}

//That's it