#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string.h>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
char input[1000010];
char index1[]={'c','h','e','f'};
lli count1[4][1000010];
lli learn[12][1000010];
lli l;
lli matrix[4][4];
lli get_index(char c)
{
  for(lli i=0;i<4;i++)
  {
     if(index1[i]==c)
       return i;
  }
}
void store(lli s,lli e,lli z)
{
   lli v=0;
   lli old=0;
   for(lli i=l-1;i>=0;i--)
   {
      if(input[i]==index1[s])
      {
         v=count1[e][l-1]-count1[e][i];
      }
      learn[z][i]=old+v;
      old=learn[z][i];
      v=0;
   }
}
lli oprtn(char c,char f,lli s,lli e)
{
  lli id1=get_index(c);
  lli id2=get_index(f);
  lli z1=matrix[id1][id2];
 // printf("z1===%lld\n",z1);
  lli m1,m2,m3;
  /*for(lli i=0;i<l;i++)
  {
    printf("%lld",count1[id2][i]);
  }
   printf("\n");
  for(lli i=0;i<l;i++)
  {
    printf("%lld",learn[z1][i]);
  }
  printf("\n");*/
 
 
 
 
   if(e+1<=l-1)
     m1=learn[z1][s]-learn[z1][e+1];
    else
     m1=learn[z1][s];
    //printf("m1=====%lld\n",m1);
  {
    if(s-1>=0)
      m2=count1[id1][e]-count1[id1][s-1];
    else
      m2=count1[id1][e];
    //printf("m2=====%lld\n",m2);
  }
 
 
  {
      m3=count1[id2][l-1]-count1[id2][e];
  }
  return m1-m2*m3;
 
}
void preprocess1()
{
   lli z=0;
   for(lli i=0;i<4;i++)
   {
     for(lli j=0;j<4;j++)
     {
       if(i!=j)
       {
         matrix[i][j]=z;
         store(i,j,z);
         z++;
       }
       else
       {
         matrix[i][j]=-1;
       }
     }
   }
  return;
}
void preprocess(char *input)
{
    l=strlen(input);
    lli countb[]={0,0,0,0};
    for(lli i=0;i<l;i++)
    {
        if(input[i]=='c')
        {
          countb[0]++;
 
        }
        else if(input[i]=='h')
        {
          countb[1]++;
        }
        else if(input[i]=='e')
        {
          countb[2]++;
        }
        else if(input[i]=='f')
        {
          countb[3]++;
        }
        count1[0][i]=countb[0];
        count1[1][i]=countb[1];
        count1[2][i]=countb[2];
        count1[3][i]=countb[3];
    }
}
void read_input()
{
  lli i=0;
  char c='a';
  while(1)
  {
    c=getchar_unlocked();
    if(c==' ' || c=='\n')
     break;
    else
     input[i]=c;
     i++;
  }
  input[i]='\0';
 
}
lli read_lli()
{
  char c=gc();
  while(c<'0' || c>'9')
    c=gc();
  lli ret=0;
  while(c>='0' && c<='9')
  {
    ret=10*ret+c-48;
    c=gc();
  }
  return ret;
}
int main()
{
  read_input();
  //printf("%s\n",input);
  preprocess(input);
  preprocess1();
  lli q;
  q=read_lli();
  lli s,e;
  char c,h;
   while(q--)
   {
      //cin>>c>>h>>s>>e;
      c=getchar_unlocked();
      gc();
      h=gc();
      gc();
      s=read_lli();
      e=read_lli();
      lli ans=oprtn(c,h,s-1,e-1);
      printf("%lld\n",ans);
   }
   return 0;
 
}
 