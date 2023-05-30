//
//  cstk.c
//  
//
//  Created by Trey Tuscai on 2/28/22.
//

#include "cstk.h"

//global max size is 50
int CSTK_MAX = 50;

//creates pointer to new stack and values while establishing size and top
Stack *stk_create(int cap)
{
    Stack *newStack= (Stack*)malloc(sizeof(Stack));
    newStack->size = cap;
    newStack->top = -1;
    newStack->values = (int*)malloc(sizeof(int)*cap);
    
    return newStack;
}

//frees the memory from the stack and its values
void stk_destroy (Stack *stack)
{
    free(stack);
    free(stack->values);
}

//returns the size of the stack
int size(Stack *stack)
{
    return stack->top +1;
}

//returns true if stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

//returns true if stack is full
int isFull(Stack *stack)
{
    return stack->top == stack->size-1;
}

//returns the top value on the stack if it is not empty
int peek(Stack *stack)
{
    if(!isEmpty(stack))
    {
        return stack->values[stack->top];
    }
    else
    {
        printf("Stack is empty. Cannot peek.");
        exit(EXIT_FAILURE);
    }
}

//pushes a new value onto the stack if there is available space
void stk_push(Stack* stack, int val)
{
    if(isFull(stack))
    {
        printf("Stack is full");
        exit(EXIT_FAILURE);
    }
    
    //printf("Adding %d\n", val);
        stack->values[++stack->top] = val;
}

//pops value off the stack and decrements stack size by one if not empty
int stk_pop(Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty. Cannot pop.");
        exit(EXIT_FAILURE);
    }
    
    //printf("Popping %d\n", peek(stack));
        return stack->values[stack->top--];
}

//returns the original list in the form of a stack
Stack *stk_original(Stack *stack)
{
    Stack *original = stk_create(stack->size);
    Stack *temp = stk_create(stack->size);
    //while stack is not empty
    //stack pops its values ande pushes them onto both original and temp
    while(!isEmpty(stack))
    {
        int topVal = peek(stack);
        stk_push(original, topVal);
        stk_push(temp, topVal);
        stk_pop(stack);
        //original should be in original order now
    }
    while(!isEmpty(temp))
    {
        //temp pops off its values and pushes them onto stack
        int topVal = peek(temp);
        stk_push(stack, topVal);
        stk_pop(temp);
    }
    //stack should be in reverse order now
    return original;
}

//displays the original and reverse of the lists
void stk_display(Stack *stack, int val)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty. Cannot display");
        exit(EXIT_FAILURE);
    }
    //creates the original list as a stack
    Stack *ogList = stk_original(stack);
    if(val == 1)
    {
        while(!isEmpty(stack))
        {
            //prints values from original in orginal order
            printf("%d ", stk_pop(stack));
        }
        printf("\n");
    }
    else if (val == 0)
    {
        while(!isEmpty(ogList))
        {
            //prints values from stack in reverse order
            printf("%d ", stk_pop(ogList));
        }
        printf("\n");
    }
    else
        printf("Out of range: Type 1 for reversed list or 0 for original list.");
}


/*int main()
{
    // create a stack of capacity 5
    Stack *stack = stk_create(5);
 
    stk_push(stack, 1);
    stk_push(stack, 2);
    stk_push(stack, 3);
 
    stk_display(stack, 1);
 
 return 0;
}*/

