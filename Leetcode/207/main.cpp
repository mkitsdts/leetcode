/*
�����ѧ�ڱ���ѡ�� numCourses �ſγ̣���Ϊ 0 �� numCourses - 1 ��
��ѡ��ĳЩ�γ�֮ǰ��ҪһЩ���޿γ̡� ���޿γ̰����� prerequisites ���������� prerequisites[i] = [ai, bi] ����ʾ���Ҫѧϰ�γ� ai �������ѧϰ�γ� bi ��
���磬���޿γ̶� [0, 1] ��ʾ����Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��
�����ж��Ƿ����������пγ̵�ѧϰ��������ԣ����� true �����򣬷��� false ��

ʾ�� 1��
���룺numCourses = 2, prerequisites = [[1,0]]
�����true
���ͣ��ܹ��� 2 �ſγ̡�ѧϰ�γ� 1 ֮ǰ������Ҫ��ɿγ� 0 �����ǿ��ܵġ�

ʾ�� 2��
���룺numCourses = 2, prerequisites = [[1,0],[0,1]]
�����false
���ͣ��ܹ��� 2 �ſγ̡�ѧϰ�γ� 1 ֮ǰ������Ҫ�����?�γ� 0 ������ѧϰ�γ� 0 ֮ǰ���㻹Ӧ����ɿγ� 1 �����ǲ����ܵġ�

��ʾ��
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
prerequisites[i] �е����пγ̶� ������ͬ
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