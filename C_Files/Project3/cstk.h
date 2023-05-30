//
//  cstk.h
//  
//
//  Created by Trey Tuscai on 2/28/22.
//

#ifndef cstk_h
#define cstk_h

#include <stdio.h>
#include <stdlib.h>

//defines the stack structure
typedef struct stack
{
    int size;
    int* values;
    int top;
}   Stack;

//global variable for max stack size
extern int CSTK_MAX;

//creates a new stack
Stack *stk_create(int cap);

//destroys stack and frees up memory
void stk_destroy (Stack *stack);

//returns the size of the stack
int size(Stack *stack);

//returns true if empty
int isEmpty(Stack *stack);

//returns true if full
int isFull(Stack *stack);

//returns the top value on the stack
int peek(Stack *stack);

//pushes a new value onto the stack
void stk_push(Stack* stack, int val);

//pops the top value off the stack and decrements stack size by one
int stk_pop(Stack *stack);

//displays the original and reversed lists
void stk_display(Stack *stack, int val);

#endif /* cstk_h */
