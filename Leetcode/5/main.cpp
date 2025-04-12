#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    static string longestPalindrome(string s) 
    {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        int max_len = 1, left = 0, right = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            dp[i][i] = 1;
            if(i < s.size() - 1 && s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
                max_len = 2;
                left = i;
                right = i + 1;
            }
        }
        for(int len = 3;len <= s.size(); ++len)
        {
            for(int i = 0; i + len - 1 < s.size(); ++i)
            {
                int j = i + len - 1;
                if(s[i] == s[j] && dp[i+1][j-1] == 1)
                {
                    dp[i][j] = 1;
                    max_len = len;
                    left = i;
                    right = j;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
}

int main()
{
    string s;
    cin >> s;
    cout << Solution::longestPalindrome(s) << endl;
    return 0;
}