#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

struct Stack{
	int top;
	char arr[10];
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

void push(char symbol, struct Stack *s){
	if(isFull(s)){
		printf("Stack overflow.\n");
	}
	else{
		s->top++;
		s->arr[s->top]=symbol;
	}
}

char pop(struct Stack *s){
	if(isEmpty(s)){
		printf("Stack underflow.\n");
		return ' ';
	}
	else{
		char popped = s->arr[s->top];
		s->top--;
		return popped;
	}
}

char peek(struct Stack *s){
	return s->arr[s->top];
}

int main(){
	char expression[150];
	struct Stack s1;
	struct Stack *s;
	s=&s1;
	s->top=-1;
	bool balanced=true;
	scanf("%[^\t]s", expression);
	//printf("Enter expression: ");
	//scanf("%s", expression);

	for(int i=0;i<strlen(expression);i++){
		if(expression[i]=='(' || expression[i]=='{' || expression[i]=='['){
			push(expression[i],s);
		}
		
		else if(expression[i]==')'){
			if(peek(s)=='('){
				pop(s);
			}
			
			else{
				balanced=false;
				break;
			}
		}
		
		else if(expression[i]=='}'){
			if(peek(s)=='{'){
				pop(s);
			}
			
			else{
				balanced=false;
				break;
			}
		}
		
		else if(expression[i]==']'){
			if(peek(s)=='['){
				pop(s);
			}
			
			else{
				balanced=false;
				break;
			}
		}
		
		else{
			continue;
		}
	}
		
	
	if(!isEmpty(s)){
		balanced=false;
	}
	if(balanced){
		printf("The expression has balanced amount of brackets.\n");
	}
	else{
		printf("The expression does not have balanced amount of brackets.\n");
	}
	
	return 0;
}