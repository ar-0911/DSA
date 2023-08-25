#include<iostream>

using namespace std;

class Stack{
	int top;
	char arr[10];
	
	public:
		Stack(){
			top=-1;
			for(int i=0;i<10;i++){
				arr[i]=' ';
			}
		}
		
		bool isFull(){
			if(top==9){
				return true;
			}
			else{
				return false;
			}
		}
		
		bool isEmpty(){
			if(top==-1){
				return true;
			}
			else{
				return false;
			}
		}
		
		void push(char element){
			if(isFull()){
				cout<<"Stack overflow"<<endl;
			}
			else{
				top++;
				arr[top]=element;
			}
			
		}
		
		char pop(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			else{
				int popped = arr[top];
				top--;
				return popped;	
			}	
		}
		
		void display(){
			for(int i=0;i<10;i++){
				cout<<arr[i]<<endl;
			}
		}
		
		char peek(){
			if(!isEmpty()){
				return arr[top];
			}
			else{				
				return 0;
			}
		}
			
};

int priority(char ch){
	int precedence;
	switch(ch){
		case '+':
		case '-':
			precedence=1;
			break;
		case '*':
		case '/':
			precedence=2;
			break;
		case '(':
		case ')':
			precedence =3;
			break;
		default:
			precedence=-1;
			break;
	
	}
	return precedence;
}

bool isOperand(char operand){
	if((operand>='a' && operand<='z')||(operand>='A'&&operand<='Z')){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	string infix="(A+B)*C-(D-E)*(F+G)";
	string output="";
	Stack s1;
	for(int i=0;i<infix.length();i++){
		if (isOperand(infix[i])){
			output+=infix[i];
		}
		else{
			if(s1.isEmpty()){
				s1.push(infix[i]);
			}
			
			else if(s1.peek()=='('){
				s1.push(infix[i]);
			}
			
			else if(infix[i]==')'){
				while(s1.peek()!='('){
					output+=s1.pop();
				}
				s1.pop();
			}
			else{
				if(priority(infix[i])>priority(s1.peek())){
					s1.push(infix[i]);
				}
				else{
					output+=s1.pop();
					while(priority(infix[i])<=priority(s1.peek()) && s1.isEmpty()==false){
						output+=s1.pop();								
						}
					s1.push(infix[i]);
					}
				//priority(infix[i])<priority(s1.peek())
				}
		}
	

		                                          
		if(i==infix.length()-1){
			while(s1.isEmpty()!=true){
				output+=s1.pop();
			}
		}
	}
	cout<<output<<endl;
}