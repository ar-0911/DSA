#include<stdio.h>
#include<stdbool.h>

struct Stack{
	int top;
	int arr[20];
};

bool isFull(struct Stack *s){
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

void push(int element, struct Stack* s){
	if(isFull(s)){
		printf("Stack overflow.\n");
	}
	else{
		s->top++;
		s->arr[s->top]=element;
	}
}

int pop(struct Stack *s){
	if(isEmpty(s)){
		printf("Stack underflow.\n");
	}
	else{
		int popped;
		popped = s->arr[s->top];
		s->top--;
		return popped;
	}
}

void display(struct Stack* s){
	for(int i=s->top;i>=0;i--){
		printf("%d\n",s->arr[i]);
	}
}

int peek(struct Stack *s){
	return s->arr[s->top];
}

void display_firstX(int num,struct Stack *s, struct Stack *t){
	for(int i=s->top;i>=num;i--){
		push(pop(s),t);
	}
	for(int i=0;i<=s->top;i++){
		printf("\n%d student to submit their register is %d\n",i+1,s->arr[i]);
	}
	while(!isEmpty(t)){
		push(pop(t),s);
	}
}

bool check_regno(int register_number, struct Stack* s){
	bool present = false;
	for(int i=0;i<s->top;i++){
		if(s->arr[i]==register_number){
			present = true;
			break;
		}
	}
	return present;

}

void submitted_before(int regno_1, int regno_2, struct Stack* s){
	int index1,index2;
	if(check_regno(regno_1,s) && check_regno(regno_2,s)){
		for(int i =0;i<=s->top;i++){
			if(s->arr[i]==regno_1){
				index1=i;
			}
			else if(s->arr[i]== regno_2){
				index2=i;
			}
			else{
				continue;
			}
		}
		if(index2>index1){
			printf("\n%d register number submitted before %d\n",regno_1, regno_2);
		}
		else{
			printf("\n%d register number submitted before %d\n",regno_2, regno_1);
		}
	}
	else{
		printf("\nRegister number not found.\n");
	}
}

int main(){
	struct Stack s1;
	struct Stack *s;
	struct Stack temp;
	struct Stack *t;
	int regno;
	t=&temp;
	s=&s1;
	t->top=-1;
	s->top=-1;
	for(int i = 0;i<20;i++){
		printf("Enter %d students register number: ",i+1);
		scanf("%d",&regno);
		push(regno,s);
	}
	printf("\nlast submitted record by: %d\n",peek(s));
	display_firstX(10,s,t);
	if(check_regno(12,s)){
		printf("\nRegister number found.\n");
	}
	else{
		printf("\nNot found.\n");
	}
	submitted_before(3,2,s);
	submitted_before(37,5,s);
}