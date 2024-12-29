#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

//刚开始写的错误版本
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

//看完答案后写的版本
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