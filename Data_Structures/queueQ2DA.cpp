#include<iostream>
#include<string.h>
using namespace std;
#define max 5
struct queue
{
    char a[max];
    int f,r;
}q;
void initialize()
{
    q.f=q.r=-1;
}
int enqueue(char c)
{
    if(((q.f==0)&&(q.r==max-1)) || (q.r+1==q.f))
        return 1;
    else{
    if(q.r==-1)
    {
        q.r=0;
        q.f=0;
    }
    else if(q.r==max-1)
        q.r=0;
    else
        q.r++;
    q.a[q.r]=c;
    }return 0;
}
char dequeue()
{
    if(q.f==-1)
    {
        cout<<"Empty queue";
        return '\0';
    }
    else
    {
        char c = q.a[q.f];
        if(q.r==q.f)
            q.r=q.f=-1;
        else if(q.f==max-1)
            q.f=0;
        else
            q.f++;
        return c;
    }
}
void display()
{
    int i;
    for(i=0;i<max-1;i++)
        cout<<q.a[i]<<"\t";
    cout<<"\nfront: "<<q.f<<"\trear: "<<q.r<<endl;
}
int main()
{
    string str,str1;
    cout<<"Enter a String to write data in DVD\n";
    getline(cin,str,'#');
    int i,f,choice;
    initialize();

    for(i=0;str[i]!='\0';i++)
    {
        f=enqueue(str[i]);
        if(f==1)
        {
            do{
            cout<<"Buffer is:\n";
            display();
            cout<<"Enter 1 to read and 2 to exit\n";
            cin>>choice;
            if(choice==1)
            {
                str1=str1+dequeue();
                cout<<"output: "<<str1<<endl;
            }
            f=enqueue(str[i]);
            i++;
            }while(choice!=2);
        }
        if(choice==2)
            break;
        f=0;
    }
}