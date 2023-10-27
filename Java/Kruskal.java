\\Kruskal algorithm using Union-find method
package krusk;

import java.util.Scanner;
public class Kruskal {
static int n, parent[], a[][];

public static int find(int p)
{
while(parent[p]!=0)
{
	p=parent[p];
}
return p;
}

public static void union(int i, int j)
{
	if(i<j)
		parent[i]=j;
	else
		parent[j]=i;
}

public static void kruskal()
{ 
	int u=0,v=0,min,k=0,i,j,sum=0;
	while(k<n-1)
	{ 
		min=999;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++) if(a[i][j]<min && i!=j)
			{ 
				min=a[i][j];
				u=i;
				v=j;
			}
		i=find(u);
		j=find(v);
		if(i!=j)
		{
			union(i,j);
			System.out.println((u+1)+","+(v+1)+"=>"+a[u][v]);
			sum=sum+a[u][v];
			k++;
		}
		a[u][v]=a[v][u]=999;
	}
	System.out.println("The cost of minimum spanning tree = "+sum);
}

public static void main(String[] args)
{
int i,j;
System.out.println("Enter the number of vertices of the graph");
Scanner in=new Scanner(System.in);
n=in.nextInt();
a=new int[n][n];
parent=new int[n];
System.out.println("Enter the weighted matrix");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		a[i][j]=in.nextInt();
	}
}
kruskal();
in.close();
}
}
