package Two;
import java.util.Scanner;
public class NatureOfChar {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char c = sc.next().charAt(0);
		if(c>=97 && c<=122) {
			System.out.println("0");
		}
		else if(c>=65 && c<=90) {
			System.out.println("1");
		}
		else {
			System.out.println("-1");
		}
	}

}
