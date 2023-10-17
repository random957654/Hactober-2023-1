package Strings_And_Arrays;

import java.util.Scanner;

public class PrintLikeAWave {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int i = 0; 
		int j  = 0;
		int arr[][]= new int[m][n];
		for(i = 0; i<m; i++) {
			for(j = 0; j<n; j++) {
				arr[i][j]=sc.nextInt();
			}
		}
		 for(j=0;j<n;j++) {
			 
		 
		if(j%2==0)
		{
			
				for(i = 0; i<m; i++) {
					System.out.print(arr[i][j]+" ");
				}
			}
		
		else {
			
				for(i=m-1; i>=0; i--) {
					System.out.print(arr[i][j]+" ");
				}
			
		}
		

	}

}
}