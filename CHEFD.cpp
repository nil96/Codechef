#include<stdio.h>
#include<stdlib.h>
#define lli long long int
lli arr[100004];
lli input(lli n)
{
  lli i=0;
  for(i=1;i<=n;i++)
    scanf("%lld",&arr[i]);
}
void div1(lli l, lli r,lli m)
{
  lli i;
  for(i=l;i<=r;i++)
  {
     if(arr[i]%m==0)
     {
       arr[i]=arr[i]/m;
     }
  }
}
void print(lli *arr,lli x)
{
  lli i;
  for(i=1;i<=x;i++)
   printf("%lld ",arr[i]);
   printf("\n");
}
int main()
{
  lli t,n,count=0;
  scanf("%lld",&n);
  input(n);
  scanf("%lld",&t);
  while(t--)
  {
     lli c;
     scanf("%lld",&c);
     if(c==1)
     {
       lli l,r,m;
       scanf("%lld%lld%lld",&l,&r,&m);
       div1(l,r,m);
      /* printf("%lld\n---------------\n",count++);
       print(arr,n);
        printf("\n---------------\n");*/
     }
     else if(c==2)
     {
        lli z1,z2;
        scanf("%lld%lld",&z1,&z2);
        arr[z1]=z2;
     }
  }
  print(arr,n);
}
 