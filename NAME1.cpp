#include<stdio.h>
#include<stdlib.h>
//Name Reduction
char A[140008];
long long int alphabet[28]={0};
long long int son[28]={0};
void mark(char *a)
{
  long long int i=0;
  while(a[i]!='\0')
  {
    alphabet[(int)(a[i]-'a')]++;
    i++;
  }
}
void mark1(char *a)
{
  long long int i=0;
  while(a[i]!='\0')
  {
    son[(int)(a[i]-'a')]++;
    i++;
  }
}
void intilise()
{
  long long int i;
  for(i=0;i<=27;i++)
  {
    alphabet[i]=0;
    son[i]=0;
  }
}
int operation()
{
   int i;
   for(i=0;i<=27;i++)
   {
     if(son[i]>alphabet[i])
       return 0;
   }
   return 1;
}
int main()
{
   long long int t,son;
   scanf("%lld",&t);
   while(t--)
   {
       intilise();
       fflush(stdin);
       scanf("%s",A);
       mark(A);
 
       fflush(stdin);
       scanf("%s",A);
       mark(A);
 
       scanf("%lld",&son);
       while(son--)
       {
          fflush(stdin);
          scanf("%s",A);
          mark1(A);
       }
       int a=operation();
       if(a==0)
         printf("NO\n");
       else
         printf("YES\n");
   }
   return 0;
}
 