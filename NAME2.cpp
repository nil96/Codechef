#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int operation(char *a,char *b,int small,int large)
{
   int i=0,count=0,j=0;
   while(b[i]!='\0' && j<large)
   {
      if(b[i]==a[j])
       i++;
      j++;
   }
   if(i==small)
     return 1;
   else
     return 0;
}
int main()
{
  int t,male_l,female_l,a;//a==1 possible
  scanf("%d",&t);
  char male[250000];
  char female[250000];
  while(t--)
  {
     fflush(stdin);
     scanf(" %s",male);
     fflush(stdin);
     scanf(" %s",female);
     male_l=strlen(male);
     female_l=strlen(female);
     if(male_l>female_l)
     {
       a=operation(male,female,female_l,male_l);
     }
     else
     {
        a=operation(female,male,male_l,female_l);
     }
     if(a==1)
      printf("YES\n");
     else
      printf("NO\n");
  }
}