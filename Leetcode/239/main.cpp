#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  static vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int index = 0;
    vector<int> result;
    int MAX = INT_MIN;
    for (int i = 0; i < nums.size() - k + 1; ++i) {
      if (i >= index) {
        MAX = INT_MIN;
        for (int j = i; j < i + k; ++j) {
          if (nums[j] >= MAX) {
            MAX = nums[j];
            index = j;
          }
        }
        result.push_back(MAX);
      } else {
        if (nums[i + k - 1] >= nums[index]) {
          result.push_back(nums[i + k - 1]);
          index = i + k - 1;
        } else {
          result.push_back(nums[index]);
        }
      }
    }
    return result;
  }
};

int main() {
  vector<int> nums = {1, -1};
  int k = 1;
  vector<int> result = Solution::maxSlidingWindow(nums, k);
  for (auto &val : result) {
    cout << val << " ";
  }
  cout << endl;
}