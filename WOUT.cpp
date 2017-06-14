#include<stdio.h>
#include<stdlib.h>
//#include<iostream>
//#include<algorithm>
#define lli  int
#define gc getchar_unlocked
//using namespace std;
lli seg[10000000];
lli arr[1000000];
lli read_lli() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  lli ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
lli create(lli* arr,lli s,lli e,lli ite)
{
    if(s==e)
    {
        seg[ite]=arr[s];
        return seg[ite];
    }
    lli mid=(s+e)/2;
    seg[ite]=create(arr,s,mid,2*ite+1)+create(arr,mid+1,e,2*ite+2);
    return seg[ite];
}
lli max1(lli a,lli b)
{
  if(a<b)
   return b;
  return a;
}
lli min1(lli a,lli b)
{
  if(a<b)
   return a;
  return b;
}
lli update(lli *arr,lli s,lli e,lli qs,lli qe,lli index)
{
  lli sp=max1(s,qs);
  lli ep=min1(e,qe);
  lli x;
  if(ep-sp>=0)
     x=ep-sp;
  else
    return 0;
  seg[index]=seg[index]-(x+1);
  if(s!=e)
  {
     lli mid=(s+e)/2;
     update(arr,s,mid,qs,qe,2*index+1);
     update(arr,mid+1,e,qs,qe,2*index+2);
  }
}
lli sum(lli ss,lli se,lli qs,lli qe,lli ite)
{
  if(qs<=ss && qe>=se)
    return seg[ite];
  if(se<qs || ss>qe)
    return 0;
  lli mid=(ss+se)/2;
  return sum(ss,mid,qs,qe,2*ite+1)+sum(mid+1,se,qs,qe,2*ite+2);
}
void intilize(lli n)
{
   lli i;
   for(i=0;i<n;i++)
     arr[i]=n;
   //arr[0]=1, arr[1]=3, arr[2]=5, arr[3]=7, arr[4]=9, arr[5]=11;
   create(arr,0,n-1,0);
}
int main()
{
   lli t,i;
   t=read_lli();
   while(t--)
   {
     lli n,x;
     n=read_lli();x=read_lli();
     intilize(n);
     for(i=0;i<n;i++)
     {
       lli qs,qe;
       qs=read_lli();qe=read_lli();
       update(arr,0,n-1,qs,qe,0);
     }
     lli max1=10000000,j;
     for(i=0,j=x-1;i<n && j<n;i++)
     {
       lli z=sum(0,n-1,i,j,0);
       if(max1>z)
        max1=z;
       j=i+x;
     }
     printf("%d\n",max1);
   }
   return 0;
}