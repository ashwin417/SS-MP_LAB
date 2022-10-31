#include<stdio.h>
#include<stdlib.h>
 
void main()
{
	int i,st,len,j,c,p,f[50],a,k;
	for(i=0;i<50;i++)
	{
		f[i]=0;
	}
	printf("Enter how many blovks are already allocated : ");
	scanf("%d",&p);
	printf("Enter block already allocated : ");
	for(i=0;i<p;i++)
	{
		scanf("%d",&a);
		f[a]=1;
	}
	
	x: printf("Enter index starting block and length : ");
	scanf("%d%d",&st,&len);
	k=len;
	if(f[st]==0)
	{
		for(j=st;j<(st+k);j++)
		{
			if(f[j]==0)
			{
				f[j]=1;
				printf("%d ---> %d\n",j,f[j]);
			}
			else
			{
			printf("%d block already allocation\n",j);
			k++;
			}			
		}
	}
	else 
		printf("%d starting block is already allocated\n",st);
	
	printf("Do you want to enter more file\n\t Yes => 1, No => 0\nEnter your choice : ");
	scanf("%d",&c);
	if(c==1)
		goto x;
	else 
		exit(0);
}
