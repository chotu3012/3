#include<stdio.h>
int visited[20];
int main(){
	int i,n,head;
	printf("enter no.of tracks");
	scanf("%d",&n);
	int arr[n];
	printf("enter head");
	scanf("%d",&head);
	printf("enter  tracks");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n+1;i++){
		visited[i]=-1;
	}
	int k=n,d,ind,st=0;
	while(n>0){
		int min=9999;
		for(i=0;i<k;i++){
			d=abs(head-arr[i]);
			if(min>d && visited[i]==-1){
				min=d;
				ind=i;
			}
		}
		st+=min;
		head=arr[ind];
		visited[ind]=1;
		n--;
	}
	printf("Seek time is %d",st);
}
