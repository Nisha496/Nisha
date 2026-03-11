#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;


void delete_begin()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_end()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
    }
}

void delete_position(int pos)
{
    struct node *temp, *nextnode;
    int i;

    temp = head;

    for(i = 1; i < pos-1; i++)
    {
        temp = temp->next;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}

// Display list
void display()
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // Creating list
    struct node *n1 = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));
    struct node *n3 = malloc(sizeof(struct node));

    n1->data = 10;
    n1->next = n2;

    n2->data = 20;
    n2->next = n3;

    n3->data = 30;
    n3->next = NULL;

    head = n1;

    display();

    delete_begin();
    display();

    delete_end();
    display();

    return 0;
}