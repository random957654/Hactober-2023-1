package Strings_And_Arrays;

import java.util.Scanner;

public class PrintSpiral {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int arr[][]= new int[m][n];
		int i=0 , j=0;
		for(i = 0; i<m; i++) {
			for(j = 0; j<n; j++) {
				arr[i][j]=sc.nextInt();
			}
		}
		for(i= 0; i<m; i++) {
			if(i%2==0) {
				for(j = 0; j<n; j++) {
					System.out.print(arr[i][j]+" ");
				}
			}
			else {
				for(j = n-1; j>=0; j--) {
					System.out.print(arr[i][j]+" ");
				}
			}
		}

	}

}
