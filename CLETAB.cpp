#include<stdio.h>
#include<stdlib.h>
#define lli long long int
int find_replace(int *arr,int i,int m,int *a,int n)
{
  int dis[500];
  lli j,k;
  for(j=0;j<500;j++)
   dis[j]=700;
  lli count=0;
  for(k=i+1;k<m;k++)
  {
    if(count<dis[arr[k]])
     dis[arr[k]]=count;
     count++;
  }
  lli z=dis[a[0]],rem=0;
 // printf("dis[%d]=%d\n",a[k],dis[a[k]]);
  for(k=1;k<n;k++)
  {
   // printf("dis[%d]=%d\n",a[k],dis[a[k]]);
    if(z<dis[a[k]])
    {
      z=dis[a[k]];
      rem=k;
    }
  }
  return rem;
}
void print(int *a,int n)
{
  int i;
  for(i=0;i<n;i++)
   printf("%d ",a[i]);
  printf("\n------------------------------------\n");
}
int main()
{
  lli t,n,m,n1,m1;
  scanf("%lld",&t);
  while(t--)
  {
     scanf("%lld%lld",&n,&m);
     n1=n;m1=m;
     lli i=0;
     int arr[10000];
     while(m--)
     {
       scanf("%d",&arr[i]);
       i++;
     }
     //printf("arr------------------------------------\n");
     //print(arr,m1);
     m=m1;
     int a[10000];
     int residing[10000];
     lli l;
     for(l=0;l<10000;l++)
     {
       a[l]=0;
       residing[l]=0;
     }
     lli clean=0;
     lli empty=0;
     i=-1;
     while(m--)
     {