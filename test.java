import java.util.*;
import java.awt.*;
import java.lang.reflect.*;

public class test {
    public static void main(String[] args) {
        // System.out.println(Color.red);

        Scanner sc = new Scanner(System.in);

        // int arr[] = new int[5]; // by default all els = 0
        // for(int i = 0; i < arr.length; i++) {
        //     arr[i] = sc.nextInt();
        //     System.out.println(arr[i] + " ");
        //     // System.out.println(Array.get(arr, 2));
        // }

        String s = sc.next();
        System.out.println(s);
        s = s.replace('h', 'H');
        System.out.println(s);
    }
}