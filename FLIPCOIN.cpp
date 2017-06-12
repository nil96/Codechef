//https://www.codechef.com/problems/FLIPCOIN
 
#include <bits/stdc++.h>
#define FOR(i,a,n) for(lli i=a;i<n;i++)
#define sc(a) scanf("%lld",&a)
#define sc_(a,b) scanf("%lld%lld",&a,&b)
#define pf(x) printf("%lld\n",x)
#define lli long long int
using namespace std;
lli arr[1000004];
lli seg[1000004];
lli lazy[1000004];
lli create(lli s,lli e,lli i)
{
	if(s>e)
	  return 0;
	if(s==e)
	{
	  seg[i]=arr[s];
	  return 0;
	}
	lli mid=(s+e)/2;
	create(s,mid,2*i+1);create(mid+1,e,2*i+2);
	seg[i]=seg[2*i+1]+seg[2*i+2];
}
lli query(lli s,lli e,lli qs,lli qe,lli si)
{
	if(s>e)
	  return 0;
	if(lazy[si]!=0)
	{
		seg[si]=(e-s+1)-seg[si];
		if(s!=e)
		{
			lazy[2*si+1]=1-lazy[2*si+1];
			lazy[2*si+2]=1-lazy[2*si+2];
		}
		lazy[si]=0;
	}
	if(s>qe || qs>e || s>e)
	   return 0;
	if(s>=qs && e<=qe) 
       return seg[si];
    lli mid=(s+e)/2;
    return query(s,mid,qs,qe,2*si+1)+query(mid+1,e,qs,qe,2*si+2);
}
lli update(lli s,lli e,lli qs ,lli qe,lli si)
{
	if(s>e)
	  return 0;	
	if(lazy[si]!=0)
	{
		seg[si]=(e-s+1)-seg[si];
		if(s!=e)
		{
			 lazy[2*si+1]=1-lazy[2*si+1];
			 lazy[2*si+2]=1-lazy[2*si+2];
		}
		lazy[si]=0;
	}
	if(s>e || s>qe || qs>e)
	 return 0;
	if(s>=qs && e<=qe)
	{
		seg[si]=(e-s+1)-seg[si];
        if(s!=e)
        {
        	lazy[si*2+1]=1-lazy[2*si+1];;
        	lazy[si*2+2]=1-lazy[2*si+2];;
        }
        return 0;
	}
	lli mid=(e+s)/2;
	update(s,mid,qs,qe,2*si+1);
	update(mid+1,e,qs,qe,2*si+2);
	seg[si]=seg[2*si+1]+seg[2*si+2];
}
 
 
 
int main()
{
	lli n,q;
	sc_(n,q);
	FOR(i,0,n)
	{
	  arr[i]=1;
	}
	FOR(i,0,10*n)
	{
		lazy[i]=0;
	}
	create(0,n-1,0);
	FOR(i,0,q)
	{
	  lli flag,a,b;
	  sc(flag);sc_(a,b);
	  if(flag==0)
	  {
	  	update(0,n-1,a,b,0);
	  }
	  else if(flag==1)
	  {
	  	lli x=query(0,n-1,a,b,0);
	  	printf("%lld\n",b-a-x+1 );
	  }
	}
	return 0;
}
 
 