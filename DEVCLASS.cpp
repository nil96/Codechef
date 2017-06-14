#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<limits.h>
#define boy 0
#define girl 1
#define lli long long int
#define inf LONG_LONG_MAX
#define gc() getchar_unlocked()
using namespace std;
char buffer[1000008];
vector<lli> boys;
vector<lli> girls;
void push_in_vector()
{
   boys.clear();
   girls.clear();
   lli l=strlen(buffer);
   for(lli i=0;i<l;i++)
   {
     if(buffer[i]=='B')
     {
       boys.push_back(i);
     }
     else
     {
        girls.push_back(i);
     }
   }
}
lli mod(lli num)
{
  if(num<0)
    return -num;
  return num;
}
lli pow(lli x,lli y)
{
  if(x==0 && y==0)
    return 0;
  if(y==0)
   return 1;
  if(y==1)
   return x;
  return x;
}
lli calculate(lli *arr,lli l,lli cost)
{
    lli sum=0;
    for(lli i=0;i<l;i++)
    {
      sum=sum+pow(mod(arr[i]-i),cost);
    }
    return sum;
}
lli print(lli *arr,lli n)
{
  for(lli i=0;i<n;i++)
  {
    printf("%lld ",arr[i]);
  }
}
lli boom(lli tb,lli tg,lli l,lli cost)//tb==tg
{
//   char temp[1000008];
   lli auxilary_arr[1000008];
   lli bite=0,gite=0;
   for(lli i=0;i<l;i++)
   {
      if(i%2==0)
      {
  //      temp[i]='B';
        auxilary_arr[i]=boys[bite];
        bite++;
      }
      else
      {
    //    temp[i]='G';
        auxilary_arr[i]=girls[gite];
        gite++;
      }
   }
 
   lli m=calculate(auxilary_arr,l,cost);
   /*printf("\nm==%lld\n",m);
   printf("\n--------------\n");
   print(auxilary_arr,l);
   printf("\n----------\n");*/
   bite=0,gite=0;
   for(lli i=0;i<l;i++)
   {
      if(i%2==1)
      {
      //  temp[i]='B';
        auxilary_arr[i]=boys[bite];
        bite++;
      }
      else
      {
        //temp[i]='G';
        auxilary_arr[i]=girls[gite];
        gite++;
      }
   }
   lli n=calculate(auxilary_arr,l,cost);
   /*printf("n==%lld\n",n);
   printf("\n--------------\n");
   print(auxilary_arr,l);
   printf("\n----------\n");*/
   return min(m,n);
}
lli boom1(lli tb,lli tg,lli l,lli cost)
{
   lli arr[1000008];
   lli bite=0,gite=0;
   for(lli i=0;i<l;i++)
   {
     if(i%2==0)
     {
        arr[i]=boys[bite];
        bite++;
     }
     else
     {
       arr[i]=girls[gite];
       gite++;
     }
   }
   return calculate(arr,l,cost);
}
 
 
lli boom2(lli tb,lli tg,lli l,lli cost)
{
   lli arr[1000008];
   lli bite=0,gite=0;
   for(lli i=0;i<l;i++)
   {
     if(i%2==1)
     {
        arr[i]=boys[bite];
        bite++;
     }
     else
     {
       arr[i]=girls[gite];
       gite++;
     }
   }
   return calculate(arr,l,cost);
}
 
 
 
lli oprtn1(lli cost,lli tb,lli tg,lli l)
{
 
 
   if(mod(tb-tg)>1)
     return inf;
 
 
   else
   {
     if(tb==tg)
     {
       //printf("Equal");
       return boom(tb,tg,l,cost)/2;
     }
     else if(tb>tg)
     {
        //printf("tb>tg");
        return boom1(tb,tg,l,cost)/2;
     }
     else if(tb<tg)
     {
        //printf("tb<tg");
        return boom2(tb,tg,l,cost)/2;
     }
   }
 
 
 
}
 
 
 
 
lli oprtn0(char *buffer,lli x,lli count_b,lli count_g,lli l)
{
  //  lli l=strlen(buffer);
    char temp[l+5];
    lli cb=0;
    lli cg=0;
    for(lli i=0;i<l;i++)
    {
       if(i%2==x)
       {
         temp[i]='B';
         cb++;
       }
       else
       {
         temp[i]='G';
         cg++;
       }
    }
    lli count1=0;
    if(cb>count_b || cg>count_g)
      return inf;
    for(lli i=0;i<l;i++)
    {
        if(temp[i]!=buffer[i])
         count1++;
    }
    return count1/2;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli x;
    scanf("%lld",&x);
    gc();
    if(x==2)
     x--;
    scanf("%s",buffer);
    push_in_vector();
    lli tb=0,tg=0;
    lli l=strlen(buffer);
    for(lli i=0;i<l;i++)
    {
      if(buffer[i]=='B')
        tb++;
      else
        tg++;
    }
    if(x==0)
    {
        lli gg=oprtn0(buffer,girl,tb,tg,l);
        lli b=oprtn0(buffer,boy,tb,tg,l);
        lli x=min(gg,b);
        if(x!=inf)
          printf("%lld\n",x);
        else
          printf("-1\n");
    }
    else if(x==1)
    {
      lli flag=oprtn1(x,tb,tg,l);
      if(flag==inf)
        printf("-1\n");
      else
        printf("%lld\n",flag);
    }
  }
  return 0;
}