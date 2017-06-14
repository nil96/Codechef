#include<stdio.h>
#include<stdlib.h>
#define lli long long int
lli arr[100080];
lli prime[10000];
void print(lli *arr,lli x)
{
  lli i;
  for(i=0;i<x;i++)
   printf("%lld ",arr[i]);
   printf("\n");
}
lli input(lli n)
{
  lli i=0;
  for(i=0;i<n;i++)
    scanf("%lld",&arr[i]);
}
lli prime1(lli from ,lli to)
{
 lli i,j,k=0;
 lli *sieve=(lli *)calloc(to+1,sizeof(lli));
 for(i=2;i<=to;i++)
    {
        if(sieve[i]==0)
        {
            if(i>=from)
            {
                prime[k]=i;
                k++;
            }
            if(i*i<=to)
            {
                for(j=i;j<=to;j+=i)
                {
                    sieve[j]=1;
                }
            }
        }
    }
    return k-1;
 
}
lli fac(lli num,lli k,lli *k1)
{
  lli count=0;
  while(num%k==0)
  {
     count++;
     num=num/k;
     *k1=num;
  }
  return count;
}
lli op(lli *arr,lli n,lli k,lli *flag1,lli *ans)
{
  lli i,flag=0,zount=0;
  lli zount1=0;
  for(i=0;i<n;i++)
  {
    //printf("arr[%lld]==%lld\n",i,arr[i]);
    if(arr[i]==1)
    {
      (*flag1)++;
      continue;
    }
    if(arr[i]%k==0 && arr[i]!=0)
    {
      lli k1=1;
      //printf("arr[%lld]=%lld k==%lld k1==%lld\n",i,arr[i],k,k1);
      zount=fac(arr[i],k,&k1);
     // printf("zount==%lld\n",zount);
      arr[i]=k1;
      if(zount1<zount)
      {
        zount1=zount;
      }
      flag=1;
    }
  }
  *ans=*ans+zount1;
  return flag;
}
 
lli operation(lli n,lli l)
{
  lli count=0,i=0,ans1=0;
  while(1)
  {
    lli flag1=0,flag=1;
    flag=op(arr,n,prime[i],&flag1,&ans1);
     //print(arr,n);
    if(flag1==n)
      break;
     i++;
  }
  return ans1;
}
int main()
{
  lli t;
  lli l=prime1(2,1000080);
  scanf("%lld",&t);
  while(t--)
  {
    lli n;
    scanf("%lld",&n);
    input(n);
    lli ans=operation(n,l);
    printf("%lld\n",ans);
  }
  return 0;
}
 