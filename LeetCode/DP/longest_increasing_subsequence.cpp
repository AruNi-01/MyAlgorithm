/*
 * @Descripttion: 300. 最长递增子序列
 * @Author: AruNi_Lu
 * @Date: 2022-06-08 14:58:36
 */


/*
题目：
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 
示例 1：
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

示例 2：
输入：nums = [0,1,0,3,2,3]
输出：4

示例 3：
输入：nums = [7,7,7,7,7,7,7]
输出：1
*/

/*
注意：此题并不要求子序列是连续的。
DP五部曲：
    1. 确定dp数组和其下标含义
        dp[i]：0到i的子串中，最长递增子序列的长度为dp[i]。
    2. 状态转移方程
        位置i的最长递增子序列等于从0到i-1各个位置的最长递增子序列+1的最大值
        所以 if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        注意：这里不是要dp[i]和dp[j]+1进行比较，而是要每次都取dp[j]+1的最大值，j从0开始遍历。
    3. dp数组的初始化
        每一个i，对应的dp[i]起始值至少都是1，所以dp数组全初始化为1即可。
    4. 确定遍历顺序
        dp[i] 是有0到i-1各个位置的最长升序子序列 推导而来，那么遍历i一定是从前向后遍历。
        j其实就是0到i-1，遍历i的循环在外层，遍历j则在内层，代码如下：
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > result) result = dp[i]; // 取长的子序列
        }
    5. 举例推导dp数组
        输入：[0,1,0,3,2]，dp数组的变化如图：https://img-blog.csdnimg.cn/20210110170945618.jpg
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 1; i < nums.size(); i++){
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            // 取最长的子序列
            if (dp[i] > result) result = dp[i];
        }
        return result;
    }
};