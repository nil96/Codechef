import java.awt.print.Printable;
import java.io.BufferedReader;
import java.io.Reader;
import java.nio.Buffer;
import java.util.*;
import java.util.Arrays;
class Helloworld {
    public static void main(String args[])
    {
      try{ 
    	  long mat[][] = new long[350][350];
    	  Scanner reader = new Scanner(System.in);
    	  long t;
    	  //t = reader.nextLong();
    	  //while(t-->0)
    	  {
    		  int n = reader.nextInt();
    		  for(int i=0;i<n;i++)
    		  {
    			  for(int j=0;j<n;j++)
    			  {
    				  mat[i][j]=reader.nextLong();
    			  }
    		  }
    		  for(int i=0;i<n;i++)
    		  {
    			  Arrays.sort(mat[i],0,n);
    		  }
    		  for(int i=0;i<n;i++)
    		  {
    			  for(int j=0;j<n;j++)
    			  {
    				  System.out.print(mat[i][j]+" " );
    			  }
    			  System.out.print("\n");
    		  }
    	  }
    	  
      }
      catch(Exception e){
          return;
      }
    }
    
}
 