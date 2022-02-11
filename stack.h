/*
 * stack.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dchiu
 */

#ifndef STACK_H_
#define STACK_H_

// TODO: declaration of stack struct and its functions go here
typedef struct Node {
    double data;
    struct Node *next;
}Node;
int size();
void push(double num);
double pop();

#endif /* STACK_H_ */
