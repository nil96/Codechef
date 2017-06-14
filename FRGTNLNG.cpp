#include<bits/stdc++.h>
#define lli long long int
#define inf 1000
using namespace std;
map<string,lli> m;
 
int main()
{
    lli t;
    char s[100][100];
    scanf("%lld",&t);
    getchar_unlocked();
    while(t--)
    {
    	m.clear();
    	lli n,k;
    	scanf("%lld%lld",&n,&k);
    	for(lli i=0;i<n;i++)
    	{
    		scanf("%s",s[i]);
    		getchar_unlocked();
    		//printf("%s\n",s[i]);
    	}
    	for(lli i=0;i<k;i++)
    	{
    		lli x;
    		scanf("%lld",&x);
    		getchar_unlocked();
    		for(lli i=0;i<x;i++)
    		{
    			string s1;
    			s1.clear();
    			char buffer[1000];
    			scanf("%s",buffer);
    		    getchar_unlocked();
    		    lli j=0;
    		    j=0;
    		    do
    		    {
                    s1.push_back(buffer[j]);
                    j++;
    		    }while(buffer[j]!='\0');
    //		    cout<<"s1===================="<<s1;
    		    m[s1]=i+1;
    		    
    		}
    	}
    	for(lli i=0;i<n;i++)
    	{
    		lli j=0;
    		j=0;
            string buffer;
            buffer.clear();
    //        printf("lx====%s\n",s[i] );
    		do
    		{
    		   buffer.push_back(s[i][j]);
    		   //printf("%c\n",s[i][j]);
    		   j++;
    		   
    		}while(s[i][j]!='\0');
    //		cout<<"xmmmmmm"<<buffer<<"\n";
    		map<string,lli>::iterator it = m.find(buffer);
    		if(it!=m.end())
    		{
    			printf("YES ");
    		}
    		else
               printf("NO ");
    	}
    	printf("\n");
    }
    return 0;
}  