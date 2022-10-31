#include<stdio.h>
#include<stdlib.h>

void fcfs(int [], int, int);
void scan(int [], int, int);
void cscan(int [], int, int);

void main()
{
	int n, i;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int process[n], intialhead;
	printf("Enter the sequence : ");
	for( i=0; i<n ; i++ )
	{
		scanf("%d",&process[i]);
	}
	printf("Enter the intialhead : ");
	scanf("%d", &intialhead);
			int o;
	do
	{
		printf("\n\nOptions are : \n 1.FCFS\t2.SCAN\t3.C-SCAN\t4.EXIT\nEnter the choice : ");

		scanf("%d",&o);
		switch(o)
		{
			case 1 : printf("\n\nFCFS DISK SCHEDULING\n\n"); fcfs(process, n, intialhead); break;
			case 2 : printf("\n\nSCAN DISK SCHEDULING\n\n"); scan(process, n, intialhead); break;
			case 3 : printf("\n\nC-SCAN DISK SCHEDULING\n\n"); cscan(process, n, intialhead); break;
			case 4 : break;
			default		 : printf("Wrong Choice!!!");
		
		}
	}while(o!=4);
}

void fcfs(int p[], int n, int intialhead)
{
	int total=0,i;
	for(i=0;i<n;i++)
	{
		total = total + abs(p[i]-intialhead);
		intialhead = p[i];
	}
	printf("Total Head Movement : %d",total);
}

void scan(int q[], int n, int intialhead)
{
	int disksize, dirn, index, temp, i=0, j=0, total=0;
	printf("Enter the disksize : ");
	scanf("%d", &disksize);
	printf("Enter the direction : ");
	scanf("%d",&dirn);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if( q[j]>q[j+1] )
			{
				temp = q[j];
				q[j] = q[j+1];
				q[j+1] =  temp;	
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(intialhead < q[i])
		{
			index = i;	
			break;
		}
	}
		if(dirn==1)
		{
			for(i=index;i<n;i++)
			{
				total += abs(q[i] - intialhead) ;
				intialhead = q[i];
			}
			total = total +abs(disksize - q[i-1]-1) ;
			intialhead = disksize -1 ;
			
			for(i=index-1; i>=0;i--)
			{
				total = total +abs(q[i] - intialhead) ;
				intialhead = q[i];
			}
		}
		else
		{
			for(i=index-1; i>=0;i--)
			{
				total = total +abs(q[i] - intialhead) ;
				intialhead = q[i];
			}
			total+= abs(q[i+1]);
			intialhead = 0;
			
			for(i=index;i<n;i++)
			{
				total=total+abs(q[i]-intialhead);
				intialhead=q[i];
			
			}
		}
	printf("Total Head Movement = %d",total);
}


void cscan(int RQ[], int n, int initial)
{
	int size, dirn, index, i=0, j=0, TotalHeadMoment = 0;
	printf("Enter the disksize : ");
	scanf("%d", &size);
	printf("Enter the direction : ");
	scanf("%d",&dirn);
	    for(i=0;i<n;i++)
   		 {
        for( j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }

        }
    }


    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   

    if(dirn==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }

        TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);

        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial=0;
        for( i=0;i<index;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }

    else
    {
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }

        TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial =size-1;
        for(i=n-1;i>=index;i--)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    
		
	printf("Total head movement = %d",TotalHeadMoment);
}
