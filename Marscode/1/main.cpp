// ÕÒµ¥¶ÀµÄÊı
#include <iostream>
#include <vector>

int solution(std::vector<int> cards) {
  // Edit your code here
  int nums[1000] = {0};
  for (auto n = 0; n < cards.size(); ++n) {
    ++nums[cards[n]];
  }
  for (auto i = 0; i < 1000; ++i) {
    if (nums[i] == 1) {
      return i;
    }
  }
  return 0;
}

int main() {
  // Add your test cases here

  std::cout << (solution({1, 1, 2, 2, 3, 3, 4, 5, 5}) == 4) << std::endl;
  std::cout << (solution({0, 1, 0, 1, 2}) == 2) << std::endl;
  return 0;
}