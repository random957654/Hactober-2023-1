package Strings_And_Arrays;

import java.util.Scanner;

public class RowWiseSum {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int sum = 0;
		int arr[][]= new int[n][m];
		for(int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				arr[i][j]=sc.nextInt();
			}
		}
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<m; j++) {
				sum+=arr[i][j];
			}
			System.out.print(sum+" ");
			sum = 0;
		}
	}

}
