/*
 * @Descripttion: 213. 打家劫舍 II
 * @Author: AruNi_Lu
 * @Date: 2022-06-04 21:57:55
 */


/*
题目：
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋
和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

示例 1：
输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

示例 2：
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 3：
输入：nums = [1,2,3]
输出：3
*/

/*
思路：
这道题目和 198.打家劫舍 是差不多的，唯一区别就是成环了。
对于一个数组，成环的话主要有如下三种情况：
    ·情况一：不考虑首尾元素
        下标：0   1   2   3   4
    nums[i]: 1   [6   1  9]   1
    ·情况二：不考虑尾元素
        下标：0   1   2   3   4
    nums[i]: [1  6   1   9]   1
    ·情况三：不考虑首元素
        下标：0   1   2   3   4
    nums[i]: 1   [6   1   9   1]
注意这里用的是"考虑"，例如情况三，虽然是考虑包含尾元素，但不一定要选尾部元素！ 
对于情况三，取nums[1] 和 nums[3]就是最大的。
而情况二 和 情况三 都包含了情况一了，所以只考虑情况二和情况三就可以了。

其实这是一个思想：可以把环拆成两列，一列从0到n-2(忽略尾)，另一列从1到n-1(忽略首)。然后返回两个结果最大的。

分析到这里，本题其实比较简单了。 剩下的和 198.打家劫舍 就是一样的了。
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int res1 = robRange(nums, 0, nums.size() - 2);  // 情况二
        int res2 = robRange(nums, 1, nums.size() - 1);  // 情况三
        return max(res1, res2);
    }

    // 198.打家劫舍的逻辑
    int robRange(vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};