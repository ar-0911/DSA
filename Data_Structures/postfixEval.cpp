#include<iostream>
#include<string>
using namespace std;

class Stack{
	int top;
	int arr[10];
	
	public:
		Stack(){
			top=-1;
			for(int i=0;i<10;i++){
				arr[i]=0;
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
		
		bool isFull(){
			if(top==9){
				return true;
			}
			else{
				return false;
			}
		}
		
		void push(int element){
			if(isFull()){
				cout<<"Stack overflow"<<endl;
			}
			else{
				top++;
				arr[top]=element;
			}
		}
		
		int pop(){
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
		
		int peek(){
			if(isEmpty()){
				return 0;
			}
			else{
				return arr[top];
			}
		}
};

int operation(char op, int a, int b){
	int res = 0;
	switch(op){
		case'+':
			res=a+b;
			break;
		case '-':
			res=a-b;
			break;
		case '*':
			res=a*b;
			break;
		case '/':
			res =a/b;
			break;
		default:
			res=0;	
	}
	return res;
}

int main(){
	Stack s1;
	string expression="5379++";
	int result;
	int num;
	bool evaluated = false;
	for(int i=0;i<expression.length();i++){
		if(isdigit(expression[i])){
			num=(int)(expression[i]-'0');
			s1.push(num);
		}
		else{
			int num1=s1.pop();
			int num2=s1.pop();
			result=operation(expression[i],num2,num1);
			s1.push(result);
		}
	}
	cout<<"The result is: "<<s1.pop()<<endl;
	
}