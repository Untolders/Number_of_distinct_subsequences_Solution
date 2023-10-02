************************************************************************************ Question  ***********************************************************************************************************************************

Given a string consisting of lower case English alphabets, the task is to find the number of distinct subsequences of the string
Note: Answer can be very large, so, ouput will be answer modulo 109+7.

Example 1:

Input: 
s = "gfg"
Output: 
7
Explanation: 
The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .
Example 2:

Input: 
s = "ggg"
Output: 
4
Explanation: 
The four distinct subsequences are "", "g", "gg", "ggg".
Your task:
You do not need to read any input or print anything. The task is to complete the function distinctSubsequences(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |s| ≤ 105
s contains lower case English alphabets






************************************************************************************  Solution  ***********************************************************************************************************************************
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
 
         // Your code goes here
        const int MOD = 1000000007;
        int n = s.length();
        vector<long long> dp(n + 1, 0);
    
        // Initialize dp array
        dp[0] = 1;
    
        // Create a mapping of character to its last occurrence position
        vector<int> lastPosition(26, -1);
    
        for (int i = 1; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1]) % MOD;
    
            // If the current character has occurred before, subtract the count of subsequences
            if (lastPosition[s[i - 1] - 'a'] != -1) {
                dp[i] -= dp[lastPosition[s[i - 1] - 'a']];
                dp[i] = (dp[i] + MOD) % MOD; // Ensure non-negative result
            }
    
            lastPosition[s[i - 1] - 'a'] = i - 1;
        }
    
        return (dp[n] + MOD) % MOD; // Ensure non-negative result
    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends

