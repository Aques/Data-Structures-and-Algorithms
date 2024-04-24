// Question Link : https://leetcode.com/problems/move-zeroes/
#include <iostream>
#include <vector>
using namespace std;

#define METHOD 2
void moveZeroes(vector<int>& nums) {

#ifdef METHOD == 1 // Temp vector

    vector<int> ans;
    int zero = 0;
    
    for(int i : nums)
    {
        if(i == 0)
            zero++;
        else
            ans.push_back(i);
    }
    
    while(zero--)
        ans.push_back(0);
    
    for(int i = 0; i < nums.size(); i++)
        nums[i] = ans[i];

#elif METHOD == 2 // No Extra Vector

    int j = 0;
    int n = nums.size();
    
    while(j < n && nums[j] != 0)
        j++;
    
    for(int i = j + 1; i < n; i++)
    {
        if(nums[i] != 0)
        {
            swap(nums[i],nums[j]);
            j++;
        }
    }

#endif 

}

int main()
{
    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);

    for(int i : nums)
        cout << i << " ";

    return 0;
}