//Polo the Penguin and the Numbers
 
//open the printf that are commented may help u to understand the discretizing the interval()
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define lli long long int
#define mod  1000000007
lli c[]={0,9,99,999,9999,99999,999999,9999999,99999999};
int find_digit(lli a) // function return the number of digit present in number eg:-  find_digit(100) reurn 3 find_digit(10000) rtn4
{
  lli i,j=0,k,rem;
  while(a!=0)
  {
     a=a/10;
     j++;
  }
  return j;
}
int main()
{
  lli a,b,t,diga,digb,ans,n,ans1,i;
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld%lld",&a,&b);
    //scanf("%lld",&a);
    diga=find_digit(a);// finding number of digit
    //printf("diga====%lld\n",diga);
    digb=find_digit(b);// finding number of digi
    //printf("digb====%lld\n",digb);
    if(digb==diga)//if equal
    {
      //printf("diga=====digb\n");
      n=b-a+1;// no of terms present btwn two number
      ans1=(n*(2*a+n-1)*diga)/2;// simple A.P(arithmatic progression)*diga
      ans1=ans1%mod;
    }
    else if(diga!=digb)// if not same discretizing the interval eg 2-1001 then interval are (2,9),(10,999)
    {
      i=diga;
      ans=0;
      while(i<digb)
      {
        n=c[i]-a+1;
        //printf("sum is found btween %lld---%lld  diga====%lld\n",a,c[i],diga);
        i++;
        ans=ans+(n*(2*a+n-1)*diga)/2;
        ans=ans%mod;
        diga++;
        a=c[i-1]+1;
      }
       n=b-(c[i-1]+1)+1;//discretizing last inteval explicitly(1000,10001)
      // printf("last sum is found btween %lld---%lld digb====%lld\n",c[i-1]+1,b,digb);
       ans1=(n*(2*(c[i-1]+1)+n-1)*digb)/2;
       ans1=ans1%mod;
       ans1=ans1+ans;//adding two result explicit +loop
       ans1=ans1%mod;
    }
     printf("%lld\n",ans1);//print answer
  }
}