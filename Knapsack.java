import java.util.Scanner;

public class Knapsack01_DynPrg {
static int[] p, wt;
static int C, n;

static void knapsack01_DP() {
int i, j, w;
int[][] K = new int[n + 1][C + 1];
// Build table K[][] in bottom up manner
for (i = 0; i &lt;= n; i++) {
for (w = 0; w &lt;= C; w++) {
if (i == 0 || w == 0) {
K[i][w] = 0; //rule[i][w] = 1;
} else if (wt[i] &lt;= w) {
K[i][w] = max(p[i] + K[i - 1][w - wt[i]], K[i - 1][w]);

} else {
K[i][w] = K[i - 1][w];
}
}
}

System.out.println(&quot;The selected items are : &quot;);
int c = C;
int m = n;

while (m &gt; 0)//best subset with weight at most knapsack size
{
if (K[m][c] != K[m - 1][c]) {
System.out.println(&quot;Item &quot; + m+ &quot; (weight:&quot; + wt[m] + &quot;, profit:&quot; + p[m] + &quot;)&quot;);

c = c - wt[m];
}
m--;
}
System.out.println(&quot;Total profit of the items added to knapsack = &quot; + K[n][C]);

System.out.print(&quot;\nIntermediate results \nCapacity:\t&quot;);
for (j=0; j&lt;=C;j++){
System.out.print(j+&quot;\t&quot;);
}
System.out.println();

for (i=0;i&lt;=n;i++){
System.out.print(&quot;Item&quot;+i+&quot;(&quot;+p[i]+&quot;,&quot;+wt[i]+&quot;)\t&quot;);
for (j=0; j&lt;=C;j++){
System.out.print(K[i][j]+&quot;\t&quot;);
}
System.out.println();
}

}

static int max(int a, int b) {
return (a &gt; b) ? a : b;
}

public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
System.out.println(&quot;Enter the number of items: &quot;);

n = sc.nextInt();

System.out.println(&quot;Enter the items profit: &quot;);
p = new int[n + 1];
for (int i = 1; i &lt;= n; i++) { // We store from index 1 to n
p[i] = sc.nextInt();
}

System.out.println(&quot;Enter the items weights: &quot;);
wt = new int[n + 1];
for (int i = 1; i &lt;= n; i++) { // We store from index 1 to n
wt[i] = sc.nextInt();
}

System.out.println(&quot;Enter the maximum capacity: &quot;);
C = sc.nextInt();

System.out.println(&quot;\n\n0/1 Kanpsack using Dynamic Programming&quot;);
knapsack01_DP();

}
}
