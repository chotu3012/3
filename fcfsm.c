#include<stdio.h>
#include<conio.h>
#define max 30
void main(){
  int i,j,n,bt[max],at[max],wt[max],temp[max],tat[max];
  float awt=0,atat=0;
  printf("enter the no.of processes:");
  scanf("%d",&n);
  printf("enter the burst times of the processes:");
  for(i=0;i<n;i++){
  	scanf("%d",&bt[i]);}
  printf("enter the arrival times of the processes:");
  for(i=0;i<n;i++){
  	scanf("%d",&at[i]);	
  }
  temp[0]=0;
  printf("process\t bursttime\t arrivaltime\t waitingtime\t turnaroundtime\n");
  for(i=0;i<n;i++){
  	wt[i]=0;
  	tat[i]=0;
  	temp[i+1]=temp[i]+bt[i];
  	wt[i]=temp[i]-at[i];
    tat[i]=wt[i]+bt[i];
    awt=awt+wt[i];
    atat=atat+tat[i];
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],at[i],wt[i],tat[i]);
  }
  awt=awt/n;
  atat=atat/n;
  printf("average waiting time=%f\n",awt);
  printf("average turnaround time=%f\n",atat);
  }
