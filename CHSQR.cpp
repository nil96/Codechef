#include<bits/stdc++.h>
#define lli long long int
using namespace std;
lli arr[410][410];
lli dist(lli m,lli x,lli y)
{
  return abs(m-x)+abs(m-y);
}
void init1(lli k)
{
  for(lli i=0;i<k+2;i++)
    for(lli j=0;j<k+2;j++)
       arr[i][j]=-1;
}
void print(lli k)
{
  for(lli i=0;i<k;i++)
  {
     for(lli j=0;j<k;j++)
     {
       printf("%lld ",arr[i][j]);
     }
     printf("\n");
  }
}
void fill_colm(lli r,lli c,lli k,lli num)
{
   for(lli i=0;i<k;i++)
   {
     lli r1=(r+i)%k;
     if(arr[r1][c]==-1)
     {
        arr[r1][c]=num++;
        num=num%(k+1);
        if(num==0)
         num=1;
     }
   }
}
void fill1(lli x,lli y,lli k)
{
   //printf("x====%lld y====%lld\n",x,y);
   //arr[x][y]=1;
   for(lli i=0;i<k;i++)
   {
        fill_colm((x)%k,(y+i)%k,k,i+1);
   }
 
}
int main()
{
    lli t;
    scanf("%lld",&t);
    while(t--)
    {
       lli k;
       scanf("%lld",&k);
       init1(k-1);
       lli mid=k%2==0?k/2:(k+1)/2;
       lli d=-1,x=mid,y=mid;
       if(dist(mid,k+1,1)>d)
       {
          x=1;
          y=k;
          d=dist(mid,k+1,1);
       }
       if(dist(mid,1,k+1)>d)
       {
          x=1;
          y=1;
          d=dist(mid,1,k+1);
       }
       if(dist(mid,1,k-1)>d)
       {
          x=k;
          y=1;
          d=dist(mid,1,k-1);
       }
       if(dist(mid,k-1,1)>d)
       {
          x=k;
          y=k;
          d=dist(mid,k-1,1);
       }
       fill1(mid-1,k-1,k);
       print(k);
    }
    return 0;
}
 