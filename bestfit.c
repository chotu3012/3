#include<stdio.h>
int c[10],inf=0;
int visited[10];
/*100
500
200
300
600

212
417
112
426
*/
int sort(int a[],int n,int b[],int x){
	int i,j,l=100,min=9999;
	for(i=0;i<n;i++){
	if(a[i]>=b[x]& visited[i]==-1 ){
		if(min>a[i]){
			min=a[i];
			j=i;  
		} 		
	}
    }
    if(min!=9999)
    	return j;
    else
    	return l;				
}
int  main(){
	int n,m,i,l=0,ef=0;
	printf("enter  the no of partitions");
	scanf("%d",&n);
	int a[n];
	printf("enter the sizes of the memory for respective partition");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter the no of processors");
	scanf("%d",&m);
	int b[m],c[n];
	for(i=0;i<n;i++)
		visited[i]=-1;
	printf("enter the sizes of the processors");
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	for(i=0;i<m;i++){
		int k=sort(a,n,b,i);
		if(k!=100){
			visited[k]=i;
			inf+=a[k]-b[i];	
		}			
		else{
			c[l]=i;
			//ef+=a[k];
			l++;
		}
	}
	for(i=0;i<n;i++)
	{
		if(visited[i]==-1){
			printf(" empty");
			ef+=a[i];
		}
			
		else
			printf(" %d  ",visited[i]);
	}
	if(l!=0){
		printf("\nthe waiting processors are ");
		for(i=0;i<l;i++){
				printf("%d ",c[i]);
				
		}
		
		
	}
	printf("external and internal fragmentation are: %d %d",ef,inf)	;
}
