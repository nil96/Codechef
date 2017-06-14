#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define lli long long int
char buffer[10000];
lli oprtn(char *buff)
{
	lli cur_max=1,i;
	lli r_max=1;
	lli visited[260];
	lli n=strlen(buff);
	for(i=0;i<260;i++)
	  visited[i]=-1;
   visited[buff[0]]=0;
   lli previous_index;
   for(i=1;i<n;i++)
   {
	  previous_index=visited[buff[i]];
	  if(previous_index==-1 || i-cur_max>previous_index)
	  {
		   cur_max++;
	  }
	  else
	  {
		  if(r_max<cur_max)
		  {
			  r_max=cur_max;
		  }
		  cur_max=i-previous_index;
	  }
	  visited[buff[i]]=i;
   }
    if(r_max<cur_max)
    {
	   r_max=cur_max;
    }
    return r_max;
 
}
	
int main()
{
   lli t;
   scanf("%lld",&t);
   getchar_unlocked();
   while(t--)
   {
	    scanf("%s",buffer);
	    getchar_unlocked();
	    lli ans=oprtn(buffer);
	    printf("%lld\n",ans);
   }
   return 0;
}
	
 