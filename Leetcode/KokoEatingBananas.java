public class KokoEatingBananas{
    
        //binary search on answers
        //instead of the input array, binary search is applied on the answer range, to find the desired answer
        //here the minimum banana(s) that koko can eat is 1 and and maximum she can eat varies like after a certain point when she increases her eating speed the time taken would be same, so the range would be from 1 to the minimum number to which non repeating time.
        //and this would be the maximum number of bananas.
        //so our range would be from [1,maximum number of bananas]

    public int minEatingSpeed(int[] arr, int h) {
        if(arr==null)
            return 0;
        
        int max=Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++)
            max=Math.max(max,arr[i]);
        
        int start=1;
        int end=max;
        while(start<=end){
            int mid=(end+start)/2;
            int time=calculateTime(arr,mid);
            if(time<=h)
                end=mid-1;
            else
                start=mid+1;
        }
        return start;
    }

    public int calculateTime(int arr[], int speed){
        int total=0;
        for(int i=0;i<arr.length;i++)
            total+=Math.ceil(1.0*arr[i]/speed);
        return total;
    }
}
