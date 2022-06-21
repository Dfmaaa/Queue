#include <stdio.h>
#include <stdlib.h>
//this program is like ../array_stack/queue.c but implemented with a linked list instead of an array

//global variables
static struct node *stack,*tail;
static int len=0; //solely for the function that returns length, just information

//the node struct
struct node{
    int data;
    struct node *parent;
    struct node *next;
};

//prototypes
void init_stack();
struct node *add(int);
struct node pop();
void init_stack_self(struct node *);
int ret_len();

//allocates memory for one struct, the head
void init_stack(){
    stack=(struct node*)malloc(sizeof(struct node));
    (*stack).next=NULL;
}

//uses a linked list provided by user for stack
void init_stack_self(struct node *self_queue){
    stack=self_queue;
    (*stack).next=NULL;
}

//for inserting values
struct node *add(int value){
    struct node *selected=stack;
    while((*selected).next!=NULL){
        selected=(*selected).next;
    }
    (*selected).data=value;
    (*selected).next=(struct node*)malloc(sizeof(struct node));
    (*(*selected).next).next=NULL;
    (*(*selected).next).parent=selected;
    tail=selected;
    len++;
    return selected;
}

//for popping
struct node pop(){
    struct node retNode=*tail;
    if(len==1){
        free(stack);
        init_stack();
        len--;
        return retNode;
    }
    tail=(*tail).parent;
    free((*tail).next);
    (*tail).next=(struct node*)malloc(sizeof(struct node));
    (*(*tail).next).next=NULL;
    len--;
    return retNode;
}

//returns length of stack.
int ret_len(){
    return len;
}