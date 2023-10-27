\\Java Program to solve Knapsack problem using Greedy method.

package knap;
import java.util.Scanner;
public class Gknapsack
{
void knapsack(int n, float weight[], float value[], float W)
{
float x[]=new float[20], tp= 0;
int i, u;
u=(int) W;
for (i=0;i< n;i++)
	x[i]= 0;
for (i=0;i< n;i++)
{
	if(weight[i]>u)
		break;
	else
	{
		x[i]=1;
		tp= tp+value[i];
		u=(int) (u-weight[i]);
	}
}
if(i< n)
	x[i]=u/weight[i];
tp= tp + (x[i]*value[i]);
System.out.println("\n------------------------------------------------");
System.out.print("\n weight:");
for(i=0;i< n;i++)
{
	System.out.print(weight[i]+"\t");
}
System.out.print("\n value :");
for(i=0;i< n;i++)
{
	System.out.print(value[i]+"\t");
}
System.out.print("\n x     : ");
for(i=0;i< n;i++)
{
	System.out.print(x[i]+"\t");
}
System.out.println("\n------------------------------------------------");
System.out.println("\n Maximum value that knapsack carry is:" +tp);
System.out.println("\n------------------------------------------------");
}

public static void main(String args[])
{
float weight[]=new float[20], value[]=new float[20], W;
int n, i ,j;
float ratio[]=new float[20], temp;
System.out.println("\n------------------------------------------------");
System.out.println("\n KNAPSACK PROBLEM USING GREEDY APPROACH ");
System.out.println("\n------------------------------------------------");
Scanner s=new Scanner(System.in);
System.out.println("\n Enter number of Objects you want:");
n=s.nextInt();
System.out.println("\n------Enter the weights and values of each object--------");
for (i=0; i< n; i++)
{
	System.out.println("\nEnter weight and value for object:" +(i+1));
	weight[i]=s.nextFloat();
	value[i]=s.nextFloat();
}
System.out.println("\nEnter the capacity of knapsack:");
W=s.nextFloat();
for (i=0; i< n; i++)
{
	ratio[i]=value[i]/weight[i];
}
for(i=0; i< n; i++)
{
	for(j=i+1;j< n; j++)
	{
		if(ratio[i]< ratio[j])
		{
			temp= ratio[j];
			ratio[j]= ratio[i];
			ratio[i]= temp;
			temp= weight[j];
			weight[j]= weight[i];
			weight[i]= temp;
			temp= value[j];
			value[j]= value[i];
			value[i]= temp;
		}
	}
}
Gknapsack k=new Gknapsack();
k.knapsack(n, weight, value, W);
s.close();
}
}
