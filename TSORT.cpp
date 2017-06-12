#include<stdio.h>
#include<stdlib.h>
#define lli long long int
lli input[1000005];
int main()
{
  lli t,temp,z;
  scanf("%lld",&t);
  z=t;
  lli i;
  for(i=0;i<1000005;i++)
    input[i]=0;
  while(t--)
  {
     scanf("%lld",&temp);
     input[temp]++;
  }
  lli k=0;
  for(i=0;i<=1000003;i++)
  {
    if(input[i]==0)
      continue;
    else
    {
      lli j;
      for(j=input[i];j>0;input[i]=input[i]-1,j=input[i])
      {
         printf("%lld\n",i);
         k++;
         if(k==z)
          break;
      }
    }
  }
  return 0;
}