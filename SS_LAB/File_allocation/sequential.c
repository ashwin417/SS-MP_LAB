#include<stdio.h>
#include<stdlib.h>
 
void main()
{
	int i,st,len,j,c,k,count=0,f[50];
	for(i=0;i<50;i++)
	{
		f[i]=0;
	}
	printf("Files allocated are : \n");
	x : count = 0;
	printf("Enter starting block & length of the files : ");
	scanf("%d %d",&st,&len);
	for(k=st;k<(st+len);k++)
	{
		if(f[k]==0)
			count++;
	}
	if(len==count)
	{
		for(j=st;j<(st+len);j++)
		{
			if(f[j]==0)
			{
				f[j]=1;
				printf("%d\t%d\n",j,f[j]);
			}	
		}
	}
	
	if(st>=50)
		printf("Cannot Allocate\n");
	else if(j!=(st+len-1))
		printf("The file is allocated to disk\n");
	else 
		printf("The file is not allocated\n");
	printf("Do you want to enter more files? \n\t Yes => 1 , No => 0\nEnter your choice : ");
	scanf("%d",&c);
	if(c==1)
		goto x;
	else
		exit(0);
}
