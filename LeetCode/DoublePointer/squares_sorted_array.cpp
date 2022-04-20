/*
 * @Descripttion: 977. 有序数组的平方
 * @Author: AruNi
 * @Date: 2022-03-20 23:02:27
 */

/*
题目：
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
*/


/*双指针法：数组是递增的，只不过平方后负数可能成为最大数，
    但是平方后，最大值一定在数组的两端，所以只需要将双指针分别
    指向左右两边，依次比较左右两边的值，哪个大就取哪个，用一个
    新的数组倒着装。    
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int k = nums.size() - 1;
        vector<int> res(nums.size());
        while(left <= right) {
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                res[k--] = nums[left] * nums[left];
                left++;
            } else {
                res[k--] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
};


//暴力解法
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};
