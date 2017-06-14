#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define lli long long int
using namespace std;
struct node
{
  lli pos;
  lli dish;
};
struct node arr[100000];
struct node1
{
   lli pos;
   lli give;
   lli take;
};
struct node1 clans[100000];
lli z;
lli z1;
lli check(lli x)
{
   lli clan_ptr=0;
   lli arr_ptr=0;
   while(arr_ptr<z)
   {
     if(x<0)
       return x;
     if(arr[arr_ptr].pos<clans[clan_ptr].pos)
     {
        x=x-arr[arr_ptr].dish;
        arr_ptr++;
     }
     else
     {
        if(clans[clan_ptr].give<=x)
        {
          x=x+clans[clan_ptr].take;
        }
        clan_ptr++;
     }
   }
    return x;
}
lli binary_search1(lli s,lli e)
{
 
 
  /*for(lli i=e;i>=s;i--)
  {
      if(check(i)==1)
        return i;
  }*/
   while(e>=s)
   {
   //   printf("%lld %lld \n",s,e);
      lli mid=(e+s)/2;
      lli x=check(mid);
     // printf("%lld check(%lld)\n",x,mid);
      if(x==1)
      {
        // printf(" if %lld check(%lld) %lld %lld\n",x,mid,s,e);
        return mid;
      }
      if(x<=0)
        s=mid+1;
     else
       e=mid-1;
   }
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
     lli b;
     lli sum=0;
     scanf("%lld",&b);
     scanf("%lld",&z);
     for(lli i=0;i<z;i++)
     {
        scanf("%lld%lld",&arr[i].pos,&arr[i].dish);
        sum=sum+arr[i].dish;
     }
     arr[z].pos=b+4;
     scanf("%lld",&z1);
     for(lli i=0;i<z1;i++)
     {
        scanf("%lld%lld%lld",&clans[i].pos,&clans[i].give,&clans[i].take);
     }
     clans[z1].pos=b+4;
     lli ans=binary_search1(0,sum+2);
     printf("%lld\n",ans);
  }
  return 0;
}