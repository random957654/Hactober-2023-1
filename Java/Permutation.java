import java.util.*;
import java.util.Scanner;

public class Permutation {

      private static void generatePermutations(char[] str, int start, int end) {
        if (start == end) {
            System.out.println(new String(str));
        } else {
            for (int i = start; i <= end; i++) {
                swap(str, start, i);
                generatePermutations(str, start + 1, end);
                swap(str, start, i); // Backtrack
            }
        }
    }

    private static void swap(char[] str, int i, int j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();

        System.out.println("Permutations of the string:");
        generatePermutations(input.toCharArray(), 0, input.length() - 1);
    }

 
}
