#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};

struct node *head=NULL;

void insert_begin(int x){
    struct node *n=malloc(sizeof(struct node)), *last;

    n->data=x;

    if(head==NULL){
        n->next=n;
        n->prev=n;
        head=n;
        return;
    }

    last=head->prev;

    n->next=head;
    n->prev=last;
    last->next=n;
    head->prev=n;
    head=n;
}

void insert_end(int x){
    struct node *n=malloc(sizeof(struct node)), *last;

    n->data=x;

    if(head==NULL){
        n->next=n;
        n->prev=n;
        head=n;
        return;
    }

    last=head->prev;

    last->next=n;
    n->prev=last;
    n->next=head;
    head->prev=n;
}

void insert_pos(int x,int pos){
    struct node *n=malloc(sizeof(struct node)), *t=head;
    int i;

    for(i=1;i<pos-1;i++)
        t=t->next;

    n->data=x;
    n->next=t->next;
    n->prev=t;

    t->next->prev=n;
    t->next=n;
}

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