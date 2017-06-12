#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define lli long long int
#define gc() getchar_unlocked()
char matrix[100][100];
using namespace std;
void input(lli row,lli colm)
{
  for(lli i=0;i<row;i++)
  {
    for(lli j=0;j<colm;j++)
    {
      char c=gc();
      matrix[i][j]=c;
    }
    gc();
  }
}
void print(lli row,lli colm)
{
   for(lli i=0;i<row;i++)
   {
    for(lli j=0;j<colm;j++)
    {
      printf("%c",matrix[i][j]);
    }
    printf("\n");
  }
}
lli check_right(lli i,lli j,lli row,lli colm)
{
  if(j+1>=colm || j+2>=colm || matrix[i][j+1]=='#' || matrix[i][j+2]=='#')
   return 0;
  return 1;
}
 
 
lli check_left(lli i,lli j,lli row,lli colm)
{
  if(j-1<0 || j-2<0 || matrix[i][j-1]=='#' || matrix[i][j-2]=='#')
   return 0;
  return 1;
}
 
lli check_up(lli i,lli j,lli row,lli colm)
{
  if(i-1<0 || i-2<0 || matrix[i-1][j]=='#' || matrix[i-2][j]=='#')
   return 0;
  return 1;
}
 
 
 
lli check_down(lli i,lli j,lli row,lli colm)
{
  if(i+1>=row || i+2>=row || matrix[i+1][j]=='#' || matrix[i+2][j]=='#')
   return 0;
  return 1;
}
 
lli oprtn(lli row ,lli colm)
{
  lli ans=0;
  for(lli i=0;i<row;i++)
  {
    for(lli j=0;j<colm;j++)
    {
 
      if(matrix[i][j]=='^')
      {
         lli x0=check_right(i,j,row,colm);
         lli x1=check_left(i,j,row,colm);
         lli x2=check_up(i,j,row,colm);
         lli x3=check_down(i,j,row,colm);
         ans=ans+x0*x1*x2*x3;
      }
 
 
    }
  }
  printf("%lld\n",ans);
}
int main()
{
  lli t;
  scanf("%lld",&t);
  gc();
  while(t--)
  {
    lli row,colm;
    scanf("%lld%lld",&row,&colm);
    gc();
    input(row,colm);
    oprtn(row,colm);
  }
  return 0;
}
 
 