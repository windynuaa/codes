#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 500000
#define DEBUG
void popp();
void selt();
void ins();
void quick(int *arr,int len);
void quick_main();
int main()
{
	//ins(); 				//unstable fast 
	//popp();				//unstable slowest
	//selt();				//unstable slow
	//quick_main(); 		//most stable  most fast
}
void ins()
{
	int  a[N];
	int *temp,*final;
	int count=0;
	int locate=0;
	int i,j;
	for(i=0;i<N;i++)
		a[i]=rand();
	#ifdef DEBUG
	clock_t start, finish;
    double  duration;
	start = clock();
	#endif
	temp=(int *)malloc(N*4);
	final=(int *)malloc(N*4);
	printf("malloc\n");
	for (i=0;i<N;i++)
	{
		if(a[i]>final[locate])
		{
			while(a[i]>=final[++locate]&&locate!=count);
			memcpy(temp,&final[locate],(count-locate)*4);//int 4 byte!!!
			final[locate]=a[i];
			memcpy(&final[locate+1],temp,(count-locate)*4);
			count++;
		}
		else
		{
			while(a[i]<=final[--locate]&&locate!=-1);
			locate++;
			memcpy(temp,&final[locate],(count-locate+1)*4);
			final[locate]=a[i];
			memcpy(&final[locate+1],temp,(count-locate+1)*4);
			count++;
		}
	}
	#ifdef DEBUG
    finish = clock();
    duration = (double)(finish - start);
	printf("ins time used %.2f  sec\n",duration);
	#endif
	free(final);
	free(temp);
	
}

void popp()
{
	int  a[N];
	int j,i,k;
	for(i=0;i<N;i++)
		a[i]=rand();
	#ifdef DEBUG
	clock_t start, finish;
    double  duration;
	start = clock();
	#endif
	for (j=0;j<N;j++)
	{
		for(i=0;i<N-1;i++)
		{
			if(a[i]>a[i+1])
			{
				k=a[i];
				a[i]=a[i+1];
				a[i+1]=k;
			}
		}
		
	}
	#ifdef DEBUG
    finish = clock();
    duration = (double)(finish - start);
	printf("pop time used %.2f  sec\n",duration);
	#endif
	//for(i=0;i<N;i++)
	//	printf("%d ",a[i]);
}

void selt()
{
	int  a[N];
	int j,i,k;
	for(i=0;i<N;i++)
		a[i]=rand();
	#ifdef DEBUG
	clock_t start, finish;
    double  duration;
	start = clock();
	#endif
	for (j=0;j<N;j++)
	{
		for(i=0;i<N;i++)
		{
			if(a[j]>a[i])
			{
				k=a[j];
				a[j]=a[i];
				a[i]=k;
			}
		}
	}
	#ifdef DEBUG
    finish = clock();
    duration = (double)(finish - start);
	printf("selt time used %.2f  sec\n",duration);
	#endif
}

void quick_main()
{
	int  *a;
	int j,i,k;
	a=(int* )malloc(N*4);
	for(i=0;i<N;i++)
		a[i]=rand();
	#ifdef DEBUG
	clock_t start, finish;
    double  duration;
	start = clock();
	#endif
	quick(a,N);
	#ifdef DEBUG
    finish = clock();
    duration = (double)(finish - start);
	printf("quick time used %.2f  sec\n",duration);
	#endif
	free(a);
	//for(i=0;i<N;i++)
	//	printf("%d ",a[i]);
}

void quick(int *arr,int len)
{
	int mid,m,i;
	int *left,*right,leftn=0,rightn=0;
	if(len<=1)
		return ;
	mid=len/2;
	left=(int *)malloc(len*4);
	right=(int *)malloc(len*4);
	for(m=0;m<mid;m++)
	{
		if(arr[m]<arr[mid])
			left[leftn++]=arr[m];
		else
			right[rightn++]=arr[m];
	}
	for(m=mid+1;m<len;m++)
	{
		if(arr[m]<arr[mid])
			left[leftn++]=arr[m];
		else
			right[rightn++]=arr[m];
	}
	
	quick(left,leftn);
	quick(right,rightn);
	mid=arr[mid];
	arr[leftn]=mid;
	if(leftn!=0)
		memcpy(arr,left,leftn*4);//int 4 byte!!!//int 4 byte!!!//int 4 byte!!!
	if(rightn!=0)
		memcpy(arr+leftn+1,right,rightn*4);//int 4 byte!!!//int 4 byte!!!//int 4 byte!!!//int 4 byte!!!
	free(left);
	free(right);
}