#include <stdio.h>
#include <stdlib.h>
//this program is like ../array_queue/queue.c but implemented with a linked list instead of an array

//global variables
static struct node *queue,*tail;
static int len=0; //solely for the function that returns length, just information

//the node struct
struct node{
    int data;
    struct node *parent;
    struct node *next;
};

//prototypes
void init_queue();
struct node *add(int);
struct node pop();
void init_queue_self(struct node *);
int ret_len();

//allocates memory for one struct, the head
void init_queue(){
    queue=(struct node*)malloc(sizeof(struct node));
    (*queue).next=NULL;
}

//uses a linked list provided by user for queue
void init_queue_self(struct node *self_queue){
    queue=self_queue;
    (*queue).next=NULL;
}

//for inserting values
struct node *add(int value){
    struct node *selected=queue;
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
        free(queue);
        init_queue();
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

//returns length of queue.
int ret_len(){
    return len;
}