// CPP program for fast inverse square root.
#include<bits/stdc++.h>
using namespace std;

// function to find the inverse square root
float inverse_rsqrt( float number )
{
const float threehalfs = 1.5F;

float x2 = number * 0.5F;
float y = number;

// evil floating point bit level hacking
long i = * ( long * ) &y;

// value is pre-assumed
i = 0x5f3759df - ( i >> 1 );
y = * ( float * ) &i;

// 1st iteration
y = y * ( threehalfs - ( x2 * y * y ) );

// 2nd iteration, this can be removed
// y = y * ( threehalfs - ( x2 * y * y ) );

return y;
}

// driver code
int main(){

int n = 256;
float f = inverse_rsqrt(n);
cout << f << endl;

return 0;
}
