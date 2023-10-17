package Strings_And_Arrays;

import java.util.Scanner;

public class RemoveConsecutiveDuplicates {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		for(int i = 0; i<str.length()-1; i++) {
			char ch = str.charAt(0);
			if(ch!=str.charAt(i+1)) {
					System.out.print(str.charAt(i));
					ch=str.charAt(i+1);
					i=i+2;
			}
				
			}
		

		}
	
}
