import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        List<Integer> list = new ArrayList<>();
        
        // Loop until there is no more input available
        while (scanner.hasNextInt()) {
            int input = scanner.nextInt();
            list.add(input);
        }
        
        // Close the scanner
        scanner.close();

        // Print the list of numbers entered by the user
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + " ");
        }
    }
}