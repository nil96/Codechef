#include<bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
char arr[3][10000];
lli n;
char f(lli x)
{
  if(x==0)
    return '0';
  return '1';
}
lli strng(lli m)
{
   lli c=1;
   for(lli n=strlen(arr[m]),i=n-1;i>=0;i--)
   {
      char temp=arr[m][i]-'0';
      arr[m][i]=f((temp+c)%2);
      c=(temp+c)/2;
      if(c==0)
        break;
   }
   return c;
}
lli count1(char *arr)
{
  lli c=0;
  for(lli n=strlen(arr),i=0;i<n;i++)
  {
    if(arr[i]=='1')
      c++;
  }
  return c;
}
 
 
lli oprtn()
{
  lli c=strng(2);
  if(c==0)
  {
     return count1(arr[0])+n*count1(arr[1])+count1(arr[2]);
  }
  else
  {
     char temp[10000];
     strcpy(temp,arr[1]);
     c=strng(1);
     if(c==0)
     {
        //printf("absorb2\n");
        return count1(arr[0])+count1(arr[1])+(n-1)*count1(temp)+count1(arr[2]);
     }
     else
     {
       //printf("absorb3\n");
       c=strng(0);
       return count1(arr[0])+(n)*count1(arr[1])+count1(arr[2])+c;
     }
  }
  return -1;
}
int main()
{
  lli t;
  scanf("%lld",&t);
  gc();
 
  while(t--)
  {
     scanf("%s",arr[0]);gc();
     scanf("%s",arr[1]);gc();
     scanf("%s",arr[2]);gc();
     scanf("%lld",&n);gc();
     lli ans=oprtn();
     //lli ans=oprtn1();
     printf("%lld\n",ans);
  }
}
 