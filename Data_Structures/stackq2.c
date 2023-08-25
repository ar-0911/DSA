#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

struct Stack{
	int top;
	char arr[10][50];
};

bool isFull(struct Stack* s){
	if(s->top==9){
		return true;
	}
	else{
		return false;
	}
}

bool isEmpty(struct Stack* s){
	if(s->top==-1){
		return true;
	}
	else{
		return false;
	}
}

void push(char* webpage, struct Stack *s){
	if(isFull(s)){
		printf("Stack is Full\n");
	}
	else{
		//const char* wp = webpage;
		s->top++;
		strcpy(s->arr[s->top], webpage);
		//printf("push is completed\n");
	}
}

const char* pop(struct Stack *s){
	if(isEmpty(s)){
		printf("Stack is empty.Operation cannot be done!\n");
		return "\0";
	}
	else{
		char* popped;
		//char* popp;
		//popp=popped;
		//strcpy(popped, s->arr[s->top]);
		popped=s->arr[s->top];
		s->top--;
		//printf("%s",popped);
		return popped;
	}
}

const char* peek(struct Stack *s){
	char* top_element = s->arr[s->top];
	return top_element;
}

void display(struct Stack *s){
	for(int i=s->top;i>=0;i--){
		printf("%s\n", s->arr[i]);
	}
}

int main(){
	struct Stack backward;
	struct Stack* b;
	struct Stack forward;
	struct Stack* f;
	int operation;
	f=&forward;
	b=&backward;
	b->top=-1;
	f->top=-1;
	char current_webpage[50];
	char webpage[50];
	strcpy(webpage, "google");
	push(webpage,b);
	strcpy(webpage, "youtube");
	push(webpage,b);
	strcpy(webpage, "Linkedin");
	push(webpage,b);
	strcpy(webpage, "amazon");
	push(webpage,f);
	strcpy(webpage, "flipkart");
	push(webpage,f);
	strcpy(webpage, "Myntra");
	push(webpage,f);
	printf("The current webpage you are on is instagram.\n\n");
	strcpy(webpage,"instagram");
	printf("Backward Stack\n");
	display(b);
	printf("\n\nForward Stack\n");
	display(f);
	while(true){
		printf("\nOperations:\nPress 1 to go back\nPress 2 to go front\nPress 3 to exit.\n");
		scanf("%d", &operation);
		switch(operation){
			case 1:
				push(webpage, f);
				if(!isEmpty(b)){
					strcpy(webpage,pop(b));
					printf("You are now on %s\n", webpage);
				}
				else{
					printf("No webpage in the back!\n");
				}
				
				break;
				
			case 2:
				push(webpage, b);
				if(!isEmpty(f)){
					strcpy(webpage,pop(f));
					printf("You are now on %s\n", webpage);	
				}
				else{
					printf("No webpage in the front!\n");
				}				
				break;
			
			case 3:
				exit(0);
			
			default:
				printf("Invalid operation!\n");
				break;
		}
	}	
	return 0;
}


