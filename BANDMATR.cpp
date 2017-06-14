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
    	  int mat[][] = new int[602][602];
    	  int input[][] = new int[602][602];
    	  int arr[] = new int [1000000];
    	  for(int i=0;i<502;i++)
    	  {
    		  for(int j=0;j<502;j++)
    		  {
    			  mat[i][j]=Math.abs(i-j);
    		  }
    	  }
    	  int t;
    	  Scanner reader =new Scanner(System.in);
    	  t=reader.nextInt();
    	  while(t-->0)
    	  {
    		  int n = reader.nextInt();
    		  int c=0;
    		  int c1=0;
    		  for(int i=0;i<n;i++)
    		  {
    			for(int j=0;j<n;j++)
    			{
    				input[i][j] = reader.nextInt();
    				if(input[i][j] == 1)
    				{
    				  c1++;	
    				}
    				arr[c] = mat[i][j];
 //   				System.out.println("arr[" + c + "]" + "==="+mat[i][j]);
    				c++;
    			}
    		  }
    		  Arrays.sort(arr,0,c);
    		  /*for(int i=0;i<c;i++)
    		  {
    			  System.out.println("arr[" + i + "]" + "==="+arr[i]);
    			 // System.out.println(arr[i]+" ");
    		  }*/
    		//  System.out.println("c1====="+ c1 +"\n");
    		  //int ans=arr[c1];
    		  if(c1==0)
    		  {
    			  System.out.println("0\n");
    		  }
    		  else
    		  {
    			  
    			  System.out.println(arr[c1-1]+"\n");
    		  }
    	  }
    	  reader.close();
      }
      catch(Exception e){
          return;
      }
    }
    
}