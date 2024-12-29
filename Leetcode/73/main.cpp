#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static void setZeroes(vector<vector<int>>& matrix) 
    {
        vector<int> col;
        int col_size = matrix[0].size();
        int row_size = matrix.size();
        bool is;
        for(int i = 0; i < row_size; i++)
        {
            is = false;
            for(int j = 0; j < col_size; j++)
                if(!matrix[i][j])
                {
                    col.push_back(j);
                    is = true;
                }   
            if(is)
                matrix[i] = vector<int>(col_size, 0);
        }
        for(auto i : col)
        {
            for(int j = 0; j < row_size; j++)
                matrix[j][i] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    Solution::setZeroes(matrix);
    for(auto i : matrix)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}