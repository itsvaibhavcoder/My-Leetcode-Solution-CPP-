/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.


Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109  

*/

class Solution {
private:
    int first(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        
        int ans = -1;
        while(s<=e){
             int mid = s+(e-s)/2;
            if(nums[mid]==target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid] <target){
                   s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    
int last(vector<int>&nums, int target){
    int ans = -1;
    int s = 0;
    int e = nums.size()-1;
    
    while(s<=e){
        int mid = s+(e-s)/2;
        if(nums[mid] == target){
            ans = mid;
             s = mid+1;
        }
        else if(nums[mid]<target){
               s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> req;
        req.push_back(first(nums, target));
        req.push_back(last(nums, target));
        return req;
    }
};
