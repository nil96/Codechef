#include <bits/stdc++.h>
#define lli long long int
#define lmt 100000
//#define lmt 5
using namespace std;
lli n,m,c;
int b[100][100];
void inc(lli *i,lli *j)
{
 
   *j=*j+1;
   if(*j>=m)
   {
      *j=0;
      *i=*i+1;
   }
   if(*i>=n)
   {
     *i=-1;*j=-1;
   }
   return;
}
lli check(lli x,lli y)
{
  if(x==-1 || y==-1)
    return 0;
  return 1;
}
int main()
{
  fflush(stdin);
  scanf("%lld%lld%lld",&n,&m,&c);
  fflush(stdin);
  int arr[n+2][m+2];
   lli il=0,ir=0,jl=0,jr=0;
  lli filled=0,x;
  for(lli i=0;i<n;i++)
  {
    for(lli j=0;j<m;j++)
    {
      arr[i][j]=-1;
    }
  }
 
  while(c>0)
  {
    c--;
    if(check(il,jl)==0)
        break;
    if(arr[il][jl]==-1)
    {
      fflush(stdout);
      printf("2 %lld %lld %lld %lld\n",il+1,ir+1,jl+1,jr+1);
      fflush(stdout);
      fflush(stdin);
 
      scanf("%lld",&x);
      arr[il][jl]=x;
      filled++;
      inc(&il,&jl);
      if(check(il,jl)==0)
        break;
      ir=il;
      jr=jl;
    }
 
  }
  lli xcc=0;
  
 
  for(lli i=0;i<n;i++)
  {
    for(lli j=0;j<m;j++)
    {
        if(arr[i][j]==-1)
        {
          for(lli k=1;k<=50;k++)
          {
            fflush(stdout);
            printf("1 %lld %lld %lld %lld %lld %lld\n",i+1,i+1,j+1,j+1,k,k);
            fflush(stdout);
            filled++;
            if(filled>lmt)
               break;
            lli x;
            fflush(stdin);
            scanf("%lld",&x);
            fflush(stdin);
            if(x==1)
            {
              arr[i][j]=k;
              break;
            }
          }
 
        }
    }
  }
 
 
 
 
 
 
  /*while(check(il,jl)!=0 || filled<=lmt)
  {
      if(check(il,jl)==0)
        break;
      if(arr[il][jl]==-1)
      {
         lli l=1,r=50;
         while(l!=r && l<r)
         {
           lli m=(l+r)/2;
           if(l==m || r==m)
           {
              printf("1 %lld %lld %lld %lld %lld %lld\n",il+1,ir+1,jl+1,jr+1,l,l);
              fflush(stdout);
              lli x;
              fflush(stdin);
              scanf("%lld",&x);
              if(x==1)
              {
                arr[il][jl]=l;
              }
              else
              {
                arr[il][jl]=r;
              }
              break;
           }
           else
           {
               printf("1 %lld %lld %lld %lld %lld %lld\n",il+1,ir+1,jl+1,jr+1,l,m);
               fflush(stdout);
               lli x;
               fflush(stdin);
               scanf("%lld",&x);
               if(x==0)
               {
                 l=m;
               }
               else
               {
                 r=m;
               }
           }
         }
      }
      inc(&il,&jl);
      ir=il;
      jr=jl;
      filled++;
  }
  for(lli i=0;i<n;i++)
  {
    for(lli j=0;j<m;j++)
      arr[i][j]=25;
  }*/
  while(check(il,jl)!=0)
  {
    if(arr[il][jl]==-1)
    {
      arr[il][jl]=25;
    }
    inc(&il,&jl);
    ir=il;
    jr=jl;
  }
  fflush(stdout);
  printf("3\n");
  fflush(stdout);
  for(lli i=0;i<n;i++)
  {
    for(lli j=0;j<m;j++)
    {
      fflush(stdout);
      printf("%d ",arr[i][j]);
      fflush(stdout);
    }
    printf("\n");
  }
  return 0;
}
 
Comments 
