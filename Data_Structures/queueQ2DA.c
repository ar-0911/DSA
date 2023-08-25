#include<stdio.h>
#include<string.h>
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
        printf("Empty queue");
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
        printf("%c\t",q.a[i]);
    printf("\nfront: %d\trear: %d\n",q.f,q.r);
}
int main()
{
    char str[50],str1[50];
    printf("Enter a String to write data in DVD\n");
    scanf("%s",str);
    int i,f,choice;

    for(i=0;str[i]!='\0';i++)
    {
        f=enqueue(str[i]);
        if(f==1)
        {
            do{
            printf("Buffer is:\n");
            display();
            printf("Enter 1 to read and 2 to exit\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                const char c = dequeue();
                strncat(str1,&c,1);
                printf("output: %s\n",str1);
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