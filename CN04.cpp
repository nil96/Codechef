#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<string.h>
#define lli long long int
using namespace std;
map<string,lli> m;
string s;
int main()
{
  lli t;
  map<string,lli> :: iterator p;
  scanf("%lld",&t);
  getchar_unlocked();
  while(t--)
  {
     cin>>s;
     //cout << s <<"\n";
     lli count1=0;
     m.clear();
     lli h=0;
     for(lli i=0;i<s.size();i++)
     {
       for(lli j=i;j<s.size();j++)
       {
         p=m.find(s.substr(i,j));
         if(p==m.end())
         {
            m.insert(pair<string,lli>(s.substr(i,j),i ));
           // cout<< s.substr(i,j) <<"\n";
            count1++;
         }
       }
     }
     printf("%lld\n",count1);
  }
  return 0;
}
 
Comments 
