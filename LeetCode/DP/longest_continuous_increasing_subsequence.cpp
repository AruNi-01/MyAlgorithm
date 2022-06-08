/*
 * @Descripttion: 674. 最长连续递增序列
 * @Author: AruNi_Lu
 * @Date: 2022-06-08 15:23:50
 */


/*
题目：
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，
都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 
就是连续递增子序列。

示例 1：
输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 

示例 2：
输入：nums = [2,2,2,2,2]
输出：1
解释：最长连续递增序列是 [2], 长度为1。
*/

/*
思路：
    相比于 300. 最长递增子序列，就是变成了连续递增的子序列。大致思路一样！
    区别在于递归公式上，因为本题要求连续递增子序列，所以就必要比较nums[i + 1]与nums[i]，
    而不用去比较nums[j]与nums[i] （j是在0到i之间遍历）。
    如果 nums[i + 1] > nums[i]，那么以 i+1 为结尾的数组的连续递增的子序列长度 一定等于 
    以i为结尾的数组的连续递增的子序列长度 + 1。即：dp[i + 1] = dp[i] + 1;

*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) dp[i + 1] = dp[i] + 1;
            if (dp[i + 1] > result) result = dp[i + 1];
        }
        return result;
    }
};