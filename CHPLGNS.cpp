#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#define lli long long int
using namespace std;
struct perimeter
{
  lli peri;
  lli index;
};
struct perimeter arr[1000000];
struct point
{
   lli x,y;
};
void copy1(struct point *p2,struct point *p1)
{
   p2->x=p1->x;
   p2->y=p1->y;
}
int cmp1(const void *a1,const void*b1)//decreasing
{
   lli a=((struct perimeter *)a1)->peri;
   lli b=((struct perimeter *)b1)->peri;
   if(a>b)
    return 1;
  if(a<b)
    return -1;
  if(a==b)
    return 0;
}
lli ans[100000000];
lli dist(struct point p1,struct point p2)
{
    return p1.x*p2.y-p1.y*p2.x;
}
lli mod(lli x)
{
   if(x<0)
     return -x;
  return x;
}
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
      lli x;
      scanf("%lld",&x);
      for(lli i=0;i<x;i++)
      {
         lli n;
         lli sum=0.0;
         scanf("%lld",&n);
         struct point p1,p2,pr;
         scanf("%lld%lld",&p1.x,&p1.y);
         copy1(&pr,&p1);
         for(lli j=1;j<n;j++)
         {
            scanf("%lld%lld",&p2.x,&p2.y);
            sum=sum+dist(p1,p2);
            //printf("%lld p1.x=%lld p1.y=%lld p2.x=%lld p2.y=%lld\n",dist(p1,p2),
              //          p1.x,p1.y,p2.x,p2.y);
            copy1(&p1,&p2);  //p2=p1
         }
         sum=sum+dist(p2,pr);
         arr[i].peri=mod(sum);
         arr[i].index=i;
      }
 
      /*for(lli i=0;i<x;i++)
      {
        printf("%lld %lld \n",arr[i].peri,arr[i].index);
      }*/
      qsort(arr,x,sizeof(struct perimeter),cmp1);
      /*for(lli i=0;i<x;i++)
      {
        printf("%lld %lld \n",arr[i].peri,arr[i].index);
      }*/
 
 
 
 
      for(lli i=0;i<x;i++)
      {
        ans[arr[i].index]=i;
      }
      for(lli i=0;i<x;i++)
        printf("%lld ",ans[i]);
      printf("\n");
   }
}
 
Submission Info: