#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};

struct node *head=NULL;

void delete_begin(){
    struct node *t=head,*last;

    if(head==NULL) return;

    last=head->prev;

    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }

    head=head->next;
    head->prev=last;
    last->next=head;

    free(t);
}

void delete_end(){
    struct node *last;

    if(head==NULL) return;

    last=head->prev;

    if(last==head){
        free(head);
        head=NULL;
        return;
    }

    last->prev->next=head;
    head->prev=last->prev;

    free(last);
}

void delete_pos(int pos){
    struct node *t=head;
    int i;

    for(i=1;i<pos;i++)
        t=t->next;

    t->prev->next=t->next;
    t->next->prev=t->prev;

    if(t==head)
        head=t->next;

    free(t);
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
    display();
}