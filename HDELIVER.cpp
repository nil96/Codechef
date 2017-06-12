#include<stdio.h>
#include<stdlib.h>
int graph[100];
void intilize(int n)
{
  int i;
  for(i=0;i<=n;i++)
   graph[i]=i;
}
int connect(int a,int b,int n)
{
  if(graph[a]==graph[b])
   return 0;
  int temp=graph[a];
  int i;
  for(i=0;i<=n;i++)
  {
    if(temp==graph[i])
    {
      graph[i]=graph[b];
    }
  }
}
int query(int a,int b)
{
  if(graph[a]==graph[b])
    return 1;
  else
    return 0;
}
int main()
{
  int t,N,m,q,flag,a,b,i;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&N);
    intilize(N);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
      scanf("%d%d",&a,&b);
      connect(a,b,N);
    }
    scanf("%d",&q);
    while(q--)
    {
       scanf("%d%d",&a,&b);
       flag=query(a,b);
       if(flag==1)
        printf("YO\n");
       else
       printf("NO\n");
 
    }
  }
}