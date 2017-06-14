#include<bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
#define num 1000000
#define usefull 1
#define useless 2
using namespace std;
lli arr[10000000];
lli ans[10000000];
vector<lli> p;
lli readlli()
{
    lli cc = getc(stdin);
    for (;cc < '0' || cc > '9';)
            cc = getc(stdin);
    lli ret = 0;
    for (;cc >= '0' && cc <= '9';)
    {
            ret = ret * 10 + cc - '0';
            cc = getc(stdin);
    }
    return ret;
}
lli init()
{
    lli m=(5000000)+1;
    for(lli i=0;i<m;i++)
    {
      arr[i]=1;
      ans[i]=useless;
    }
    arr[0]=0;
    arr[1]=0;
    p.clear();
    for(lli i=2;i<=(lli)sqrt(m)+1;i++)
    {
       if(arr[i]==1)
       {
          if((i-1)%4==0)
            ans[i]=usefull;
          for(lli j=i+i;j<m;j=j+i)
          {
             arr[j]=0;
             if((i-1)%4==0)
             {
               ans[j]=usefull;
             }
          }
       }
    }
 
    for(lli i=sqrt(m);i<m;i++)
    {
       if(arr[i]==1)
       {
          if((i-1)%4==0)
          {
            ans[i]=usefull;
            for(lli j=i+i;j<m;j=j+i)
            {
              ans[j]=usefull;
            }
          }
       }
    }
 
    for(lli i=0;i<m;i++)
    {
       if(arr[i]==1)
        p.push_back(i);
    }
   // printf("ax====%lld \n",arr[2499997]);
}
lli fun(lli n)
{
     for(lli i=0;i<p.size();i++)
     {
        if(n<p[i])
          break;
        if(n%p[i]==0)
        {
          if((p[i]-1)%4==0)
            return 1;
          while(n%p[i]==0)
            n=n/p[i];
        }
     }
     if(n==1)
       return 0;
     if((n-1)%4==0)
       return 1;
    return 0;
}
int main()
{
   init();
   lli t;
   t=readlli();
   for(lli i=0;i<t;i++)
   {
      lli n;
      n=readlli();
      //lli flag=fun(n);
      if(ans[n]==usefull)
       printf("YES\n");
     else
       printf("NO\n");
   }
   return 0;
}