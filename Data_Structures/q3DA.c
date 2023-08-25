#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int truck_id,time,nos;
	struct node*next;
};
struct node*head=NULL;
void push(int a, int b, int c)
{
	if(c<=3 && head==NULL)
	{
		struct node*newnode=(struct node*)malloc(sizeof(struct node));
		head=newnode;
		newnode->truck_id=a;
		newnode->time=b;
		newnode->nos=c;
		newnode->next=NULL;
		}
	else if(c<=3)
	{
		struct node*newnode = (struct node*)malloc(sizeof(struct node));
		newnode->truck_id=a;
		newnode->time=b;
		newnode->nos=c;
		if(b<(head->time))
		{
			newnode->next=NULL;
			struct node*temp;
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
				}
				temp->next=newnode;	
		}
		else if(b>(head->time))
		{
			newnode->next=head;
			head=newnode;
		}
	}
	else
		printf("The number of servicing is more than 3 times therefore the charge is Rs.5000\n");	
}

int pop()
{
	if(head==NULL)
	{
		printf("Garage Empty\n");
		return 0;
	}
	else
	{
	struct node*temp;
	temp=head;
	head=head->next;
	return(temp->truck_id);	
}
}

void display()
{
	struct node*temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d  ",temp->truck_id);
		temp=temp->next;
	}
}
int main()
{
	int choice,tid,time,number,x;
	do
	{
	printf("\n1. Move truck in garage.\n2.Remove truck from garage\n3.Display\n4.Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nEnter truck ID: ");
			scanf("%d",&tid);
			printf("\nEnter the time: ");
			scanf("%d",&time);
			printf("\nEnter the number of times of service: ");
			scanf("%d",&number);
			push(tid,time,number);
			break;
		case 2:
			x=pop();
			printf("\nRemoved truck is: %d",x);
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);		
	}
}while(choice>=1 && choice<=4);
getch();
}