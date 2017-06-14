#include<stdio.h>
#include<stdlib.h>
#define lli long long int
lli arr[20000];
lli count1=0,flag=0;
int cmp(const void * a, const void * b)
{
  if ( *(lli*)a <*(lli*)b ) return -1;
  if ( *(lli*)a==*(lli*)b ) return 0;
  if ( *(lli*)a >*(lli*)b ) return 1;
}
lli bum[10000];
lli oprtn(lli *arr,lli n,lli k,lli sum,lli ite,lli depth,lli bum_s)
{
  if(depth==1 && ite>0)
  {
   //printf("flag===0\n");
  arr[ite-1]=0;
   flag=0;
  }
  if((flag==1 && depth>0)  && ite>0)
  {
    arr[ite-1]=0;
    //printf("arr[%lld]===%lld depth==%lld\n",ite-1,arr[ite-1],depth);
    return 0;
  }
  if(sum==k && ite>0)
  {
    //printf("depth===%lld\n",depth);
    //printf("ite============%lld\n",ite-1);
    arr[ite-1]=0;
   // printf("arr[%lld]=====%lld\n",ite-1,arr[ite-1]);
    count1++;
    //printf("\n----------------------------\n");
    flag=1;
     return 0;
  }
  else
  {
    lli i;
    //if(ite<n && sum+arr[ite]<=k)
    {
      for(i=ite;i<n;i++)
      {
        // bum[bum_s]=arr[i];
       //  bum_s++;
         //printf("%lld  %lld\n",sum+arr[i],depth);
         oprtn(arr,n,k,sum+arr[i],i+1,depth+1,bum_s);
         if(flag==1 && depth>0)
           return 1;
      }
    }
  }
  return 1;
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli n,k,i;
    scanf("%lld%lld",&n,&k);
    lli sum=0;
    for(i=0;i<n;i++)
    {
       scanf("%lld",&arr[i]);
       sum=sum+arr[i];
    }
    qsort(arr,n,sizeof(lli),cmp);
    count1=0,flag=0;
    //printf("arr[2]====%lld\n",arr[2]);
    if(sum%k==0)
    {
      lli k1=sum/k;
      oprtn(arr,n,k1,0,0,0,0);
     // printf("count===%lld k1==%lld\n",count1,k1);
      if(count1>=k)
      {
         printf("yes\n");
      }
      else
      {
         printf("no\n");
      }
    }
    else
    {
      printf("no\n");
    }
  }
  return 0;
}
 