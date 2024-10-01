#include<stdlib.h>
#include<stdio.h>
#define max 100
#define min 10
int ref[max],count,frame[min],n;
void input()
{
int i,temp;
count=0;
printf("\nEnter the number of page frames : ");
scanf("%d",&n);
printf("\nEnter the reference string (-1 for end) : ");
scanf("%d",&temp);
while(temp != -1)
{
ref[count++]=temp;
scanf("%d",&temp);
}
}
void LRU()
{
int i,j,k,stack[min],top=0,fault=0;
system("CLS");
for(i=0;i<count;i++)
{
if(top<n)
stack[top++]=ref[i],fault++;
else
{
for(j=0;j<n;j++)
if(stack[j]==ref[i])
break;
if(j<n)
{
for(k=j;k<n-1;k++)
stack[k]=stack[k+1];
stack[k]=ref[i];
}
else
{
for(k=0;k<n-1;k++)
stack[k]=stack[k+1];
stack[k]=ref[i];
fault++;
}
}
printf("\nAfter inserting %d the stack status is : ",ref[i]);
for(j=0;j<top;j++)
printf("%d ",stack[j]);
}
printf("\nEnd to inserting the reference string.");
printf("\nTotal page fault is %d.",fault);
printf("\nPress any key to continue.");
}
void main()
{
int x;
//freopen("in.cpp","r",stdin);
while(1)
{
printf("\n----MENU---- ");
printf("\n1. Input ");
printf("\n2. LRU (Least Recently Used) Algorithm");
printf("\n0. Exit.");
printf("\nEnter your choice: ");
scanf("%d",&x);
switch(x)
{
case 1:
input();
break;
case 2:
LRU();
break;
case 0:
exit(0);
}
}
}
