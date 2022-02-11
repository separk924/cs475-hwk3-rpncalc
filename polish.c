/**
 * @file polish.c
 * @author Seung Park
 * polish.c contains the evaluate function that evaluates functions in RPN form
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "polish.h"
#include "stack.h"

char *c = " ";
double num;
double answer;

double evaluate(char *str){
    char *token = strtok(str,c); 
    char *ptr;
		while(token != NULL){ // separates ints and puncts while not null
            if(isdigit(*token)){
                num = strtod(token, &ptr);
                push(num);
            }else{  // if next token is an operator
                if(size()<2){
                    while(size() != 0){
                        pop();
                    }
                    printf("Error: insufficient operands.\n");
                }else{
                    double op2 = pop();
                    double op1 = pop();
                    switch(token[0]){
                        case '+' :
                            answer = op1 + op2;
                            break;
                        case '-' :
                            answer = op1 - op2;
                            break;
                        case '*' :
                            answer = op1 * op2;
                            break;
                        case '/' :
                            if(op2 == 0){
                                while(size() != 0){
                                    pop();
                                }
                                printf("Error: divide by zero\n");
                                break;
                            }else{
                                answer = op1 / op2;
                                break;
                            }
                        default:
                            while(size() != 0){
                                pop();
                            }
                            printf("Error: operator: %c is not recognized\n", *token);
                    }
                    push(answer);
                }
            }
            token = strtok(NULL,c);
        }
        if(size()>1){ // if there are too many operands
            while(size() != 0){
                pop();
            }
            printf("Error: too many operands entered.\n");
        }else{
            double ans = pop();
            printf(" %f \n", ans);
            return ans;
        }
}