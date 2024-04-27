// Leetcode Problem : https://leetcode.com/problems/rotate-array/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define METHOD 2

void rotate(vector<int>& nums, int k) {

#if METHOD == 1 // Using extra space

    int n = nums.size();

    vector<int> ans(n);

    for(int i = 0; i < n; i++)
    {
        ans[(i + k) % n] = nums[i];
    }

    for(int i = 0; i < n; i++)
    {
        nums[i] = ans[i];
    }

#elif METHOD == 2 // Reverse array

    // [1,2,3,4,5,6,7], k = 3
    // [5,6,7,1,2,3,4]
    // This can be seen as pop back and push front operation
    // But how can we do it efficiently?
    // If we see closely then last element becomes 0th + kth element of start,
    // second last becomes 0th + k-1th element and so on
    // So if we can somehow place last element in kth place and second last in k-1th place
    // and so on then our work is half done. (We haven't talked about starting elements yet)
    // So first thing that comes to mind is taking element out from array and inserting in beginning
    // but its inefficient, next that comes to mind is doing swapping. Hmm lets see..
    // Should we have do a two pointer approach? 1 pointer on last element and another on kth element? Decrement both pointers? But this will effect the order of starting n-k elements. Ok lets stop here and see whats going to happen to first n-k elements.
    // All the n-k elements are going to be shifted k index ahead. Its not much useful.
    // Ok so a new perspective... Task is to insert an element at any given position with using only push_back and swapping.
    // So lets see, given an array [1,2,3,4] if we want to insert 5 at index 0 then what can be done?
    // As we have only push_back method to insert 5. So what to do before doing a push_back?
    // We want [5,1,2,3,4] which can be broken into 4 steps [1,2,3,4] -> [4,3,2,1]
    // -> [4,3,2,1,5] -> [5,1,2,3,4]
    // So we have done reverse -> push_back->reverse
    // Now what if we want to insert at position 1?
    // [1,2,3,4] -> [1,4,3,2] -> [1,4,3,2,5] -> [1,5,2,3,4]
    // So we have done reverse of elements from index 1 -> push_back -> reverse of elements from index 1
    // What do to if 2 elements are to be inserted at index 1?
    // This is tricky but with our simple algorithm we can understand 1 thing
    // We have to push elements in reverse order in which they are to be inserted due to last reverse
    // So suppose we have array [1,2,3,4] and [5,6] are to be inserted at position 1
    // [1,2,3,4] -> [1,4,3,2] -> [1,4,3,2,6] -> [1,4,3,2,6,5] -> [1,5,6,2,3,4]
    // So lets back to our question.
    // Now we will see our given array with new perspective. 
    // Given an array of n elements break it down into 2 arrays
    // 1st array with first n-k elements and 2nd array with last k elements.
    // Our task is to insert these k elements to front using only push_back and swapping.
    // So first step is swap first n-k elements. Then insert k elements in reverse order. Then reverse the whole array.
    // As we already have elements inserted we can do simple thing, reverse(first n-k elements),
    // reverse(last k elements) (This will work like reverse push back), reverse(whole array)
    // Here goes the code
    
    int n = nums.size();
    
    k = k % n; // Corner case that k can be larger than n
    
    std::reverse(nums.end()-k, nums.end());
    std::reverse(nums.begin(), nums.begin() + (n-k));
    std::reverse(nums.begin(), nums.end());
    

#endif

}

int main()
{
    vector<int> nums = {1,3,5,7,9};
    int k = 2;

    rotate(nums,k);

    for(int i : nums)
        cout << i << " ";

    return 0;
}