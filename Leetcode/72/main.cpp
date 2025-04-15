#include <iostream>
using namespace std;

class Solution {
public:
  static int minDistance(string word1, string word2) {
    vector<vector<int>> v(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 1; i < word2.size() + 1; ++i)
      v[0][i] = i;
    for (int i = 1; i < word1.size() + 1; ++i)
      v[i][0] = i;
    for (int i = 1; i < word1.size() + 1; ++i) {
      for (int j = 1; j < word2.size() + 1; ++j) {
        if (word1[i - 1] == word2[j - 1])
          v[i][j] = v[i - 1][j - 1];
        else
          v[i][j] = min({v[i - 1][j], v[i - 1][j - 1], v[i][j - 1]}) + 1;
      }
    }
    return v[word1.size()][word2.size()];
  }
};

int main() {
  string str1 = "ADOBECODEBANC";
  string str2 = "ABC";
  cout << Solution::minDistance(str1, str2) << endl;
  return 0;
}