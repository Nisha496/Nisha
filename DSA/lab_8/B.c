#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};

struct node *head=NULL;

void delete_begin(){
    struct node *temp=head,*last;

    if(head==NULL) return;

    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }

    last=head->prev;
    head=head->next;
    head->prev=last;
    last->next=head;

    free(temp);
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
    struct node *temp=head;
    int i;

    for(i=1;i<pos;i++)
        temp=temp->next;

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    if(temp==head)
        head=temp->next;

    free(temp);
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