package Two;
import java.util.Scanner;
public class Print1ToN {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the value of N");
		int n = sc.nextInt();
		int num=1;
		while(num<=n) {
			System.out.println(num);
			num=num+1;
		}
	}
}
