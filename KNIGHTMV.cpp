//Correctness of Knight Move
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Error 1
#define correct 2
#define yes 3
#define no 4
int check(char *c)
{
  int flag=correct;
  int l=strlen(c);
  if(l!=5)
   return Error;
  else
  {
    if(!(c[0]>='a' && c[0]<='h'))
    {
      //printf("\nReturn for char 1\n");
      flag=Error;
    }
    if(!(c[1]>='1' && c[1]<='8'))
    {
     // printf("\nReturn for char 2\n");
      flag=Error;
    }
    if(!(c[2]=='-'))
    {
      //printf("\nReturn for char 3\n");
      flag=Error;
    }
    if(!(c[3]>='a' && c[3]<='h'))
    {
      //printf("Return for char 4\n");
      flag=Error;
    }
    if(!(c[4]>='1' && c[4]<='8'))
    {
      //printf("Return for char 5\n");
      flag=Error;
    }
    return flag;
  }
}
int mod(int t)
{
  if(t<0)
    return -t;
  else
    return t;
}
int operation(char *c)
{
  int temp_intial,temp1_intial;
 int i;
  temp_intial=(int)(c[0]-'a');
  temp1_intial=(int)(c[1]-'0');
  int temp_des,temp1_des;
  temp_des=(int)(c[3]-'a');
  temp1_des=(int)(c[4]-'0');
  int dif=temp_des-temp_intial;
  int dif1=temp1_des-temp1_intial;
  dif=mod(dif);
  dif1=mod(dif1);
  if(dif==1 && dif1==2)
   return yes;
  if(dif==2 && dif1==1)
   return yes;
  return no;
}
int main()
{
   long long int t;
   char c[15];
   scanf("%lld",&t);
   while(t--)
   {
     int flag=correct;
     fflush(stdin);
     getchar();
     scanf("%[^\n]s",c);
   //  printf("\nss=====%s\n",c);
     fflush(stdin);
     flag=check(c);
     if(flag==Error)
     {
       printf("Error\n");
     }
     else
     {
        int a=operation(c);
        if(a==yes)
         printf("Yes\n");
        else
         printf("No\n");
     }
   }
}