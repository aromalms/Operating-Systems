#include <stdio.h>

int main()
{
	int n;
	
	printf("Enter the number of process");
	scanf("%d",&n);
	int btime[n];
	int wtime[n];
	int ttime[n];
	int i;
	float totalw=0;
	float totalt=0;
	
	for(i=1; i<=n; i++)
	{
		printf("Enter the burst Time of Process %d:",i);
		printf("\nP[%d]:",i);
		scanf("%d",&btime[i]);
	}
	
	wtime[1]=0;
	for(i=2; i<=n;i++)
	{
		wtime[i]=wtime[i-1]+btime[i-1];
	}
	
	for(i=1; i<=n; i++)
	{
		ttime[i]=btime[i]+wtime[i];
	}
	
	printf("\n ProcessID	Burst time	Waiting time	TA time");
	for(i=1; i<=n; i++)
	printf("\n P[%d]\t\t %d\t\t%d\t\t%d",i,btime[i],wtime[i],ttime[i]);
	
	for(i=1; i<=n; i++)
	{
	totalw=wtime[i]+totalw;
	totalt=ttime[i]+totalt;
	}
	float avgwt=totalw/n;
	float avgtt=totalt/n;
	int temp=0;
	printf("\nAverage Waiting Time:%f", avgwt);
	printf("\nAverage Turn Around Time:%f", avgtt);
	
	printf("\n======================================\n");
	for( i=1; i<=n; i++)
	{
		printf(" P%d ",i);
	}
	
	printf("\n======================================\n");
	for( i=1; i<=n; i++)
	{
		printf("%d  ",temp);
		temp=temp+btime[i];
	}		
}


