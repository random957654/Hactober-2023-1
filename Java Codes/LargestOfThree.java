package Two;
import java.util.Scanner;
public class LargestOfThree {
public static void main(String args[]) {
	Scanner sc = new Scanner(System.in);
	int n1= sc.nextInt();
	int n2= sc.nextInt();
	int n3 = sc.nextInt();
	if(n1>=n2 && n1 >= n3) {
		System.out.println("Num 1 is Greatest of three");
	}
	else if(n2>=n1 && n2>=n3) {
		System.out.println("Num 2 is Greatest of three");
	}
	else {
		System.out.println("Num 3 is Greatest of three");
	}
}
}
