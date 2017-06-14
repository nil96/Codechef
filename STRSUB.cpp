#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
vector<char> v;
vector<lli> c0;
vector<lli> c1;
void preprocess()
{
   lli c_0=0,c_1=0;
   for(lli i=0;i<v.size();i++)
   {
      if(v[i]=='0')
        c_0++;
      else
       c_1++;
       c0.push_back(c_0);
       c1.push_back(c_1);
   }
}
void number_of(lli ss,lli se,lli *x,lli *y)
{
    if(ss-1>=0)
    {
      (*x)=c0[se]-c0[ss-1];
      (*y)=c1[se]-c1[ss-1];
    }
    else
    {
      *x=c0[se];
      *y=c1[se];
    }
}
lli mod(lli x)
{
  if(x<0)
    return -x;
  return x;
}
lli oprtn(lli li,lli qi,lli k)
{
   lli sum=0;
   lli count_0=0,count_1=0;
   for(lli i=li;i<=qi;i++)
   {
      for(lli j=i;j<=qi;j++)
      {
        if(mod(i-j+1)>2*k)
          break;
        number_of(i,j,&count_0,&count_1);
        if(count_0<=k && count_1 <=k)
         sum++;
        count_0=0;count_1=0;
      }
   }
   return sum;
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
      lli n,k,q;
      v.clear();
      c0.clear();
      c1.clear();
      scanf("%lld%lld%lld",&n,&k,&q);
      gc();
      //printf("%lld%lld%lld\n",n,q,k);
      for(lli i=0;i<n;i++)
      {
         char temp=gc();
       //  printf("temp==%c %lld\n",temp,i);
         v.push_back(temp);
      }
      preprocess();
      lli li,ri;
      for(lli i=0;i<q;i++)
      {
        scanf("%lld%lld",&li,&ri);
        lli ans=oprtn(li-1,ri-1,k);
       // printf("oooooooooooooo\n");
        printf("%lld\n",ans);
      }
   }
   return 0;
}