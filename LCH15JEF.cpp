#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#define lli long long int
using namespace std;
char buffer[100001];
vector<lli> stack1;
lli pow(lli x,lli y,lli m)
{
  x=x%m;
  if(y==0)
    return 1;
  lli z=pow(x,y/2,m);
  z=z%m;
  if(y%2==0)
    return (z*z)%m;
  else
    return (((x*z)%m)*z)%m;
}
void reverse1(char *buffer)
{
   lli n=strlen(buffer);
   lli i=0;
   lli j=n-1;
   while(i<j)
   {
     swap(buffer[i],buffer[j]);
     i++;
     j--;
   }
}
void preprocess(char *arr)
{
  lli n=strlen(arr);
  for(lli i=0;i<n-1;i++)
  {
    if(arr[i]=='*' && arr[i+1]=='*')
    {
      arr[i]='e';
      arr[i+1]='^';
    }
  }
}
lli oprtn(char *arr,lli m)
{
    stack1.clear();
    lli num=1;
    preprocess(arr);
 //   printf("\nbook\n%s \n",arr);
    lli n=strlen(arr);
    for(lli i=n-1;i>=0;i--)
    {
      if(num==1)
      {
        char buffer[1000];
        lli j=0;
        while(1)
        {
          buffer[j]=arr[i];
          i--;
          j++;
          if(i<0 || arr[i]=='*' || arr[i]=='^' || arr[i]=='e')
           break;
        }
        buffer[j]='\0';
        reverse1(buffer);
        //printf("\nbuff %s\n",buffer);
        num=atoi(buffer);
        if(i<0)
        {
         stack1.push_back(num);
         break;
        }
        //printf("%lld (1)num==%lld\n",i,num);
      }
      if(i<0)
      {
        stack1.push_back(num);
        break;
      }
      if(arr[i]=='e')
      {
         //printf("i===%lldee\n",i);
        char buffer[1000];
        lli j=0;
        while(1)
        {
          buffer[j]=arr[i];
          i--;
          j++;
          if(i<0 || arr[i]=='*' || arr[i]=='^' || arr[i]=='e')
          {
         //  printf("i==%lld\n",i);
           break;
          }
        }
        buffer[j]='\0';
        reverse1(buffer);
        lli num1=atoi(buffer);
        num=pow(num1,num,m);
       // printf("i==%lld e==%lld\n",i,num);
        if(i<0)
        {
         stack1.push_back(num);
         break;
        }
      }
      if(arr[i]=='*')
      {
   //      printf("i==%lld**\n",i);
         stack1.push_back(num);
     //    printf("bull%lld ",stack1[stack1.size()-1]);
         num=1;
      }
    }
    lli num2=1;
//    printf("\ns\n\n");
    for(lli i=0;i<stack1.size();i++)
    {
  //    printf("%lld  ",stack1[i]);
      num2=(num2*stack1[i])%m;
    }
    return num2;
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli m;
    scanf("%lld",&m);
    getchar_unlocked();
    scanf("%s",buffer);
    getchar_unlocked();
    lli ans=oprtn(buffer,m);
    printf("%lld\n",ans);
  }
 return 0;
}