Intuition - Binary search is a fast search algorithm with run time complexity of O(log N). This search algorithm works on the basis of "Divide and Conquer". For this algorithm to work properly, the array should be in sorted form.
Approach - Binary search looks for a particular item(or element) by comparing the middlemost element of the collection. If a match occurs, then the index of the element is returned. If the middle element is greater than the element to be found(target), then the element is searched in the sub-array to the left of the middle element. Otherwise, the element is searched in the sub-array to the right of the middle element.
Complexity
Time complexity: O(log N)
where N is the size of the array
Space complexity: O(1)

class Solution {
    public int search(int[] nums, int target) {
        
       int left = 0;
       int right = nums.length-1;
       return binarySearch_Recursive(nums,left,right,target);
    }

    int binarySearch_Recursive(int nums[], int left, int right, int target){
      if(left>right)
         return -1;

      else{
        int mid = left+(right-left)/2;

        if(nums[mid]<target)
        return binarySearch_Recursive(nums, mid+1,right,target);
      
        else if(nums[mid]>target)
        return binarySearch_Recursive(nums,left, mid-1,target);

        else
         return mid;
      }
    }
}
//// Java Program to Illustrate Recursive Binary Search

// Importing required classes
import java.util.*;

// Main class
class bsearch {

	// Method 1
	// Recursive binary search
	// Returns index of x if it is present
	// in arr[l..r], else return -1
	int binarySearch(int arr[], int l, int r, int x)
	{
		// Restrict the boundary of right index
		// and the left index to prevent
		// overflow of indices
		if (r >= l && l <= arr.length - 1) {

			int mid = l + (r - l) / 2;

			// If the element is present
			// at the middle itself
			if (arr[mid] == x)
				return mid;

			// If element is smaller than mid, then it can
			// only be present in left subarray
			if (arr[mid] > x)
				return binarySearch(arr, l, mid - 1, x);

			// Else the element can only be present
			// in right subarray
			return binarySearch(arr, mid + 1, r, x);
		}

		// We reach here when element is not present in
		// array
		return -1;
	}

	// Method 2
	// Main driver method
	public static void main(String args[])
	{

		// Creating object of above class
		bsearch ob = new bsearch();

		// Custom input array
		int arr[] = { 2, 3, 4, 10, 40 };

		// Length of array
		int n = arr.length;

		// Custom element to be checked
		// whether present or not
		int x = 10;

		// Calling above method
		int result = ob.binarySearch(arr, 0, n - 1, x);

		// Element present
		if (result == -1)

			// Print statement
			System.out.println("Element not present");

		// Element not present
		else

			// Print statement
			System.out.println("Element found at index "
							+ result);
	}
}
