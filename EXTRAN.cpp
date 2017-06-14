import java.awt.print.Printable;
import java.io.BufferedReader;
import java.io.Reader;
import java.nio.Buffer;
import java.util.*;
import java.util.Arrays;
class Helloworld {
	public static int check(long arr[],int s,long n)
	{
		long x=arr[s];
		for(int i=s+1;i<=n;i++)
		{
			x++;
			//System.out.println(x+"===="+arr[i]);
			if(x!=arr[i])
			  return i;
		}
		return -1;
	}
    public static void main(String args[])
    {
      try{ 
      long t;
       Scanner reader = new Scanner(System.in);
       t = reader.nextLong();
      // System.out.println("\n");
       while(t-->=0)
       {
    	  int  n = reader.nextInt();
    	  long arr[] = new long[n]; 
    	  for(int i=0;i<n;i++)
    	  {
    		  arr[i] = reader.nextLong();
    	  }
    	  Arrays.sort(arr);
    	 /* for(int i=0;i<n;i++)
    	  {
    		  System.out.println(arr[i]+" ");  
    	  }*/
    	  int x=check(arr,1,n-1);
    	  if(x==-1)
    	  {
    		  System.out.println(arr[0]);
    	  }
    	  else
    	  {
    		  System.out.println(arr[x]);
    	  }
    	    
       }      
      }
      catch(Exception e){
          return;
      }
    }
    
}
 