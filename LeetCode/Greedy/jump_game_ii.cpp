/*
 * @Descripttion: 45. 跳跃游戏 II
 * @Author: AruNi
 * @Date: 2022-05-18 19:18:24
 */

/*
题目：
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。

示例 1:
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

示例 2:
输入: nums = [2,3,0,1,4]
输出: 2
*/

/*
贪心算法：
    局部最优：当前可移动距离尽可能多走，如果还没到终点，步数再加一
    整体最优：一步尽可能多走，从而达到最小步数
思路虽然是这样，但注意在写代码的时候还不能真的就能跳多远跳远，那样就不知道下一步最远能跳到哪里了。
以 最小的步数 增加覆盖范围，覆盖范围一旦覆盖了终点，得到的就是最小步数！
这里就需要统计两个覆盖范围，当前这一步的最大覆盖和下一步最大覆盖。
如果移动下标达到了当前这一步的最大覆盖最远距离了，还没有到终点的话，那么就必须再走一步来增加覆盖
范围，直到覆盖范围覆盖了终点。  如图：https://img-blog.csdnimg.cn/20201201232309103.png
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0;    // 当前覆盖最远距离下标
        int ans = 0;        // 走的步数
        int nextDistance = 0;   // 下一步覆盖最远距离下标
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance);  // 更新下一步覆盖最远距离下标
            if ( i == curDistance) {            // 遇到当前覆盖最远距离下标，接下来要判断此下标是否为终点
                if (curDistance != nums.size() - 1) {   // 不是终点，要走下一步了
                    ans++;
                    curDistance = nextDistance;     // 更新当前覆盖最远距离下标（相当于加油了）
                    if (nextDistance >= nums.size() - 1) break;     // 下一步的覆盖范围可以达到终点，结束循环
                } else break;   // 是终点，直接退出
            }
        }
        return ans;
    }
};

/* 
方法二：
    针对于方法一的特殊情况，可以统一处理，即：移动下标只要遇到当前覆盖最远距离的下标，
    直接步数加一，不考虑是不是终点的情况。
    想要达到这样的效果，只要让移动下标，最大只能移动到nums.size - 2的地方就可以了
    因为当移动下标指向nums.size - 2时：
        如果移动下标等于当前覆盖最大距离下标，需要再走一步（即ans++），因为最后一步一定是可以到的终点
        如果移动下标不等于当前覆盖最大距离下标，说明当前覆盖最远距离就可以直接达到终点了，不需要再走一步
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int curDistance = 0;
        int ans = 0;
        int nextDistance = 0;
        // 注意这里是小于nums.size() - 1，最大只能移动到nums.size - 2的地方
        for (int i = 0; i < nums.size() - 1; i++) {
            nextDistance = max(nums[i] + i, nextDistance);      // 更新下一步覆盖的最远距离下标
            if (i == curDistance) {     // 遇到当前覆盖的最远距离下标
                curDistance = nextDistance;
                ans++;
            }
        }
        return ans;
    }
};