#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n,qt,count=0,temp,sq=0,bt[10],wt[10],tat[10],rem_bt[10];
	float awt=0,atat=0;
	printf("enter the no of process");
	scanf("%d",&n);
	printf("enter the burst time of the process");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		rem_bt[i]=bt[i];
	}
	printf("enter the quatum num");
	scanf("%d",&qt);
	while(1)
	{
		for(i=0,count=0;i<n;i++)
		{
			temp=qt;
			if(rem_bt[i]==0)
			{
				count++;
				continue;
			}
			if(rem_bt[i]>qt)
			   rem_bt[i]=rem_bt[i]-qt;
			else
			  if(rem_bt[i]>=0)
			  {
			  	temp=rem_bt[i];
			  	rem_bt[i]=0;
				 }
				 sq=sq+temp;
				 tat[i]=sq;
			}
			if(n==count)
			break;
		}
		printf("\nprocess\tbursttime\tturnaroundtime\twaitingtime\n");
		for(i=0;i<n;i++){
			wt[i]=tat[i]-bt[i];
			awt=awt+wt[i];
			atat=atat+tat[i];
			printf("\n%d\t%d\t%d\t%d\n",i+1,bt[i],tat[i],wt[i]);
		}
		awt=awt/n;
		atat=atat/n;
		printf("average wating time =%f\n",awt);
		printf("average turnaroundtime=%f",atat);
	}
