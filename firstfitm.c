#include<stdio.h>
void firstfit(int n,int p[],int m,int b[])
{
	int allocated[n];
	int occupied[m];
	int i,j;
	for(i=0;i<n;i++)
	{
		allocated[i]=-1;
	}
	for(i=0;i<m;i++)
	{
		occupied[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(!occupied[j]&&b[j]>=p[i])
			{
				allocated[i]=j;
				occupied[j]=1;
				break;
			}
		}
	}
	printf("\nprocess\t\tprocess size\t\tblock no\n");
	for(i=0;i<n;i++)
	{
		printf("%d \t\t %d\t\t",i+1,p[i]);
		if(allocated[i]!=-1)
		printf("%d\n",allocated[i]+1);
		else
		printf("not allocated\n");
	}
}
int main()
{
	int n,m,i,j;
	int p[n],b[m];
	printf("enter the no of processes:");
	scanf("%d",&n);
	printf("enter the sizes of the processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("enter the no of blocks:");
	scanf("%d",&m);
	printf("enter the block sizes:");
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
	}
	firstfit(n,p,m,b);
	return 0;
	
}
