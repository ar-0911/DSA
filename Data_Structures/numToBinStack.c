#include<stdio.h>
#include<stdbool.h>

struct Stack{
	int data[20];
	int top;
};

bool isFull(struct Stack* s){
	if(s->top==19){
		return true;
	}
	else{
		return false;
	}
}

bool isEmpty(struct Stack *s){
	if(s->top==-1){
		return true;
	}
	else{
		return false;
	}
}

void push(struct Stack* s, int bin){
	if(isFull(s)){
		printf("Stack overflow.\n");
	}
	else{
		s->top++;
		s->data[s->top]=bin;
	}
}

int pop(struct Stack *s){
	if(isEmpty(s)){
		printf("Stack underflow.\n");
	}
	else{
		int popped = s->data[s->top];
		s->top--;
		return popped;
	}
}

int peek(struct Stack *s){
	return s->data[s->top];
}

int main(){
	struct Stack s1;
	struct Stack* s;
	int output=0;
	int num;
	int val;
	s = &s1;
	s->top=-1;
	printf("Enter number to convert to binary: ");
	scanf("%d",&num);
	int temp = num;
	while(num>-1){
		if(num==0){
			push(s,0);
			break;
		}
		else if(num==1){
			push(s,1);
			break;
		}
		else{
			push(s,num%2);
			num /=2;
		}
	}
	
	while(!isEmpty(s)){
		output = (output*10)+pop(s);
	}
	
	printf("the binary value of %d is %d",temp,output);
}