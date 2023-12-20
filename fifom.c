#include<stdio.h>
void main()
{
	int i,j,k,pf=0,count=0,rs[30],m[30],n,f;
	printf("enter the length of the reference string:");
	scanf("%d",&n);
	printf("enter the reference string:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
	}
	printf("enter the no of frames:");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		m[i]=-1;
	}
	printf("\nthe page replacement processs is...\n");
	for(i=0;i<n;i++)
	{
		for(k=0;k<f;k++)
		{
			if(m[k]==rs[i])
			break;
		}
		if(k==f)
		{
			m[count++]=rs[i];
			pf++;
		}
		for(j=0;j<f;j++)
		{
			printf("\t%d",m[j]);
		}if(k==f)
		printf("\t pf no:%d",pf);
		printf("\n");
		if(count==f)
			count=0;
		}
		printf("\nNo of page faults are:%d",pf);	
}
