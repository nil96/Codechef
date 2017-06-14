#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define lli long long int
float arr[100060];
float learn[100060];
void intilize()
{
  lli i;
  arr[0]=0;
  for(i=1;i<=100060;i++)
  {
    arr[i]=i*log10(i);
  }
  lli previous=0,current=0;
  learn[0]=0;
  for(current=1;current<100040;current++)
  {
    learn[current]=learn[previous]+arr[current];
    previous=current;
  }
}
lli mypow(lli a,lli b,lli m)
{
  if(b==0)
   return 1;
  lli temp=mypow(a,b/2,m);
  temp=temp%m;
  if(b%2==0)
    return ((temp)*(temp))%m;
 else
   return (((((a)*(temp%m))%m)*(temp%m))%m);
 
}
int main()
{
   intilize();
   lli t;
   lli n,m,q,r;
   lli fn,fr,fn_r;
   scanf("%lld",&t);//cin>>t;
   while(t--)
   {
      scanf("%lld%lld%lld",&n,&m,&q);
      while(q--)
      {
        scanf("%lld",&r);//cin>>r;
        float ans=learn[n]-learn[r]-learn[n-r];
        //printf("n=%lf\n",learn[n]);
        //printf("r=%lf\n",learn[r]);
        //printf("n-r=%lf\n",learn[n-r]);
        lli ans1=ans;
        lli rans=(mypow(10,ans1,m)*    ((lli)(  pow((float)10,(float)(ans-ans1))+0.5 )  %m)     %m);
 
        printf("%lld\n",rans%m);
      }
   }
   return 0;
}