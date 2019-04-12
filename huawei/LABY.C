#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int x;
	int y;
	int a;
}loc;
int main()
{
	loc *locs;
	int n;
	int x[50]={0},y[50]={0},maxx=0,maxy=0,maxxn=0,maxyn=0;
	scanf("%d",&n);
	getchar();
	int i;
	int num=0;
	locs=(loc *)malloc(sizeof(loc)*n);

	for(i=0;i<n;i++)
	{
		printf("loc %d :\n",i);
		scanf("%d %d",&locs[i].x,&locs[i].y);
		x[locs[i].x]++;
		y[locs[i].y]++;
		if(x[locs[i].x]>maxx)
		{
			maxxn=locs[i].x;
			maxx=x[locs[i].x];
		}
		if(y[locs[i].y]>maxy)
		{
			maxyn=locs[i].y;	
			maxy=y[locs[i].y];
		}
		getchar();
		locs[i].a=1;
	}
	int ns;
	ns=n;
	while(ns>0)
	{
		
		if(maxx>maxy)
		{
			for(i=0;i<n;i++)
			{
				if(locs[i].x==maxxn&&locs[i].a==1)
				{
					locs[i].a=0;
					ns--;
				}
			}				
			//ns-=maxx;
			num++;
			maxx=0;
			maxy=0;
			for(i=0;i<50;i++)
			{
				x[i]=0;
				y[i]=0;
			}
			for(i=0;i<n;i++)
			{
				if(locs[i].a==1)
				{
					x[locs[i].x]++;
					y[locs[i].y]++;
					if(x[locs[i].x]>maxx)
					{
						maxxn=locs[i].x;
						maxx=x[locs[i].x];
					}
					if(y[locs[i].y]>maxy)
					{
						maxyn=locs[i].y;	
						maxy=y[locs[i].y];
					}	
				}
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(locs[i].y==maxyn&&locs[i].a==1)
				{
					locs[i].a=0;
					ns--;
				}
			}				
			num++;
			maxx=0;
			maxy=0;
			for(i=0;i<50;i++)
			{
				x[i]=0;
				y[i]=0;
			}
			for(i=0;i<n;i++)
			{
				if(locs[i].a==1)
				{
					x[locs[i].x]++;
					y[locs[i].y]++;
					if(x[locs[i].x]>maxx)
					{
						maxxn=locs[i].x;
						maxx=x[locs[i].x];
					}
					if(y[locs[i].y]>maxy)
					{
						maxyn=locs[i].y;	
						maxy=y[locs[i].y];
					}	
				}
			}
		}
	}
	
	printf("\nfinal %d\n",num);
}