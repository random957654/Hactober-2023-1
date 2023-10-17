package Strings_And_Arrays;

import java.util.Scanner;

public class CheckPermutation {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str1 = sc.nextLine();
		String str2 = sc.nextLine();
		char c1;
		char c2;
		int c = 0;
		for(int i = 0; i<str1.length(); i++) {
			c1= str1.charAt(i);
			for(int j = 0; j<str2.length(); j++) {
				c2 = str2.charAt(j);
				if(c1==c2) {
					++c;
				}
			}
			
		}
		if(c == str1.length()) {
			System.out.println(true);
		}
		else {
			System.out.println(false);
		}
		}
		

}
