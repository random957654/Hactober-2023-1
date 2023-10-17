package Strings_And_Arrays;

import java.util.Scanner;

public class ReverseStringWord {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		String word = " ";
		String s = " ";
		str = " "+str;
		for(int i = str.length()-1; i>=0;i--) {
			char c = str.charAt(i);
			if(c != ' ') {
				 word = c + word;
			}
			else {
				s += word+" ";
				word = " ";
			}
			
		}
		System.out.println(s);

	}

}
