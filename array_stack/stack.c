#include <stdio.h>
#include <stdlib.h>
#define stack_overflow 0
#define SUCCESS 1
#define stack_empty 0
//This is a simple Last-In-First-Out data structure, with simple functions like adding and popping.

//This program will contain 5 functions, for initialization(to receive maximum length for array.), adding,returning length, and popping.

//global variables
static int top,*stack,maxlen;
//prototypes
void init_stack(int);
void init_stack_ptr(int,int*);
int add(int); 
int get_top();
int pop();
//a function to take maximum possible length of stack, then to malloc.
void init_stack(int len){
    stack=(int*)malloc(sizeof(int)*len);
    maxlen=len;
    top=-1;
}

//a function which allows the user to use their own stack
void init_stack_ptr(int len, int *queue_ptr){
    stack=queue_ptr;
    maxlen=len;
    top=-1;
}

//function to insert values
int add(int value){
    //if maximum length if reached, then 0 will be returned(or stack_overflow, a macro for 0)
    if(top+1>=maxlen){
        return stack_overflow;
    }
    stack[top+1]=value; //value at top=value;
    top++; //incrementing top so that if first value was stack[0], next will be queue[1]
    return SUCCESS; //returns SUCCESS or 1(meaning everything is ok)
}

//function to pop values from the top(haha it rhymes)
int pop(){
    if(top==-1){
        return stack_empty; //returns 0 if stack is empty
    }
    top--; //decrementing top
    return stack[top+1]; // a big difference you might've noticed is that we aren't returning success/failure messages here, we're returning the value that was removed.
}

//a function to return the current length of the stack
int get_top(){
    return top;
}