/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        
        std::vector<int> lRegistrarOfIndex;
        
        for(auto index = 0; index < nums.size(); ++index) {
            lRegistrarOfIndex.push_back(index);
        }
        
        std::sort(lRegistrarOfIndex.begin(), lRegistrarOfIndex.end(), [=](int a, int b){
            return nums[a] < nums[b];
        });
        
//         for(auto item: lRegistrarOfIndex ) {
//             std::cout<< item << " ";
//         }
        
        int lIndex = 0, rIndex = nums.size() - 1;
        while (lIndex < rIndex) {
            if (nums[lRegistrarOfIndex[lIndex]] + nums[lRegistrarOfIndex[rIndex]] == target) {
                return {lRegistrarOfIndex[lIndex], lRegistrarOfIndex[rIndex]};
            }
            if (target > nums[lRegistrarOfIndex[lIndex]] + nums[lRegistrarOfIndex[rIndex]]) {
                ++lIndex;
            }
            else {
                --rIndex;
            }
        }
        return result;
    }
};
