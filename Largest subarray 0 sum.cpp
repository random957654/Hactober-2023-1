
//SOLUTION
  class Solution
{

 
public:
 
int maxLen (vector < int >&A, int n) 
 
  {
    
 
int maxi = 0;
    
 
int sum = 0;
    
 
unordered_map < int, int >m;
    
 
for (int i = 0; i < n; i++)
      
 
      {
	
 
sum += A[i];
	
 
if (sum == 0)
	  
 
	  {
	    
 
maxi = i + 1;
	  
 
}
	
 
	else
	  
 
	  {
	    
 
if (m.find (sum) != m.end ())
	      
 
	      {
		
 
maxi = max (maxi, i - m[sum]);
	      
 
}
	    
 
	    else
	      
 
	      {
		
 
m[sum] = i;
	      
 
}
	  
 
}
      
 
}
    
 
return maxi;
  
 
}

 
};
