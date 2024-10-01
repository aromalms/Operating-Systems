#include <stdio.h>
void swap(int *,int *);
int main()
{
	int n;
	
	printf("Enter the number of process\n");
	scanf("%d",&n);
	int btime[n];
	int wtime[n];
	int ttime[n];
    int temp=0;
	int i,j;
    int pid[n];
	float totalw=0;
	float totalt=0;
	
	for(i=1; i<=n; i++)
	{
		printf("Enter the burst Time my of Process %d:",i);
		printf("\nP[%d]:",i);
		scanf("%d",&btime[i]);
        pid[i]=i;
	}

    for(i=1; i<=n; i++)
	{
	for(j=1; j<=n; j++)
	{
		if(btime[j]>btime[i])
		{
		//Swapping
            swap(&btime[i],&btime[j]);
            swap(&pid[i], &pid[j]);
        }
	}
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
	printf("\n P[%d]\t\t %d\t\t%d\t\t%d",pid[i],btime[i],wtime[i],ttime[i]);
	
	for(i=1; i<=n; i++)
	{
	totalw=wtime[i]+totalw;
	totalt=ttime[i]+totalt;
	}
	float avgwt=totalw/n;
	float avgtt=totalt/n;
	printf("\nAverage Waiting Time:%f", avgwt);
	printf("\nAverage Turn Around Time:%f", avgtt);
	
	printf("\n======================================\n");
	for( i=1; i<=n; i++)
	{
		printf("  P%d ",pid[i]);
	}
	
	printf("\n======================================\n");
    temp=0;
	for( i=1; i<=n; i++)
	{
		printf("%d    ",temp);
		temp=temp+btime[i];
	}
    printf("%d",ttime[n]);
    		
}

void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

   