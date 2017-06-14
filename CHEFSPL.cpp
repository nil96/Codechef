#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define gc() getchar_unlocked()
char buffer[10000000];
char temp[10000000];
lli check_(char *arr,lli n)
{
   lli i=0,j=0,flag=1;
   while(i<n)
   {
     if(arr[i]=='1')
       i++;
     temp[j++]=arr[i];
     i++;
   }
   n=strlen(temp);
   lli x=(n/2)-1;
   for(lli i=0,j=x+1;i<=x && j<n ;i++,j++)
   {
      if(temp[i]!=temp[j])
      {
        flag=0;
        break;
      }
   }
   return flag;
}
int main()
{
   lli t;
   scanf("%lld",&t);
   gc();
   while(t--)
   {
      scanf("%s",buffer);gc();
      lli n=strlen(buffer);
      lli flag=1;
      if(n%2==0)
      {
        lli x=(n/2)-1;
        for(lli i=0,j=x+1;i<=x && j<n ;i++,j++)
        {
          if(buffer[i]!=buffer[j])
          {
            flag=0;
            break;
          }
        }
      }
      else
      {
        lli flag1[4]={1,1,1,1};
        for(lli i=0,j=n/2+1;i<=n/2 && j<n;i++,j++)
        {
          if(buffer[i]!=buffer[j])
          {
            char m=buffer[i];
            buffer[i]='1';
            flag1[0]=check_(buffer,n);
            buffer[i]=m;
            break;
          }
       }
 
 
       for(lli i=0,j=n/2+1;i<=n/2 && j<n;i++,j++)
       {
         if(buffer[i]!=buffer[j])
         {
            char m=buffer[j];
            buffer[j]='1';
            flag1[1]=check_(buffer,n);
            buffer[j]=m;
            break;
         }
       }
 
 
       for(lli i=0,j=n/2;i<=n/2-1 && j<n;i++,j++)
       {
         if(buffer[i]!=buffer[j])
         {
            char m=buffer[i];
            buffer[i]='1';
            flag1[2]=check_(buffer,n);
            buffer[i]=m;
            break;
         }
       }
 
 
        for(lli i=0,j=n/2;i<=n/2-1 && j<n;i++,j++)
        {
           if(buffer[i]!=buffer[j])
            {
              char m=buffer[j];
              buffer[j]='1';
              flag1[3]=check_(buffer,n);
              buffer[j]=m;
              break;
           }
        }
        flag=flag1[0] || flag1[1] || flag1[2] || flag1[3];
      //  for(lli i=0;i<4;i++)
        // printf("flag1[%lld]=%lld\n",i,flag1[i]);
        if(n==1)
          flag=0;
 
 
 
 
 
 
 
 
     }
      if(flag==0)
       printf("NO\n");
      else
       printf("YES\n");
   }
   return 0;
}
 