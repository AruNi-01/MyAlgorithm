/*
 * @Descripttion: 1005. K 次取反后最大化的数组和
 * @Author: AruNi
 * @Date: 2022-05-19 20:46:04
 */

/*
题目：
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
    选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
以这种方式修改数组后，返回数组 可能的最大和 。

示例 1：
输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。

示例 2：
输入：nums = [3,-1,0,2], k = 3
输出：6
解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。

示例 3：
输入：nums = [2,-3,-1,5,-4], k = 2
输出：13
解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
*/

/*
贪心算法：
    局部最优：让绝对值大的负数变为正数，当前数值达到最大
    整体最优：整个数组和达到最大。
    如果将负数都转变为正数了，K依然大于0，此时的问题是一个有序正整数序列，如何转变K次正负，让 数组和 达到最大。
这又是一个贪心：
    局部最优：只找数值最小的正整数进行反转，直到k=0，当前数值可以达到最大
    全局最优：整个 数组和 达到最大。
步骤：
    第一步：将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
    第二步：遍历，遇到负数将其变为正数，同时K--
    第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
    第四步：求和
*/
class Solution {
static bool cmp(int a, int b) {
    // 注意要按照绝对值的大小
    return abs(a) > abs(b);
}

public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res = 0;
        // 使用自己的比较规则，降序，因为越小的负数，其正数越大
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        // 将剩余的k用完，若k为奇数，才需要将最后的数转为负数
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;
        for (int a : nums) res += a;
        return res;
    }
};