#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

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

void push(int element, struct Stack *s){
	if(isFull(s)){
		printf("Stack overflow.\n");
	}
	else{
		s->top++;
		s->arr[s->top]=element;
	}
}

int pop(struct Stack* s){
	if(isEmpty(s)){
		printf("Stack underflow.\n");
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

int calculate(char opr, int num1, int num2){
	int result;
	switch(opr){
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
			result=0;
			break;
	}
	return result;
}

int main(){
	
	char polish_expression[50]="+*+36-247";
	struct Stack s1;
	struct Stack* s;
	s=&s1;
	int number;
	int num1,num2,res;
	//printf("%d", strlen(polish_expression));
	for(int i=strlen(polish_expression)-1;i>=0;i--){
		if(isdigit(polish_expression[i])){
			number = polish_expression[i]-'0';
			printf("%d", number);
			push(number,s);
		}
		else{
			num1 = pop(s);
			num2 = pop(s);
			res=calculate(polish_expression[i],num1,num2);
			push(res,s);
		}
	}
	
	printf("Evaluated value: %d",pop(s));
	return 0;
	
}



