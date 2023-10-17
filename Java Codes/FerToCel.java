package One;
import java.util.Scanner;
public class FerToCel {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int fer= sc.nextInt();
		int cel = (5 * (fer-32))/9;
		System.out.println(cel);

	}

}
