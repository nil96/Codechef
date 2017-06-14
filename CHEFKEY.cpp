#include<bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> s1;
lli Sqrt(float x) {
  float z=x;
  float xhalf = 0.5f * x;
  int i = *(int*)&x;         // evil floating point bit level hacking
  i = 0x5f3759df - (i >> 1);  // what the fuck?
  x = *(float*)&i;
  x = x*(1.5f-(xhalf*x*x));
  z=x*z+1;
  return (lli) z;
}
void fillset1(vector<lli> &s,lli num)
{
   s.clear();
   lli n=sqrt(num)+1;
 //  printf("n====%lld\n",n);
   for(lli i=1;i<n;i++)
   {
     if(num%i==0 && i*i!=num)
     {
       s.push_back(i);
       s.push_back(num/i);
     }
     else if(num%i==0 && i*i==num)
     {
        s.push_back(i);
     }
   }
}
 
 
 
 
int main()
{
   lli t;
   scanf("%lld",&t);
   //t=1;
   while(t--)
   {
     lli n,m,c;
      scanf("%lld%lld%lld",&n,&m,&c);
      if(n<m)//n>=m
        swap(n,m);
      fillset1(s1,c);
      lli ans=0;
      for(lli i=0;i<s1.size();i++)
      {
         if(s1[i]<=n && c/s1[i]<=m)
           ans++;
 
      }
      printf("%lld\n",ans);
   }
   return 0;
}