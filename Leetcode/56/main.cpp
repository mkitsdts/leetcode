#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    static vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(auto i = 0; i < intervals.size(); i++){
            if(intervals[i][0] <= result.back()[1]){
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = Solution::merge(intervals);
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}