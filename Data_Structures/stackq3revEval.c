#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

struct Stack{
	int top;
	int arr[10];
};

bool isFull(struct Stack *s){
	if(s->top==9){
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

void push(int element,struct Stack* s){
	if(isFull(s)){
		printf("Stack overflow\n");
	}
	else{
		s->top++;
		s->arr[s->top]=element;
	}
}

int pop(struct Stack *s){
	if(isEmpty(s)){
		printf("Stack underflow\n");
		return 0;
	}
	else{
		int popped = s->arr[s->top];
		s->top--;
		return popped;
	}
}

int peek(struct Stack *s){
	return s->arr[s->top];
}

int evaluate(char oper, int num1,int num2){
	int result;
	switch(oper){
		case '+':
			result = num1+num2;
			break;
		case '-':
			result = num1-num2;
			break;
		case '*':
			result = num1*num2;
			break;
		case '/':
			result = num1/num2;
			break;
		default:
			printf("operation invalid\n");
			result = 1;
	}
	return result;
}

int main(){
	char expression[50]="57+62-*";
	struct Stack s1;
	struct Stack* s;
	s=&s1;
	s->top=-1;
	int i,num1,num2,number;
	for(i=0;i<strlen(expression);i++){
		if(isdigit(expression[i])){
			number = expression[i]-'0';
			push(number,s);
		}
		else{
			num1 = pop(s);
			num2 = pop(s);
			int result = evaluate(expression[i], num2,num1);
			push(result, s);
		}
	}
	printf("result: %d",pop(s));
	return 0;
}