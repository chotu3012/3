#include<stdio.h>
//78 63 14 53 48 97 182

int main(){
	int i,n,head,st=0;
	printf("enter no.of tracks");
	scanf("%d",&n);
	int arr[n];
	printf("enter head");
	scanf("%d",&head);
	printf("enter  tracks");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++){
		st+=abs(head-arr[i]);
		head=arr[i];
	}
	printf("%d is seek time",st);
}
