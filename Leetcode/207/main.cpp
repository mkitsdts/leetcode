/*
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则必须先学习课程 bi 。
例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

示例 1：
输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。

示例 2：
输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
输出：false
解释：总共有 2 门课程。学习课程 1 之前，你需要先完成?课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。

提示：
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
prerequisites[i] 中的所有课程对 互不相同
*/
#include <iostream>
using namespace std;

class Solution
{
public:
    static bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int map[numCourses][numCourses]={0};
        int line[numCourses]={0};
        int column[numCourses]={0};
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            for(int j = 0; j < prerequisites[i].size(); ++j)
            {
                map[prerequisites[i][0]][prerequisites[i][1]] = 1;
                line[prerequisites[i][0]]=1;
                column[prerequisites[i][1]]=1;
                if(map[prerequisites[i][1]][prerequisites[i][0]] == 1)
                    return false;
            }
        }
        for(int i = 0; i < numCourses; ++i)
        {
            if(line[i] == 0 && column[i] == 0)
                return true;
        }
        return false;
    }
};

int main()
{
    int numCourses;
    cin >> numCourses;
    return 0;
}