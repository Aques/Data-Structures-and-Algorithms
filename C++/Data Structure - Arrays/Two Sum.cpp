// Question Link : https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
using namespace std;

vector<int> TwoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(nums[i] + nums[j] == target)
                return {i,j};
        }
    }
    
    return {};
}

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> ans = TwoSum(nums,target);

    for(int i : ans)
        cout << i << " ";

    return 0;
}