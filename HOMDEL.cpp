#include<stdio.h>
#include<stdlib.h>
#define lli long long int
#define infinity 10000000000000
struct node
{
  lli dis;
  lli mark;
};
struct node *sol[252];
lli graph[252][252];/*{0,10,3,110,110,
                 110,0,1,2,110,
                 110,4,0,8,2,
                 110,110,110,0,7,
                 110,110,110,9,0,
                 };
/*void print(lli n,struct node *x)
{
 lli i;
 for(i=0;i<n;i++)
    printf("%lld ",x[i].dis);
 printf("\n");
 for(i=0;i<n;i++)
   printf("%lld ",x[i].mark);
  printf("\n");
 
}
void print1(lli source,lli n)
{
 lli i;
 for(i=0;i<n;i++)
    printf("%lld ",graph[source][i]);
 printf("\n");
}
 
void print2(lli n)
{
  lli i,j;
  struct node *x;
  for(i=0;i<n;i++)
  {
     x=sol[i];
    printf("solution[%lld]==",i);
    for(j=0;j<n;j++)
       printf("%lld  ",x[j].dis);
    printf("\n");
  }
}*/
 
lli load (struct node *x,lli source,lli n,lli l)
{
  lli temp=infinity,i,z=infinity;
  for(i=0;i<n;i++)
  {
    if(x[i].mark==1)
    {
      //printf("continue exist\n");
      continue;
    }
    else if(x[i].mark!=1)
    {
      if(x[i].dis>l+graph[source][i])
          x[i].dis=l+graph[source][i];
      if(temp>x[i].dis)
      {
        temp=x[i].dis;
        z=i;
      }
    }
  }
  return z;
}
void intilize(struct node *x,lli n)
{
  lli i;
  for(i=0;i<n;i++)
   x[i].dis=infinity;
}
lli dijkitras(lli source,lli n)//n=maximum node value
{
  lli k=0,l=0;
  sol[source]=(struct node*)calloc(n,sizeof(struct node));
  struct node *x=sol[source];
  intilize(x,n);
  x[source].dis=0;
  while(1)
  {
 
      k++;
      x[source].mark=1;//all mark is intilized to 1?????instead of of first mark
      source=load(x,source,n,l);
      if(source==infinity)
      {
        break;
      }
      if(k==n)
      {
         break;
      }
      l=x[source].dis;
  }
}
void input(lli n)
{
  lli i,j;
  for(i=0;i<n;i++)
  {
     for(j=0;j<n;j++)
     scanf("%lld",&graph[i][j]);
  }
}
 
void print2(lli n)
{
  lli i,j;
  struct node *x;
  for(i=0;i<n;i++)
  {
     x=sol[i];
    printf("solution[%lld]==",i);
    for(j=0;j<n;j++)
       printf("%lld  ",x[j].dis);
    printf("\n");
  }
}
 
 
lli distance(lli source,lli end)
{
   struct node *x;
   x=sol[source];
   return x[end].dis;
}
 
int main()
{
   lli i,n,m,s,g,d;
   scanf("%lld",&n);
   input(n);
   for(i=0;i<n;i++)
      dijkitras(i,n);
   //print2(n);
   scanf("%lld",&m);
   while(m--)
   {
       scanf("%lld",&s);
       scanf("%lld",&g);
       scanf("%lld",&d);
       lli dis1,dis2;
       dis1=distance(s,g);
       dis1=dis1+distance(g,d);
       dis2=distance(s,d);
       printf("%lld %lld\n",dis1,dis1-dis2);
   }
}