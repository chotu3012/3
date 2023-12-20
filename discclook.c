#include<stdio.h>
void sort(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main(){
	int i,n,head,st=0;
	printf("enter no.of tracks");
	scanf("%d",&n);
	int arr[n];
	printf("enter head");
	scanf("%d",&head);
	printf("enter no.of tracks");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,n);
	for(i=0;i<n;i++){
		if(arr[i]>head){
			st+=arr[n-1]-head;
			break;
		}
	}
	for(i=n-1;i>0;i--){
		if(arr[i]<head){
			st+=(arr[i]-arr[0])+arr[0];
		}
	}
	printf("%d is seek time",st);
}
