package Two;
import java.util.Scanner;
public class SumOfEvenNum {
public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
//	int sum = n*(n+1);
//	System.out.println("Sum of first "+n+" even numbers is: "+sum);
	int sum=0;
	int i = 2;
	while(i<=n) {
	if(i%2 == 0) {
		System.out.println(i);
		sum = i+sum;
	}
	i++;
}
	System.out.println("sum: "+sum);
}
}