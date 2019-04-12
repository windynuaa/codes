#include <stdio.h>
#include <math.h>
typedef struct{
    int x;
    int y;
    int on;
}flower;
double find_min(int x,int y,flower* flowers,int start)
{
	//200 0 200 10 200 50 200 30 200 25
    int i;
    double min=99999;
	int minn=8;
	double temp;
    temp=0;
	for(i=0;i<6;i++)
    {
        if(flowers[i].on==0)		
		{
			flowers[i].on=1;
            temp=find_min(flowers[i].x,flowers[i].y,flowers,start);
			printf("\t%4.2f ",temp);
			temp+=sqrt(((x-flowers[i].x)*(x-flowers[i].x))+((y-flowers[i].y)*(y-flowers[i].y)));
			printf("\t%4.2f \n",temp);
            if(temp<min)
            {
                minn=i;
                min=temp;
            }   
			flowers[i].on=0;
			printf("\t%d ",flowers[i].on);
		}
    }
    if(minn==8)
		min=0;
	else
		flowers[minn].on=1;
	return min;
}

double cir_find(flower flowers[6])
{
	int a,b,c,d,e;
	double dist,dista=0,distb=0,distc=0,distd=0,diste=0,min=99999999;
	for(a=0;a<5;a++)
	{
		dista=sqrt((flowers[a].x)*(flowers[a].x)+(flowers[a].y)*(flowers[a].y));
		for(b=0;b<5;b++)
		{
			if(b==a)
				continue;
			distb=sqrt(((flowers[a].x-flowers[b].x)*(flowers[a].x-flowers[b].x))+((flowers[a].y-flowers[b].y)*(flowers[a].y-flowers[b].y)));
			for(c=0;c<5;c++)
			{	
				if(c==a||c==b)
					continue;
				distc=sqrt(((flowers[c].x-flowers[b].x)*(flowers[c].x-flowers[b].x))+((flowers[c].y-flowers[b].y)*(flowers[c].y-flowers[b].y)));
				for(d=0;d<5;d++)
				{
					if(d==c||d==a||d==b)
						continue;
					distd=sqrt(((flowers[c].x-flowers[d].x)*(flowers[c].x-flowers[d].x))+((flowers[c].y-flowers[d].y)*(flowers[c].y-flowers[d].y)));
					for(e=0;e<5;e++)
					{	
						if(e==d||e==c||e==b||e==a)
							continue;
						diste=sqrt(((flowers[e].x-flowers[d].x)*(flowers[e].x-flowers[d].x))+((flowers[e].y-flowers[d].y)*(flowers[e].y-flowers[d].y)));
						diste+=sqrt((flowers[e].x)*(flowers[e].x)+(flowers[e].y)*(flowers[e].y));
						dist=dista+distb+distc+distd+diste;
						if(dist<min)
						{
							min=dist;
						}
					}
		
				}
		
			}
		
		}
		
	}
	return min;
}

int main()
{
    int distance,now_x=0,now_y=0,min=9999999;
	int i;
    flower flowers[6]={0};//200 0 200 10 200 50 200 30 200 25 :456
    scanf("%d %d %d %d %d %d %d %d %d %d",&flowers[0].x,&flowers[0].y,&flowers[1].x,&flowers[1].y,&flowers[2].x,&flowers[2].y,&flowers[3].x,&flowers[3].y,&flowers[4].x,&flowers[4].y);
	distance=(int)cir_find(flowers);
	printf("%d",distance);
}