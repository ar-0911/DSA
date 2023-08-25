#include<iostream>
using namespace std;

class Stack{
	int top;
	int arr[100000];
	
	public:
		Stack(){
			top=-1;
			for(int i=0;i<100000;i++){
				arr[i]=0;
			}
		}
		
		int getMax(){
			int max=0;
			for(int i=0;i<100000;i++){
				if(arr[i]>max){
					max=arr[i];
				}
			}
			return max;
		}
		
		bool isFull(){
			if (top==99999){
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
		
		void push(int element){
			if(!isFull()){
				top++;
				arr[top]=element;
			}
			else{
				cout<<"Stack overflow"<<endl;
			}
		}
		
		int pop(){
			if(!isEmpty()){
				int popped = arr[top];
				top--;
				return popped;
			}
			else{
				cout<<"Stack is empty"<<endl;
				return 0;
			}
		}
};

int main(){
	Stack s1;
	int operations;
	cin>>operations;
	int code, number;
	for(int i=0;i<operations;i++){
		cin>>code;
		if(code==1){
			cin>>number;
			s1.push(number);
		}
		else if(code==2){
			s1.pop();
		}
		else if(code==3){
			cout<<s1.getMax()<<endl;
		}
		else{
			cout<<"operation invalid"<<endl;
			continue;
		}
	}
}