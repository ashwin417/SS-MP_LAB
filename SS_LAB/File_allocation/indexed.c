#include<stdio.h>
#include<stdlib.h>
 
void main()
{
	int i,st,index[50],len,j,c,t,count=0,f[50],ind,n;
	for(i=0;i<50;i++)
	{
		f[i]=0;
	}
	printf("Files allocated are : \n");
	x : printf("Enter the index block : ");
	scanf("%d",&ind);
	if(f[ind] != 1)
	{
		printf("Enter the number of blocks needed and no of file for index %d on the disk: ",ind);
		scanf("%d",&n);
	}
	else 
	{
		printf("%d index is already allocated\n", ind);
		goto x;
	}
	
	y: count = 0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&index[i]);
		if(f[index[i]]==0)
			count++;	
	}
	if(count == n)
	{
		for(j=0;j<n;j++)
			{ f[index[j]]=1; }
		printf("Allocated \n");
		for(t=0;t<n;t++)
		{
			printf("%d ----> %d : %d\n",ind,index[t],f[index[t]]);
		}
	}
	else
	{
		printf("File in the index ius allocated \n");
		printf("Enter another file index : ");
		goto y;
	}
	
	printf("Do you want to enter more file\n\t Yes => 1, No => 0\nEnter your choice : ");
	scanf("%d",&c);
	if(c==1)
		goto x;
	else 
		exit(0);
}
