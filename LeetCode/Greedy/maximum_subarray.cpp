/*
 * @Descripttion: 53. 最大子序和
 * @Author: AruNi
 * @Date: 2022-05-17 21:39:21
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
贪心算法：
    局部最优：当前 “连续和” 为负数的时候立刻放弃，从下一个元素重新计算“连续和”，
             因为负数加上下一个元素后 “连续和” 只会越来越小。
    全局最优：选取最大“连续和”
    局部最优的情况下，并记录最大的 “连续和”，可以推出全局最优。

代码实现：
    遍历nums，从头开始用count累积，如果count一旦加上nums[i]变为负数，那么就应该
    从nums[i+1]开始从0累积count了，因为已经变为负数的count，只会拖累总和。
    区间的终止位置，就是如果count取到最大值了，及时记录下来：if(count > result) result = count;
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;   // 先将结果初始化最int类型的最小值，防止nums全是很小的数
        int count = 0;  // 用于记录连续子串的和
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            result = result < count ? count : result;   // 取区间累计的最大值（相当于不确定最大子序的终止位置）
            if (count <= 0) count = 0;  // 当子串和为负数时，直接重置（相等于重置最大子序的起始位置）
        }
        return result;
    }
};

// 本题也可用DP，在DP目录中有此题