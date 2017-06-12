#include<bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
int arr[1000][1000];
int can_flow_r8(int i,int j,int n,int m)
{
  if(j==m-1)
    return 0;
  if(arr[i][j+1]=='A')
   return 0;
  return 1;
}
int can_flow_lft(int i,int j,int n,int m)
{
  if(j==0)
    return 0;
  if(arr[i][j-1]=='A')
   return 0;
  return 1;
}
int can_flow_dwn(int i,int j,int n,int m)
{
  if(i==n-1)
    return 1;
  if(arr[i+1][j]=='A')
   return 0;
  return 1;
}
int will_fall(int i,int j,int n,int m)
{
   if(i==n-1)
     return 1;
   if(arr[i+1][j]=='A' || arr[i+1][j]=='W')
     return 0;
   return 1;
}
int main()
{
   int t;
   scanf("%d",&t);gc();
   while(t--)
   {
      lli n,m;
      scanf("%lld%lld",&n,&m);gc();
      for(int i=0;i<n;i++)
      {
         for(int j=0;j<m;j++)
         {
           arr[i][j]=gc();
 //          printf("arr[%d][%d]=%c\n",i,j,arr[i][j]);
         }
         gc();
      }
     /* for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          printf("%c",arr[i][j]);
        }
        printf("\n");
      }*/
      int flag=1;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
           if(arr[i][j]=='W')
           {
              int x=1;
              x = x & can_flow_r8(i,j,n,m);
             // printf("can_flow_r8==%d\n",can_flow_r8(i,j,n,m));
              x = x & can_flow_lft(i,j,n,m);
              //printf("can_flow_lft==%d\n",can_flow_lft(i,j,n,m));
              x = x & can_flow_dwn(i,j,n,m);
              //printf("can_flow_dwn==%d\n",can_flow_dwn(i,j,n,m));
              if(x==0)
              {
                flag=0;
              }
           }
           if(arr[i][j]=='B')
           {
             int x=will_fall(i,j,n,m);
             if(x==0)
             {
                flag=0;
             }
           }
 
 
        }
      }
      if(flag==0)
        printf("no\n");
      else
        printf("yes\n");
   }
}