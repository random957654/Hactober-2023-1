package Two;
import java.util.Scanner;
public class FarToCelTable {
public static void main(String[] args) {
	int S, E, W;
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter the value of start far between 0 to 80: ");
	S = sc.nextInt();
	System.out.println("Enter end far value between "+S+" to 900:");
	E = sc.nextInt();
	System.out.println("Enter Step Size between 0 to 40: ");
	W = sc.nextInt();
	while(S<=E) {
	int cel = (5 * (S-32))/9;
	System.out.println(S +"\t"+ cel);
	S=S+W;
	}
}
}
