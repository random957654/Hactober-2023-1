// Allocate Books
// Idea:
// We need to make sure chapters are assigned to Ayush in such a way that max numbers of chapters read by him in a single day is minimized.

/*
Input: n = 2, m = 4
       10 20 10 30
       
Approach:

max number of chapters assigned to him in a single day is upper bounded by total number of chapters.

sum of time required to read all the chapters = (10+20+10+30) = 70 
Min value will be the max time required to read a chapter : 30

i.e our answer cannot be less than the max page in a book.

Hence our answer must lie in the range [ 30, 70]. we will apply binary search in this range.

10	20	10	30

x = (30+70)/2 = 50    res = 50 (feasible solution) 

10+20 = 30  && 10+30 = 40 
10+20+10 = 40 && 30

to find min solution 

x = (30+49)/2 = 39 (not feasible)

10+20 = 30 && 30+10=40 > 39
10+20+10 = 40 > 39

since for 39 solution is not feasible then for any lower value solution would not be feasible.

so move to right of 39

x = (40+49)/2 = 44 res = 44 (feasible)
10+20 = 30 && 30+10=40 
10+20+10 = 40 && 30

go to left half of 44
x = (40+43)/2 = 41, res = 41(feasible)
10+20 = 30 && 30+10=40 
10+20+10 = 40 && 30

go to left half of 41

x = (40+40)/2 = 40  , res = 40 
10+20 = 30 && 30+10=40 
10+20+10 = 40 && 30

*/

#include <bits/stdc++.h> 
using namespace std;

bool isFeasible(vector<int> &time, int k, long long mid)
{
    long long req = 1, sum = 0;
    for(auto x: time)
    {
        if(x > mid) return false;
        else if(sum+x > mid)
        {
            req++;
            sum = x;
        }
        else
            sum += x;
    }
    return (req <= k);
}
long long allocateBooks(int n, int m, vector<int> time) 
{	
	long long sum = 0;
    int mx = 0;
    for(int i = 0; i < m; i++)
    {
        sum += time[i];
        mx = max(mx, time[i]);
    }

    long long low = mx, high = sum, res = 0;
    while(low <= high)
    {
        long long mid = (low+high)/2;
        if(isFeasible(time, n, mid))
        {
            res = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return res;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> time(m);
    for(int i = 0; i < m; i++) cin>>time[i];
    cout<<allocateBooks(n, m, time);
    return 0;
}
