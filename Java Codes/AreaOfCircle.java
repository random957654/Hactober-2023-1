package One;
import java.util.Scanner;
public class AreaOfCircle {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int AREA =(int) (2*3.14*r*r);//Explicit TypeCasting
		System.out.println(AREA);

	}

}
