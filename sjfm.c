#include<stdio.h>
#include<conio.h>
#define max 30
void main(){
  int i,j,n,bt[max],wt[max],t,p[max],tat[max];
  float awt=0,atat=0;
  printf("enter the no.of processes:");
  scanf("%d",&n);
  printf("enter the id`s of the processes:");
  for(i=0;i<n;i++){
  	scanf("%d",&p[i]);}
  printf("enter the burst times of the processes:");
  for(i=0;i<n;i++){
  	scanf("%d",&bt[i]);}
  	for(i=0;i<n;i++)
  	{
  		for(j=0;j<n-i-1;j++)
  		{ 
  		  if(bt[j]>bt[j+1])
  		  {
  		  	t=bt[j];
  		  	bt[j]=bt[j+1];
  		  	bt[j+1]=t;
  		  	
  		  	t=p[j];
  		  	p[j]=p[j+1];
  		  	p[j+1]=t;
			}
		  }
	  }
	  printf("process\t bursttime\t waitingtime\t turnaroundtime\n");
	  for(i=0;i<n;i++)
	  {
	  	wt[i]=0;
	  	tat[i]=0;
	  	for(j=0;j<i;j++){

	  		wt[i]=wt[i]+bt[j];
		  }
		  tat[i]=wt[i]+bt[i];
		  awt=awt+wt[i];
		  atat=atat+tat[i];
		  printf("%d\t %d\t\t %d\t\t %d\n",p[i],bt[i],wt[i],tat[i] );
	  }
	  awt=awt/n;
	  atat=atat/n;
	  printf("avearge waiting time=%f\n",awt);
	  printf("average turn around time=%f",atat);
	  }
 	

