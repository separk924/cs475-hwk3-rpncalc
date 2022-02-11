/**
 * @file stack.c
 * @author Seung Park
 * @brief stack.c holds all the functions to create a stack element
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

Node *head = NULL;
int count = 0;

/**
 * This function returns the amount of elements on the stack
*/
int size(){
    return count;
}

/**
 * This function pushes a new node onto the stack
 * 
 * @param num the double to be pushed onto the stack
 */
void push(double num){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = head;
    newNode->data = num;
    head = newNode;
    count++;
}

/**
 * This function pops off the first element on the stack
 * 
 * @return double The data of the element that was popped off
 */
double pop(){
    Node *temp = head;
    head = head->next;
    count--;
    return temp->data;
}