#include<stdio.h>

struct student{
	char name[100];
	int notest;
	float avgruns;
};

int main()
{
	struct student s[3];
	struct student *ptr;
	ptr=s;
	int i;
	float totalavg;
	for(i=0;i<3;i++)
	{
		printf("Enter detail of student #%d\n",(i+1));
		scanf("%s", ptr->name);
		scanf("%d", &ptr->notest);
		scanf("%f", &ptr->avgruns);
		totalavg+=ptr->avgruns;
		ptr++;
	}
	totalavg/=3;
	printf("%f\n", totalavg);
	ptr=s;
	for(i=0;i<3;i++)
	{
		if(ptr->avgruns>totalavg)
		{
			printf("%s", ptr->name);
		}
		ptr++;
	}
}