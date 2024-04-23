// Question Link : https://leetcode.com/problems/maximum-subarray/
#include <iostream>
#include <vector>
using namespace std;

#define METHOD 2
int maxSubArray(vector<int>& nums) {

#if METHOD == 1 // Naive Approach

    int sum = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        int temp = nums[i];
        sum = max(sum,temp);

        for(int j = i+1; j < n; j++)
        {
            temp += nums[j];
            sum = max(sum,temp);    
        }
    }

    return sum;

#elif METHOD == 2 // Kadanes Algorithm
    
    int sum = nums[0];
    int n = nums.size();

    int temp = 0;

    for(int i = 0; i < n; i++)
    {
        temp = max(nums[i],temp + nums[i]);

        sum = max(sum,temp);
    }

    return sum;

#endif
    }

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int ans = maxSubArray(nums);

    cout << ans;

    return 0;
}