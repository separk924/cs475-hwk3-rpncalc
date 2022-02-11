/*
 ============================================================================
 Name        : PolishSol.c
 Author      : Seung Park
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"
#include "polish.h"

#define MAX_EQ_LEN 100 /* maximum RPN expression input length */

int main()
{
	char eqn[MAX_EQ_LEN];	 // string to store the input RPN expression
	char resp[MAX_EQ_LEN]; // string to store the user's response "y" or "n"
	int punc; // int to store if punctuation
	char *c = " ";
	double num;
    char *ptr;

	while(resp[0] != 'n'){ //continues until user responds with 'n'
		printf("Enter an equation (in RPN): \n");
		fgets(eqn, MAX_EQ_LEN, stdin); 
		evaluate(eqn);
		printf("Evaluate another? (y/n): ");
		fgets(resp, MAX_EQ_LEN, stdin);
	}

	printf("Exiting...\n");
	return 0;
}
