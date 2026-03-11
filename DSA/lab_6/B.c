#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};

struct node *head=NULL;

void insert_begin(int x){
    struct node *n=malloc(sizeof(struct node));
    n->data=x;
    n->prev=NULL;
    n->next=head;
    if(head) head->prev=n;
    head=n;
}

void insert_end(int x){
    struct node *n=malloc(sizeof(struct node)),*t=head;
    n->data=x;
    n->next=NULL;

    if(head==NULL){
        n->prev=NULL;
        head=n;
        return;
    }

    while(t->next) t=t->next;
    t->next=n;
    n->prev=t;
}

void insert_pos(int x,int pos){
    struct node *n=malloc(sizeof(struct node)),*t=head;
    int i;

    for(i=1;i<pos-1;i++)
        t=t->next;

    n->data=x;
    n->next=t->next;
    n->prev=t;

    if(t->next) t->next->prev=n;
    t->next=n;
}

void display(){
    struct node *t=head;
    while(t){
        printf("%d <-> ",t->data);
        t=t->next;
    }
    printf("NULL\n");
}

int main(){
    insert_begin(10);
    insert_end(30);
    insert_pos(20,2);
    display();
}