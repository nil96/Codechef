//https://www.codechef.com/problems/MULTQ3/
 
#include <bits/stdc++.h>
#define lli  int
#define gc() getchar_unlocked();
#define sc(a) scanf("%d",&a);gc();
#define sc_(a,b) scanf("%d%d",&a,&b);gc();
#define pf(a) printf("%d\n",a);
#define FOR(i,a,b) for(lli i=a;i<b;i++)
using namespace std;
struct node
{
   lli rem[3];
};
lli arr[1000006];
struct node seg[8000006];
lli lazy[1000006];
lli init(lli n)
{
	FOR(i,0,n)
	  arr[i]=0;
	FOR(i,0,5*n)
	{
		seg[i].rem[0]=0;
		seg[i].rem[1]=0;
		seg[i].rem[2]=0;
	}
}
struct node add(struct node seg1,struct node seg2)
{
	struct node t;
	t.rem[0]=seg1.rem[0]+seg2.rem[0];
	t.rem[1]=seg1.rem[1]+seg2.rem[1];
	t.rem[2]=seg1.rem[2]+seg2.rem[2];
	return t;
}
lli create(lli s,lli e,lli ind)
{
	if(s>e)
		return 0;
	if(s==e)
	{
		seg[ind].rem[arr[s]%3]++;
		return 0;
	}
	lli mid=(s+e)/2;
	create(s,mid,2*ind+1);
	create(mid+1,e,2*ind+2);
	seg[ind]=add(seg[2*ind+1],seg[2*ind+2]);
}
struct node shift1(struct node a)
{
	FOR(i,0,3)
	{
		swap(a.rem[i],a.rem[2]);
	}
	return a;
}
lli query(lli s,lli e,lli qs,lli qe,lli ind)
{
	if(lazy[ind]!=0)
	{
		lli z=lazy[ind]%3;
		FOR(i,0,z)
		{
			seg[ind]=shift1(seg[ind]);
		}
		if(s!=e)
		{
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		lazy[ind]=0;
	}
	if(s>qe || e<qs || s>e)
		return 0;
	if(s>=qs && e<=qe)
	  return seg[ind].rem[0];
	lli mid=(s+e)/2;
	lli q1=query(s,mid,qs,qe,2*ind+1);
	lli q2=query(mid+1,e,qs,qe,2*ind+2);
    return q1+q2;
}
lli update(lli s,lli e,lli qs,lli qe,lli ind)
{
	if(lazy[ind]!=0)
	{
	    lli z=lazy[ind]%3;
		FOR(i,0,z)
		{
			seg[ind]=shift1(seg[ind]);
		}
		if(s!=e)
		{
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		lazy[ind]=0;	
	}
	if(s>qe || e<qs || s>e)
	{
	  return 0;
	}
    if(s>=qs && qe>=e)
    {
    	lli z=1;
		FOR(i,0,z)
		{
			seg[ind]=shift1(seg[ind]);
		}
		if(s!=e)
		{
			lazy[2*ind+1]+=1;
			lazy[2*ind+2]+=1;
		}
		return 0;
    }
    lli mid=(s+e)/2;
    {
      update(s,mid,qs,qe,2*ind+1);
      update(mid+1,e,qs,qe,2*ind+2);
    }
    seg[ind]=add(seg[2*ind+1],seg[2*ind+2]);
}
int main()
{
	lli n,q;
	sc_(n,q);
	init(n);
	create(0,n-1,0);
	while(q--)
	{
		lli flag;
		sc(flag);
		lli s,e;
		sc_(s,e);
		if(flag==0)
		{
			update(0,n-1,s,e,0);
		}
		if(flag==1)
		{
		     lli ans=query(0,n-1,s,e,0);
		     printf("%d\n",ans);	
		}
	}
	return 0;
} 
Comments 
