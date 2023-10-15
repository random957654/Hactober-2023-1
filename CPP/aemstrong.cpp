#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int n=15, c, num, sum, r, i=1, a=1;
	 while(a <= n)
	 {
		  num = i;
		  c = 0;
		  while(num != 0)
		  {
			   c++;
			   num = num/10;
		  }
		  num = i;
		  sum = 0;
		  while(num != 0)
		  {
			   r = num%10;
			   sum = sum + pow(r, c);
			   num = num/10;
		  }
		  if(sum == i)
		  {
			 cout<<i<<endl;
			  a++;
		  }
		  i++;
	 }

return 0;
}
