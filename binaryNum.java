import java.util.*;
class binary
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the n");
        int n=sc.nextInt();int k=0;
        int a[]=new int[100];
        while(n!=0)
        {
            int d=n%2;
            a[k]=d;
            k++;
            n=n/2;
        }
        for(int i=k;i>=0;i--)
        {
            System.out.print(a[i]);
        }
    }
}