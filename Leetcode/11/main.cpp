#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& height)
{
    int left=0;
    int right=height.size()-1;
    int MAX = 0;

    while(left != right)
    {
        int tmp=min(height[left],height[right])*(right-left);
        if(MAX < tmp)
            MAX = tmp;
        if(height[left]<height[right])
            ++left;
        else
            --right;
    }
    return MAX;
}

int main()
{
    int n;
    cin<<n;
    vector<int> height(n);
    for(int i=0;i<n;++i)
    {
        cin>>height[i];
    }
    cout<<solve(height)<<"\n";
    return 0;
}