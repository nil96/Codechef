#include<stdio.h>
#include<stdlib.h>
long long signed int **a;
long long signed int max(long long signed int a,long long signed int b)
{
  if(a>b)
   return a;
  else
   return b;
}
void print(long long signed int n)
{
   long long signed int i,j;
   for(i=0;i<n;i++)
   {
     for(j=0;j<=i;j++)
        printf("%llu  ",a[i][j]);
     printf("\n");
   }
}
long long signed int f(long long signed int m1)
{
  static long long signed int count=0;
  count++;
  long long unsigned int i,j,m;
  for(i=0;i<m1;i++)
  {
    for(j=0;j<=i;j++)
    {
      if(j==0)
      {
         a[i+1][j]=a[i+1][j]+a[i][j];
      }
      if(j+1<=i)
      {
        m=max(a[i][j],a[i][j+1]);
        a[i+1][j+1]=a[i+1][j+1]+m;
      }
      if(j==i)
      {
        a[i+1][j+1]=a[i+1][j+1]+a[i][j];
      }
    }
  }
}
void input(long long signed int n)
{
   a=(long long signed int**)malloc(n*(sizeof(long long signed int)));
   long long signed int i,j;
   for(i=0;i<n;i++)
   {
     a[i]=(long long signed int*)malloc((i+1)*sizeof(long long signed int));
     for(j=0;j<=i;j++)
      scanf("%llu",&a[i][j]);
   }
}
int main()
{
   long long signed int t,n,i;
   scanf("%llu",&t);
   while(t--)
   {
      scanf("%llu",&n);
      input(n);
      long long signed int k=f(n-1);
      for(i=0;i<n-1;i++)
        free (a[i]);
      k=a[n-1][0];
      for(i=1;i<n;i++)
      {
         if(k<a[n-1][i])
          k=a[n-1][i];
      }
      printf("%llu\n",k);
      free (a[n-1]);
      free (a);
   }
}