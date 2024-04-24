// Leetcode Problem: https://leetcode.com/problems/contains-duplicate/
#include <iostream>
#include <vector>
using namespace std;

// This will give TLE as dataset size is 10^5
bool containsDuplicate(vector<int>& nums) {
            
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(nums[i] == nums[j])
                    return true;
            }
        }
        
        return false;
}

int main()
{
    vector<int> nums = {1,2,3,1,3,2,4};

    bool b = containsDuplicate(nums);

    cout << b;

    return 0;
}