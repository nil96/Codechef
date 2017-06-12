#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define lli long long int
using namespace std;
vector<lli> v;
lli sum[1000000];
lli cmp(lli x,lli y)
{
   return x>y;
}
lli binary_search(lli s,lli e,lli m,lli num)
{
   while(s!=e  && s<e)
   {
     lli mid=(s+e)/2;
    // printf("s==%lld e==%lld\n",s,e);
     if(v[mid]-num<m)
       s=mid+1;
     else
       e=mid-1;
  //  printf("ss==%lld ee==%lld\n",s,e);
   }
   return s;
}
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
     lli n,m,temp;
     v.clear();;
     scanf("%lld%lld",&n,&m);
     for(lli i=0;i<n;i++)
     {
        scanf("%lld",&temp);
        v.push_back(temp);
     }
     sum[0]=0;
     for(lli i=0;i<n;i++)
         sum[i]=0;
     lli sum1=0;  
     sort(v.begin(),v.end(),cmp);
    //  for(lli i=0;i<n;i++) 
      // printf("%lld ",v[i]) ;*/   
     for(lli i=0,j=1;i<n && j<n;)
     {
        if(v[i]-v[j]<m)
        {
           //printf("\n%lld -%lld<%lld\n",v[i],v[j],m);
           sum1=sum1+v[j]+v[i];
           i=j+1;
           j=i+1;
        }
        else
        {
          i=j;
          j=i+1;
        }
     }     
     printf("%lld\n",sum1);   
   }
   return 0;
}
 
Comments 
