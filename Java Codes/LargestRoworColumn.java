package Strings_And_Arrays;

import java.util.Scanner;

public class LargestRoworColumn {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int Sum1=0;
		int Sum2=0;
		int index = 0;
		int rmax = Integer.MIN_VALUE;
		int cmax = Integer.MIN_VALUE;
		int arr[][]= new int[m][n];
		for(int i = 0; i<m; i++) {
			for(int j = 0; j<n; j++) {
				arr[i][j]=sc.nextInt();
			}
		}
		for(int i = 0; i<m; i++) {
			Sum1=0;
			for(int j = 0; j<n; j++) {
				Sum1 +=arr[i][j];
			}
			if(Sum1>rmax) {
				rmax = Sum1;
				
				index = i;
			}
		}
		for(int i = 0; i<n; i++) {
			Sum2=0;
			for(int j = 0; j<m; j++) {
				Sum2 +=arr[j][i];
			}
			if(Sum2>cmax) {
				cmax = Sum2;
		
				index = i;
			}
		}
		if(rmax > cmax) {
			System.out.println("row"+ " "+rmax+" "+index);
		}
		else {
			System.out.println("Coloumn"+ " "+cmax+" "+index);
		}

	}

}
