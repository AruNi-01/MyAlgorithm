/*
 * @Descripttion: 18. 四数之和
 * @Author: AruNi
 * @Date: 2022-04-01 23:07:58
 */

/*
题目：
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 
[nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

    0 <= a, b, c, d < n
    a、b、c 和 d 互不相同
    nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按任意顺序返回答案。

示例 1：
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

示例 2：
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
*/

//双指针法：两层for循环nums[i]+nums[j]为确定值，循环内有left和right下标作为双指针，找出四数之和=target即可
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            //去重
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    //注意：target是随机值，不是0
                    if (nums[i] + nums[j] > target - (nums[l] + nums[r])) {
                        r--;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    } else if (nums[i] + nums[j] < target - (nums[l] + nums[r])) {
                        l++;
                        while (l < r && nums[l] == nums[l - 1]) l++;
                    } else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        l++;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};