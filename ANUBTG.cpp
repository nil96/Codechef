#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define lli long long int
vector<long long int> v;
bool cmp(long long int i,long long int j)
{
  return i>j;
}
int main()
{
   long long int t;
   scanf("%lld",&t);
   while(t--)
   {
     v.clear();
     long long int n,temp;
     scanf("%lld",&n);
     for(long long int i=0;i<n;i++)
     {
        scanf("%lld",&temp);
        v.push_back(temp);
     }
     sort(v.begin(),v.end(),cmp);
     long long int x=0,x1=x;
     long long int sum=0;
     while(1)
     {
        x1=x+1;
        if(x<v.size())
          sum=sum+v[x];
        else
          break;
       if(x1<v.size())
         sum=sum+v[x1];
       else
         break;
         x=x+4;
     }
     printf("%lld\n",sum);
 
   }
   return 0;
}
 
 
Comments 
