#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> hash(128, 0);
        int left = 0, right = 0, max_len = 0;
        while(right < s.size() && left < s.size())
        {
            bool is=true;
            while(right<s.size())
            {
                if(hash[s[right]] == 0)
                {
                    ++hash[s[right]];
                    ++right;
                    if(right==s.size())
                    {
                        max_len=max(max_len, right-left);
                        return max_len;
                    }
                }
                else
                {
                    is = false;
                    max_len = max(max_len, right-left);
                    break;
                }
            }
            if(is)
            {
                max_len = max(max_len, right-left);
            }
            --hash[s[left]];
            ++left;
        }
        return max_len;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}