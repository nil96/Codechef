#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define lower_case 1
#define upper_case 2
#define special_character 3
int check_case(int num)
{
 // printf("num==============%d  %c\n",num,(char)num);
  if(num>=(int)'A' && num<=(int)'Z')
    return upper_case;
  if(num>=(int)'a' && num<=(int)'z')
    return lower_case;
  else
    return special_character;
}
int main()
{
  int t,i,case1;
  char english[26];
  char buffer[200];
  char z;
  scanf("%d",&t);
  scanf("%s",english);
  while(t--)
  {
     scanf("%s",buffer);
     i=0;
     while(buffer[i]!='\0')
     {
      case1=check_case((int)buffer[i]);
      if(buffer[i]=='_')
         printf(" ");
      else if(case1==lower_case)
         printf("%c",english[(int)buffer[i]-(int)'a']);
      else if(case1==upper_case)
       printf("%c",toupper(english[(int)buffer[i]-(int)'A']));
      else if(case1==special_character)
         printf("%c",buffer[i]);
         i++;
     }
     printf("\n");
  }
  return 0;
}