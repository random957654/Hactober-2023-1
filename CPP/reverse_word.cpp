// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to reverse the given string
string reverseString(string str)
{
 
    // Reverse str using inbuilt function
    reverse(str.begin(), str.end());
 
    // Add space at the end so that the
    // last word is also reversed
    str.insert(str.end(), ' ');
 
    int n = str.length();
 
    int j = 0;
 
    // Find spaces and reverse all words
    // before that
    for (int i = 0; i < n; i++) {
 
        // If a space is encountered
        if (str[i] == ' ') {
            reverse(str.begin() + j, str.begin() + i);
 
            // Update the starting index
            // for next word to reverse
            j = i + 1;
        }
    }
 
    // Remove spaces from the end of the
    // word that we appended
    str.pop_back();
 
    // Return the reversed string
    return str;
}
 
// Driver code
int main()
{
    string str = "I like this code";
 
    // Function call
    string rev = reverseString(str);
 
    // Print the reversed string
    cout << rev;
    return 0;
}
