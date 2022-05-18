/*
 * @Descripttion: 55. 跳跃游戏
 * @Author: AruNi
 * @Date: 2022-05-18 17:21:29
 */

/*
题目：
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。

示例 1：
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

示例 2：
输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
*/

/*
贪心算法：
    把每次跳几步的问题转化为每次可以跳跃的范围，然后判断这个范围能不能覆盖到终点就行了，
    不用在意每次怎么跳，跳几步。
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;      // nums长度为1，就直接到达了
        int cover = 0;
        // 注意：每次只能在cover内移动
        for (int i = 0; i <= cover; i++) {
            // nums[i] + i ：该元素数值补充后的范围
            cover = max(nums[i] + i, cover);
            // 若cover的长度能覆盖到终点，则返回true
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};