#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,j,k=1,t,b=0,min,temp[30],at[30],bt[30],wt[30],pr[30],tat[30];
	float awt=0,atat=0;
	printf("enter the no of process");
	scanf("%d",&n);
	printf("enter the burst time,arrival time and priority");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&bt[i],&at[i],&pr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(at[i]<at[j])
			{
				t=at[j];
				at[j]=at[i];
				at[i]=t;
				
				t=bt[j];
				bt[j]=bt[i];
				bt[i]=t;
			}
		}
	}
	for(j=0;j<n;j++)
	{
		b=b-bt[j];
		min=bt[k];
		for(i=k;i<n;i++)
		{
			min=pr[k];
			if(b<=at[i])
			{
				if(pr[i]<min)
				{
				t=at[k];
				at[k]=at[i];
				at[i]=t;
				
				t=bt[k];
				bt[k]=bt[i];
				bt[i]=t;
				
				t=pr[k];
				pr[k]=pr[i];
				pr[i]=t;	
				}
			}
		}
		k++;
	}
	temp[0]=0;
	printf("process\tburst time\tarrival time\tpriority\twaitingtime\tturn aroundtime\n");
	for(i=0;i<n;i++)
	{
		wt[i]=0;
		tat[i]=0;
		temp[i+1]=temp[i]+bt[i];
		wt[i]=temp[i]-at[i];
		tat[i]=wt[i]+bt[i];
		awt=awt+wt[i];
		atat=atat+tat[i];
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],at[i],pr[i],wt[i],tat[i]);
	}
	awt=awt/n;
	atat=atat/n;
	printf("average waiting time=%f\n",awt);
	printf("average turn around time=%f",atat);
}
