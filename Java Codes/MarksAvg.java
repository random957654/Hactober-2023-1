package One;

import java.util.Scanner;
public class MarksAvg {
	public static void main(String args[]) {
	Scanner sc= new Scanner(System.in);
	String name= sc.next();
	int marks1= sc.nextInt();
	int marks2= sc.nextInt();
	int marks3= sc.nextInt();
	int avg= (marks1+marks2+marks3)/3;
	System.out.println(name);
	System.out.println(avg);
		
	}
}

