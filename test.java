// TCS IPA Exam preparation 2024

// import java.util.*;

// public class test {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);

//         int n = sc.nextInt();
//         int[] arr = new int[n];
//         for(int i = 0; i < n; i++) {
//             // arr[i] = sc.nextInt(); sc.nextLine(); // it will only accept first element of new line
//             arr[i] = sc.nextInt();
//         }

//         HashMap<Integer,Integer> mp = new HashMap<>();
//         for(int i = 0; i < n; i++) {
//             int key = arr[i];
//             if (mp.containsKey(key)) {
//                 mp.put(key, mp.get(key) + 1);
//             } else {
//                 mp.put(key, 1);
//             }
//             // System.out.println(arr[i] + " ");
//         }

//         for(Map.Entry<Integer,Integer> ele : mp.entrySet()) {
//             System.out.println(ele.getKey() + " " + ele.getValue());
//         }
//     }
// };



// import java.util.*;

// public class test {
//     public static void main(String[] args) {
//         byte x = 127; // cyclic nature --> [-128, 127]
//         System.out.println(x);
//         x++;
//         System.out.println(x);
//         x++;
//         System.out.println(x);
//         x++;
//         System.out.println(x);
//         x++;
//         System.out.println(x);
//     }
// }


// import java.util.*;

// public class test {
//     public static void main(String[] args) {
//         PriorityQueue<Integer> minheap = new PriorityQueue<Integer>(); // min-heap
//         PriorityQueue<Integer> maxheap = new PriorityQueue<Integer>(Collections.reverseOrder()); // min-heap
//     }
// }


/*
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
        // }

        String s = sc.next();
        System.out.println(s);
        s = s.replace('h', 'H');
        System.out.println(s);
    }
}
    */

/*
// Question1 : TCS XPLORE - Java4 - Docs with odd pages

import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Document[] doc = new Document[4];
        for (int i = 0; i < 4; i++) {
            int a = sc.nextInt(); sc.nextLine();
            String b = sc.nextLine();
            String c = sc.nextLine();
            int d = sc.nextInt();
            if (i < 3) sc.nextLine();
            
            doc[i] = new Document(a, b, c, d);
        }

        Document[] oddPages = docsWithOddPages(doc);
        
        Arrays.sort(oddPages, (d1, d2) -> Integer.compare(d1.getId(), d2.getId()));

        for (Document d : oddPages) {
            System.out.println(d.getId() + " " + d.getTitle() + " " + d.getFolderName() + " " + d.getPages());
        }
    }

    public static Document[] docsWithOddPages(Document[] doc) {
        Document[] oddPageDocs = new Document[0];
        for (Document d : doc) {
            if (d.getPages() % 2 == 1) {
                oddPageDocs = Arrays.copyOf(oddPageDocs, oddPageDocs.length+1);
                oddPageDocs[oddPageDocs.length-1] = d;
            }
        }
        return oddPageDocs;
    }
}

class Document {
    int id;
    String title;
    String folderName;
    int pages;

    public Document(int id, String title, String folderName, int pages) {
        this.id = id;
        this.title = title;
        this.folderName = folderName;
        this.pages = pages;
    }

    // getters
    public int getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public String getFolderName() {
        return folderName;
    }

    public int getPages() {
        return pages;
    }
}

*/



/*
// Question2 : TCS Xplore - Sort books by Price

import java.util.*;

public class Solution {
    public static void main(String args[] ) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        
        Book[] bk = new Book[4];
        for(int i = 0; i < 4; i++) {
            int a = sc.nextInt(); sc.nextLine();
            String b = sc.nextLine();
            String c = sc.nextLine();
            double d = sc.nextDouble();
            if(i < 3) sc.nextLine();
            
            bk[i] = new Book(a, b, c, d);
        }
        
        Book[] b = sortBooksByPrice(bk);
        
        for(int i = 0; i < 4; i++) {
            System.out.println(b[i].getId() + " " + b[i].getTitle() + " " + b[i].getAuthor() + " " + b[i].getPrice());
        }
    }
    
    public static Book[] sortBooksByPrice(Book[] bk) {
        Book[] b = Arrays.copyOf(bk, bk.length);
        Arrays.sort(b, (b1, b2) -> Double.compare(b1.getPrice(), b2.getPrice()));
        return b;
    }
}

class Book {
    int id;
    String title;
    String author;
    double price;
    
    public Book(int id, String title, String author, double price) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.price = price;
    }
    
    // getters
    public int getId() {
        return id;
    }
    
    public String getTitle() {
        return title;
    }
    
    public String getAuthor() {
        return author;
    }
    
    public double getPrice() {
        return price;
    }
}
*/