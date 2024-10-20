/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:
输入: strs = [""]
输出: [[""]]
示例 3:
输入: strs = ["a"]
输出: [["a"]]

提示：
1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

//错误版本
vector<vector<string>> solution(vector<string> strs)
{
        pair<int,int> pairs[10000];
        int n=0;
        for(int i=0;i<strs.size();++i)
        {
            int tmp = 0;
            for(int j=0;j<strs[i].size();++j)
            {
                tmp += (strs[i][j] * 26);
            }
            pairs[n++] = pair<int,int>(tmp,i);
        }
        auto cmp=[=](pair<int,int> left,pair<int,int> right)->bool
        {
            return left.first<right.first?true:false;
        };
        sort(pairs,pairs+n,cmp);
        vector<vector<string>> s;
        n=0;
        vector<string> tmp;
        for(int i=0; i<strs.size();++i)
        {
            tmp.push_back(strs[pairs[i].second]);
            cout<<i<<" "<<pairs[i].second<<" ";
            if(pairs[i].first != pairs[i+1].first || i == strs.size())
            {
                cout<<strs[pairs[i].second]<<endl;
                s.push_back(tmp);
                tmp=vector<string>();
            }
        }
        return s;
}

//第二版
vector<vector<string>> solution(vector<string> strs)
{
    {
        unordered_map<string,vector<string>> map;
        for(int i=0;i<strs.size();++i)
        {
            string key = strs[i];
            sort(key.begin(),key.end());
            map[key].push_back(strs[i]);
        }
        vector<vector<string>> s;
        for(auto it=map.begin();it!=map.end();++it)
        {
            s.push_back(it->second);
        }
        return s;
    }
}

int main()
{
    vector<string> strs;
    string tmp; 
    while(cin<<tmp)
    {
        strs.push_back(tmp);
    }
    solution(strs);
    return 0;
}