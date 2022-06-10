/*
 * @Descripttion: 53. 最大子序和
 * @Author: AruNi_Lu
 * @Date: 2022-06-10 16:19:23
 */

/*
题目：
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。
 
示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：
输入：nums = [1]
输出：1

示例 3：
输入：nums = [5,4,-1,7,8]
输出：23
*/

/*
本题使用贪心算法也可以解，在贪心中有此题 贪心算法：53. 最大子序和
这次用动态规划的思路再来分析一次。DP五部曲：
    1. 确定dp数组（dp table）以及下标的含义
        dp[i]：包括下标i之前的最大连续子序列和为dp[i]。
    2. 确定递推公式
        dp[i]只有两个方向可以推出来：
            dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
            nums[i]，即：从头开始计算当前连续子序列和
        一定是取最大的，所以dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    3. dp数组的初始化
        从递推公式可以看出来dp[i]是依赖于dp[i - 1]的状态，dp[0]就是递推公式的基础。
        dp[0]应该是多少呢?  根据dp[i]的定义，很明显dp[0]应为nums[0]即dp[0] = nums[0]。
    4. 确定遍历顺序
        递推公式中dp[i]依赖于dp[i - 1]的状态，需要从前向后遍历。
    5. 举例推导dp数组
        以示例一为例，输入：nums = [-2,1,-3,4,-1,2,1,-5,4]，对应的dp状态如图： https://img-blog.csdnimg.cn/20210303104129101.png
        注意最后的结果不是dp[nums.size() - 1]， 而是dp[6]。
        在回顾一下dp[i]的定义：包括下标i之前的最大连续子序列和为dp[i]。
        那么我们要找最大的连续子序列，就应该找每一个i为终点的连续最大子序列。
        所以在递推公式的时候，可以直接选出最大的dp[i]，用一个result变量记录。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > result) result = dp[i];
        }
        return result;
    }
};