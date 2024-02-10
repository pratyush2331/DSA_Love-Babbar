import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class test {
    public static void main(String[] args) {
        List<Integer> used = new ArrayList<>();
        used.add(1);
        used.add(3);
        used.add(3);
        // used.add(3);
        // used.add(1);

        List<Integer> total = new ArrayList<>();
        total.add(3);
        total.add(3);
        total.add(3);
        // total.add(5);
        // total.add(5);

        int minPartition = 0;

        List<Integer> sortedTotal = total.stream()
                .sorted(Comparator.reverseOrder())
                .collect(Collectors.toList());

        int totalNumber = used.stream().mapToInt(Integer::intValue).sum();

        int counterTotal = 0;
        int currTotal;
        while (totalNumber > 0 && counterTotal < sortedTotal.size()) {
            currTotal = sortedTotal.get(counterTotal);
            totalNumber -= currTotal;

            if (totalNumber > 0) {
                minPartition++;
                counterTotal++;
            } else if (totalNumber < 0) {
                totalNumber += currTotal; // Revert the subtraction if totalNumber goes negative
                minPartition++;
            }
        }

        // Handle edge cases where totalNumber becomes negative
        if (totalNumber > 0) {
            minPartition++;
        }

        System.out.println(minPartition);
    }
}