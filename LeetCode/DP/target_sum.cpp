/*
 * @Descripttion: 494. 目标和
 * @Author: AruNi
 * @Date: 2022-05-30 22:07:47
 */


/*
题目：
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。
对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例：
输入：nums: [1, 1, 1, 1, 1], S: 3
输出：5
解释：
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
一共有5种方法让最终目标和为3。

提示：
    数组非空，且长度不会超过 20 。
    初始的数组的和不会超过 1000 。
    保证返回的最终结果能被 32 位整数存下。
*/

/*
思路：
    想一想，如何使表达式结果为target？
    既然为target，那么一定有 left组合 - right组合 = target。
    left + right = sum，sum是固定的。
    所以公式为：left - (sum - left) = target   ==>  left = (target + sum) / 2
    target是固定的，sum也是固定的，left就可以求出来。
    此时问题就是在集合nums中找出和为left的组合。

    如何转化为01背包问题呢？
    假设加法的总和为x，那么减法的总和就是sum-x。
    所以要求的是 x - (sum - x) = target   ==>    x = (target + sum) / 2
    此时问题转为：装满容量为x的背包，有几种方法。
    (target + sum) / 2 的计算向下取整有没有影响呢？
    例如sum = 5，target = 2，其实就是无解的，和为5的正数怎么转变后再组合也不可能为2。
    所以：if ((target + sum) % 2 == 1) return 0;
    同时如果 target的绝对值已经大于sum了，也是无解的。
    所以：if (abs(target) > sum) return 0;

    再回归到01背包问题，为什么是01背包呢？
    因为每个物品（题目中的1）只用一次！
    这次和之前遇到的背包问题不一样了，之前都是求容量为j的背包，最多能装多少。
    本题则是装满有几种方法。其实这就是一个组合问题了。

dp五部曲：
    1. 确定dp数组和其下标含义
        dp[j] 表示：填满j(包括j) 这么大容积的包，有dp[j]种方法。
    2. 确定递推公式
        有哪些来源可以推出dp[j]呢？
        不考虑nums[i]的情况下，填满容量为j - nums[i]的背包，有dp[j - nums[i]]种方法。
        那么只要搞到nums[i]的话，凑成dp[j]就有dp[j - nums[i]] 种方法。
        例如：dp[j]，j 为5，
            ·已经有一个1（nums[i]） 的话，有 dp[4]种方法 凑成 dp[5]。
            ·已经有一个2（nums[i]） 的话，有 dp[3]种方法 凑成 dp[5]。
            ·已经有一个3（nums[i]） 的话，有 dp[2]中方法 凑成 dp[5]
            ·已经有一个4（nums[i]） 的话，有 dp[1]中方法 凑成 dp[5]
            ·已经有一个5 （nums[i]）的话，有 dp[0]中方法 凑成 dp[5]
        那么凑整dp[5]有多少方法呢，也就是把 所有的 dp[j - nums[i]] 累加起来。
        所以求组合类问题的公式，都是类似这种：dp[j] += dp[j - nums[i]];
        这个公式在后面在讲解背包解决排列组合问题的时候还会用到！
    3. dp数组的初始化
        从递归公式可以看出，在初始化的时候dp[0] 一定要初始化为1，因为dp[0]是在公式中一切递推结果的起源，
        如果dp[0]是0的话，递归结果将都是0。
        dp[0] = 1，理论上也很好解释，装满容量为0的背包，有1种方法，就是装0件物品。
        dp[j]其他下标对应的数值应该初始化为0，从递归公式也可以看出，dp[j]要保证是0的初始值，
        才能正确的由dp[j - nums[i]]推导出来。
    4. 确定遍历顺序
        对于01背包问题一维dp的遍历，nums放在外循环，target在内循环，且内循环倒序。
    5. 举例推导dp数组
        输入：nums:[1,1,1,1,1], target: 3
        bigSize = (target + sum) / 2 = (3 + 5) / 2 = 4
        dp数组状态变化：https://img-blog.csdnimg.cn/20210125120743274.jpg
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if ((target + sum) % 2 == 1) return 0;  // 此时没有方案
        if (abs(target) > sum) return 0;        // 此时没有方案
        int bagSize = (target + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};