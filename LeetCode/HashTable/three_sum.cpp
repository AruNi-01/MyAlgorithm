/*
 * @Descripttion: 15. 三数之和
 * @Author: AruNi
 * @Date: 2022-03-31 15:46:34
 */

/*
题目：
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
请你找出所有和为 0 且不重复的三元组。         注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]

示例 2：
输入：nums = []
输出：[]

示例 3：
输入：nums = [0]
输出：[]
*/

//双指针法：此处要用到3个指针，一个指向数组左边，一个指向数组右边，
//还有一个则在左右指针之间移动，判断三个指针指向的值相加是否等于0，前提是排好序的数组
//注意：需要去重，结果中不能有相同的数组
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        //找出a + b + c = 0；指针i在左边，left在中间，right在右边
        //a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            //去重，比如前面算了以-1开头的，后面就不用计算了
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;        //三数之和小了，左指针移动找更大的数
                    //当l++后，这个数和前一个数相同时，去重
                    while (l < r && nums[l] == nums[l - 1]) l++;
                } else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                } else {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    //去重后再进行下一次循环
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    r--;
                    l++;
                }
            }
        }
        return res;
    }
};