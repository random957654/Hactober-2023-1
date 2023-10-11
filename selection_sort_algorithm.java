
import java.util.Arrays;
//selection sort

public class Main{
    public static void main(String[] args){
        int[] arr= {5,3,4,1,2};
        insertion(arr);
        System.out.println(Arrays.toString(arr));
    }
static void selection(int[] arr){
        for(int i=0;i<arr.length;i++){
            //find the max item in the remaining array and swap with correct index
            int last=arr.length-i-1;
            int maxIndex=getMaxIndex(arr, 0 ,last);

            swap(arr, maxIndex, last);
        }
    }

    static void swap(int[] arr, int first, int second){
        int temp=arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
}
