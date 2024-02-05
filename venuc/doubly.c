#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *pre;
};

struct node *head=NULL;
struct node *createll();
struct node *insert_b();
struct node *delate();
struct node *display();

struct node *createll()
{
    struct node *newnode,*temp;
    temp=head;
    newnode=(struct node*) malloc(sizeof(struct node));
    printf("enter data:- ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->pre=NULL;

    if(head==NULL)
    {
        temp=head=newnode;

    }

    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->pre=temp;
    }
}


struct node *display()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("empty");
    }

    else
    {
        while(temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->next;
        }
    }
}

struct node *insert_b()
{
    struct node *temp,*newnode;
    temp=head;
    newnode=(struct node*) malloc(sizeof(struct node));
    printf("enter data:- ");
    scanf("%d",&newnode->data);
    int idata;
    printf("enter i data:- ");
    scanf("%d",&idata);

    while(temp->data!=idata)
    {
        temp=temp->next;
    }


    newnode->next=temp;
    newnode->pre=temp->pre;
    temp->pre->next=newnode;
    temp->pre=newnode;
}


struct node *delate()
{
    struct node *temp;
    temp=head;

    int idata;
    printf("enter i data:- ");
    scanf("%d",&idata);

    while(temp->data!=idata)
    {
        temp=temp->next;
    }
    temp->pre->next=temp->next;
    temp->next->pre=temp->pre;
    free(temp);
};



int main()
{
    int option;
    while(1)
    {
        printf("1.create ll\n 2.display\n 3.insert\n4.delete\n 5.exit");
        printf("\n enter option:- ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:createll(head);
                break;
            case 2: display(head);
                break;

            case 3:insert_b(head);
                break;

            case 4:delate(head);
                break;
            case 5:exit(0);

            default:printf("wrong option");
            break;
        }
    }
}
