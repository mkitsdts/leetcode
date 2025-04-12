#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (auto num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (auto num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

int main(){
    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    cout << Solution::longestConsecutive(nums) << endl;
    return 0;
}