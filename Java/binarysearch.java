public class binarysearch {

    public static int binarySearch(int num[], int key){
        
        int start =0;
        int end = num.length-1;
        while(start<=end){
            int mid = (start+end)/2;
            if (num[mid]==key){
                return mid;
            }
            else if (num[mid]<key){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            
        }
        return -1;
    }
    public static void main(String args[]){
        int num[]={2,10,41,71,90};
        int key = 90;
        System.out.println(binarySearch(num,key));
    }
}
