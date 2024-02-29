import java.util.*;
import java.util.Arrays;
import java.util.Collections;

public class test{

    int convert(int decimal)
    {
        int result = 0;
        int multiplier = 1;
        int count =0;
          while(decimal > 0)
            {
              int residue = decimal % 2;
              if(residue==1)
                  count++;
              decimal     = decimal / 2;
              result      = result + residue * multiplier;
              multiplier  = multiplier * 10;
            }
          return count;
    }
    boolean isBleak(int m)
    {
       int k = convert(m);
       for(int i=1; i<=k; i++)
       {
          if(convert(m-i) == i)
              return false;
       }
       return true;
    }
    public static void main(String args[])
    {
        MinMax conv = new MinMax();
        boolean x=conv.isBleak(4);
        if(x){
            System.out.println("Number is Bleak");
        }else{
            System.out.println("Supported by some number");
        }
    }
}
    
    
    
    