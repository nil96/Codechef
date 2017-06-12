#include<bits/stdc++.h>
#define lli long long int
#define inf LONG_LONG_MAX
using namespace std;
struct node
{
    lli h,m;
};
struct range
{
    lli s,e;
};
/*
1
12
699 52
29 446
647 64
148 311
480 596
109 815
176 695
55 745
35 320
4 71
530 34
157 814
 
*/
vector<struct node> v;
vector<struct range> ans1;
vector<struct range> ans2;
lli flip(lli x)
{
    if(x==0)
      return 1;
    return 0;
}
lli isphie(struct range x)
{
    if(x.s==-1 || x.e==-1)
      return 1;
    return 0;
}
struct range UnionWithPhie(struct range a,struct range b)
{
  if(a.s==-1 || a.e==-1)
     return b;
  return a;
}
struct range IntersectionWithPhie(struct range a,struct range b)
{
  if(a.s==-1 || a.e==-1)
     return a;
  return b;
}
lli lower(double a)
{
    lli x=a;
    if(a-x>0)
        return x;
    return x-1;
}
struct range fun1(struct node a,struct node b)
{
    struct range temp;
    if(a.m-b.m==0)
    {
        if(a.h>b.h)
        {
          temp.s=0;temp.e=inf;
        }
        else
        {
          temp.s=-1;temp.e=-1;
        }
    }
    if(a.m-b.m>0)
    {
        if(b.h-a.h>0)
        {
            temp.s=(b.h-a.h)/(a.m-b.m)+1;
            temp.e=inf;
        }
        if(b.h-a.h==0)
        {
            temp.s=1;
            temp.e=inf;
        }
        if(b.h-a.h<0)
        {
            temp.s=0;
            temp.e=inf;
        }
    }
    else if(a.m-b.m<0)
    {
       if(b.h-a.h>0)
        {
            temp.s=-1;
            temp.e=-1;
        }
        if(b.h-a.h==0)
        {
            temp.s=-1;
            temp.e=-1;
        }
        if(b.h-a.h<0)
        {
            temp.s=0;
            temp.e=lower((double)(b.h-a.h)/(a.m-b.m));
        }
 
    }
    return temp;
}
void print_ans(vector<struct range> a)
{
    for(lli i=0;i<a.size();i++)
        printf("(%lld %lld) ",a[i].s,a[i].e);
}
void fun(lli x)
{
  ans1.clear();ans2.clear();
  struct range temp,temp1;
  if(v.size()==1)
  {
      temp.s=0;
      temp.e=inf;
      ans1.push_back(temp);
      ans2.push_back(temp);
      return;
  }
  for(lli i=0,j=1;j<v.size();i++,j++)
  {
     struct node a,b;
      a=v[i];
      b=v[j];
      temp=fun1(a,b);
      temp1=fun1(b,a);
      if(x==0)
      {
          ans1.push_back(temp);
          ans2.push_back(temp1);
      }
      else
      {
        ans1.push_back(temp1);
        ans2.push_back(temp);
      }
      x=flip(x);
  }
      /*printf("\n---------ans1-------\n");
      print_ans(ans1);
      printf("\n---------ans1-------\n");
 
      printf("\n---------ans2-------\n");
      print_ans(ans2);
      printf("\n---------ans2-------\n");*/
}
struct range _intersection(struct range a,struct range b)
{
   struct range t;
   t.s=max(a.s,b.s);
   t.e=min(a.e,b.e);
   if(t.s>t.e)
   {
       t.s=-1;
       t.e=-1;
   }
   return t;
}
struct range intersection(vector<struct range> &a)
{
   struct range t=a[0];
   for(lli i=1;i<a.size();i++)
   {
     if(a[i].s==-1 || a[i].e==-1 || t.s==-1 || t.e==-1)
     {
         t=IntersectionWithPhie(a[i],t);
     }
     else
     {
         t=_intersection(a[i],t);
     }
   }
   return t;
}
vector<struct range> fans;
void union1(struct range a,struct range b)
{
    fans.clear();
    struct range t;
    if(a.s==-1 && a.e==-1 && b.s==-1 && b.e==-1)
        return;
    if(a.s==-1 || a.e==-1)
    {
       fans.push_back(b);
       return;
    }
    if(b.s==-1 || b.e==-1)
    {
      fans.push_back(a);
      return;
    }
    if(a.s>=b.s)
        swap(a,b);
    if(b.s>=a.s && b.s<=a.e)
    {
        t.s=min(a.s,b.s);
        t.e=max(a.e,b.e);
        fans.push_back(t);
 
    }
    else
    {
        if(b.s==a.e+1)
        {
          t.s=min(a.s,b.e);
          t.e=max(a.e,b.e);
          fans.push_back(t);
          return;
        }
       fans.push_back(a);
       fans.push_back(b);
    }
    return;
}
void print(struct range a)
{
    printf("%lld %lld\n",a.s,a.e);
}
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
       lli n;v.clear();
       scanf("%lld",&n);
       for(lli i=0;i<n;i++)
       {
           struct node temp;
           scanf("%lld%lld",&temp.h,&temp.m);
           v.push_back(temp);
       }
       fun(0);
       struct range temp1=intersection(ans1);
       struct range temp2=intersection(ans2);
    /*   printf("\n-----------------\n");
       print(temp1);
       print(temp2);
        printf("\n-----------------\n");*/
       union1(temp1,temp2);
       lli x=0;
       x=fans.size();
       printf("%lld\n",x);
       if(fans.size()==2)
       {
           if(fans[1].s<fans[0].s)
             swap(fans[1],fans[0]);
       }
       for(lli i=0;i<fans.size();i++)
       {
           printf("%lld ",fans[i].s);
           if(fans[i].e==inf)
             printf("Inf\n");
           else
           printf("%lld \n",fans[i].e);
 
       }
   }
   return 0;
}
 