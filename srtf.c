#include<stdio.h>
/*
1 0 8
2 1 6
3 2 5
4 3 2 
5 4 4 
6 5 1
*/
struct process{
	int pno,at,bt;
};
int c=0;
int find(struct process s[],int n){
	int i,ind=-1,min=9999;
	for(i=0;i<n;i++){
		if(s[i].bt!=0 && s[i].at<=c && min>s[i].bt){
			min=s[i].bt;
			ind=i;
			
		}
		else if(s[i].bt!=0 && s[i].at<=c && min==s[i].bt){
			if(s[i].at<s[ind].at){
				ind=i;
			}
		}
	}
	return ind;
}
int main(){
	int i,j,end=1,k,n;
	float atat=0,awt=0;
	printf("enter n value");
	scanf("%d",&n);
	printf("enter pno,at,bt");
	struct process s[n];
	int ct[n],tat[n],wt[n],bt[n];
	for(i=0;i<n;i++){
		scanf("%d%d%d",&s[i].pno,&s[i].at,&s[i].bt);
		bt[i]=s[i].bt;
	}
	while(end){
		k=find(s,n);
		if(k==-1){
			c++;
			printf("idle");
		}
		else{
			c++;
			ct[k]=c;
			printf("%d",s[k].pno);
			s[k].bt--;
			end=0;
			for(i=0;i<n;i++){
				if(s[i].bt>0){
					end=1;
					break;
				}
			}
		}
		
		
	}
	for(i=0;i<n;i++){
			//printf("%d ",ct[i]);
			tat[i]=ct[i]-s[i].at;
			wt[i]=tat[i]-bt[i];
			
		}
		printf("\nct tat wt\n");
		for(i=0;i<n;i++){
			printf("%d %d %d\n",ct[i],tat[i],wt[i]);
			atat+=tat[i];
			awt+=wt[i];
		}
	printf("%f %f",atat/n,awt/n);
}
