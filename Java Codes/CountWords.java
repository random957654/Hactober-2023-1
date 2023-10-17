package Strings_And_Arrays;

import java.util.Scanner;

public class CountWords {

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			String str = sc.nextLine();
			int c = 1;
			for(int i = 0; i<str.length(); i++) {
				if ((str.charAt(i) == ' ') && (str.charAt(i + 1) != ' ')) {
					c++;
				}
			}
			System.out.println(c);
		}

	}

}
