//Write a Java program to divide two user entered numbers using try..catch..finally
//block. The catch block should handle ArithmaticException. In the finally block
//take user option to retry till user says “No”.
import java.util.Scanner;

public class lab12_1 {
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        boolean retry = true;
        
        do {
            try {
                System.out.print("Enter the numerator: ");
                int numerator = sc.nextInt();
                
                System.out.print("Enter the denominator: ");
                int denominator = sc.nextInt();
                
                int result = divide(numerator, denominator);
                System.out.println("Result: " + result);
                
                retry = false;
            } catch (ArithmeticException e) {
                System.out.println("Error: " + e.getMessage());
            } finally {
                System.out.print("Do you want to try again? (Yes/No): ");
                String input = sc.next();
                
                if (input.equalsIgnoreCase("No")) {
                    retry = false;
                }
            }
        } while (retry);
        
        sc.close();
    }
    
    public static int divide(int numerator, int denominator) throws ArithmeticException {
        return numerator / denominator;
    }
}
