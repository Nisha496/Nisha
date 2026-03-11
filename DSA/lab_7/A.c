#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};

struct node *head=NULL;

// Insert at beginning
void insert_begin(int x){
    struct node *n=malloc(sizeof(struct node)),*t=head;
    n->data=x;

    if(head==NULL){
        n->next=n;
        n->prev=n;
        head=n;
        return;
    }

    while(t->next!=head)
        t=t->next;

    n->next=head;
    n->prev=t;
    t->next=n;
    head->prev=n;
    head=n;
}

// Insert at end
void insert_end(int x){
    struct node *n=malloc(sizeof(struct node)),*t=head;
    n->data=x;

    if(head==NULL){
        n->next=n;
        n->prev=n;
        head=n;
        return;
    }

    while(t->next!=head)
        t=t->next;

    t->next=n;
    n->prev=t;
    n->next=head;
    head->prev=n;
}

// Insert at position
void insert_pos(int x,int pos){
    struct node *n=malloc(sizeof(struct node)),*t=head;
    int i;

    for(i=1;i<pos-1;i++)
        t=t->next;

    n->data=x;
    n->next=t->next;
    n->prev=t;

    t->next->prev=n;
    t->next=n;
}

// Display
void display(){
    struct node *t=head;

    if(head==NULL) return;

    do{
        printf("%d <-> ",t->data);
        t=t->next;
    }while(t!=head);

    printf("(back to head)\n");
}

int main(){
    insert_begin(10);
    insert_end(30);
    insert_pos(20,2);

    display();
}