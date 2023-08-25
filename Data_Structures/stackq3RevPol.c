#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

struct Stack{
	int top;
	char arr[10];
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

void push(char oper, struct Stack *s){
	if(isFull(s)){
		printf("Stack overflow\n");
	}
	else{
		s->top++;
		s->arr[s->top]=oper;
		//printf("%d push completed\n",s->top);
	}
}

char pop(struct Stack *s){
	if(isEmpty(s)){
		printf("Stack underflow\n");
		return ' ';
	}
	else{
		char popped;
		popped = s->arr[s->top];
		s->top--;
		return popped;
	}
}

char peek(struct Stack *s){
	char top_element = s->arr[s->top];
	return top_element;
}

int priority(char op){
	int priority;
	switch(op){
		case '+':
		case '-':
			priority=1;
			break;
		case '*':
		case '/':
			priority=2;
			break;
		default:
			priority = 0;
			break;
	}
	return priority;
}

void main(){
	struct Stack s1;
	struct Stack *s;
	s=&s1;
	s->top=-1;
	char expression[50]="b-c*a+(d*e-f)/g";
	for(int i=0;i<strlen(expression);i++){
		if(isalpha(expression[i])){
			printf("%c", expression[i]);
		}
		else{
			if(isEmpty(s)){
				push(expression[i],s);
			}
			else if(expression[i]==')'){
				while(peek(s)!='('){
					printf("%c",pop(s));
				}
				pop(s);
			}
			else if(expression[i]=='('){
				push(expression[i],s);
			}
			
			else{
				if(priority(expression[i])<=priority(peek(s))){
					printf("%c",pop(s));
					while(priority(peek(s))>=priority(expression[i])){
						printf("%c", pop(s));
					}
					push(expression[i],s);
				}
				else{
					push(expression[i],s);
				}
			}
		}		
	}
	//printf("\n%d",s->top);
	while(!isEmpty(s)){
		printf("%c", pop(s));
	}

}
	