package Strings_And_Arrays;

public class StringUse {

	public static void main(String[] args) {
		char c = 'c';
		String str = "abcdef";
		System.out.println(str.charAt(1));
		System.out.println(str.length());
		System.out.println(str.substring(2, 5));
		System.out.println(str.contains("cde"));
		for(int i = 0; i<str.length();i++) {
			System.out.println(str.charAt(i));
		}
		
		str = "abc";
		str = str +"def";
		System.out.println(str.concat("ghi"));
		for(int i = 0; i<str.length(); i++) {
			System.out.println(str.substring(0, i+1));
		}
	}

}
