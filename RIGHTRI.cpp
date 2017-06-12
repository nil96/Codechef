#include<stdio.h>
#include<stdlib.h>
struct point
{
   int x;
   int y;
};
void input(struct point *p)
{
    scanf("%d",&p->x);
    scanf("%d",&p->y);
}
long long unsigned int dis(struct point *p1,struct point *p2)
{
  long long unsigned int distance;
  distance=(p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y);
  return distance;
}
int main()
{
  long long unsigned int t,d1,d2,d3,temp,count=0;;
  struct point p1,p2,p3;
  scanf("%lld",&t);
  while(t--)
  {
     input(&p1);
     input(&p2);
     input(&p3);
     d1=dis(&p1,&p2);
     d2=dis(&p1,&p3);
     d3=dis(&p2,&p3);
     if(d1<d2)
     {
       temp=d1;
       d1=d2;
       d2=temp;
     }
     if(d1<d3)
     {
       temp=d1;
       d1=d3;
       d3=temp;
     }
     if(d1==d2+d3)
      count++;
  }
  printf("%lld\n",count);
  return 0;
}