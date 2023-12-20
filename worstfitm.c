#include<stdio.h>
void worstfit(int n,int p[],int m,int b[])
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
	    int index=-1;	
	    for(j=0;j<m;j++)
	    {
	    	if(b[j]>=p[i] && !occupied[j])
	    	{
	    		if(index==-1)
	    		index=j;
	    		else if(b[j]>b[index])
	    		index=j;
			}
		}
		if(index!=-1)
		{
			allocated[i]=index;
			occupied[index]=1;
		}
	}
	printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, p[i]);
        if (allocated[i] != -1)
            printf("%d\n",allocated[i] + 1);
        else
            printf("Not Allocated\n");
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
	worstfit(n,p,m,b);
	return 0;	
}
