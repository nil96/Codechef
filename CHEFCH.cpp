#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#define lli long long int
#include<string.h>
using namespace std;
char input[100002];
char x[100002];
char x1[100002];
lli min1(lli x,lli y)
{
  if(x<y)
    return x;
   return y;
}
lli oprtn()
{
   lli l=strlen(input);
 
   for(lli i=0;i<l;i++)
   {
      if(i%2==0)
      {
         x[i]='+';
         x1[i]='-';
      }
      else
      {
         x[i]='-';
         x1[i]='+';
      }
   }
   lli count1=0,count2=0;
   for(lli i=0;i<l;i++)
   {
      if(x[i]!=input[i])
        count1++;
      if(x1[i]!=input[i])
        count2++;
   }
   return min1(count1,count2);
}
int main()
{
  lli t;
  cin>>t;
  while(t--)
  {
    scanf("%s",input);
    getchar_unlocked();
    lli ans=oprtn();
    printf("%lld\n",ans);
  }
  return 0;
}
 