import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
class Solution
{
  public static int gcd(int a, int b)
  {
    if(a==0)
      return b;
    return gcd(b%a,a);
  }
  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
    List<Integer> list = new ArrayList<Integer>();
    int[] myIntArray = new int[1000];
    int t=sc.nextInt();
    while(t>0)
    {
    	int n=sc.nextInt();
    	list.clear();
    	for(int i=0;i<n;i++)
    	{
    		int temp=sc.nextInt();
    		myIntArray[i]=temp;
    	}
    	BigInteger ans = new BigInteger("11111111111111111111111111111111111111111111111111");
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			if(i!=j)
    			{
    				BigInteger x = new BigInteger(Integer.toString(myIntArray[i]));
    				BigInteger y = new BigInteger(Integer.toString(myIntArray[j]));
    				int z=gcd(myIntArray[i],myIntArray[j]);
    				BigInteger z1 = new BigInteger(Integer.toString(z));
    				x=x.multiply(y);
    				//System.out.println("x*y========="+x);
    				x=x.divide(z1);
    				//System.out.println("x*y========="+x);
    				ans=x.min(ans);
    			}
    		}
    	}
    	System.out.println(ans);
    	t=t-1;
    }
    
    sc.close();
 
  }
} 