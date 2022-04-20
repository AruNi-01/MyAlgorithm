/*
 * @Descripttion: 1. 两数之和
 * @Author: AruNi
 * @Date: 2022-03-31 15:06:19
 */

/*
题目：
给定一个整数数组nums和一个整数目标值 target，请你在该数组中找出 和为目标值 target的那两个整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
*/

//思路：用Map集合，key存数，value存下标；用target-当前遍历的数值是否在map中存在来判断两数之和是否为target
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;    //不用数值key有序，选择unordered_map 效率更高
        for (int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);      //返回一个迭代器
            //若在map中找到该数，直接返回
            if (iter != map.end()) {
                return {iter->second, i};   //iter->second是map集合的value
            }
            map.insert(pair<int, int>(nums[i], i));     //遍历一个数就将该数添加到map集合中
        }
        return {};
    }
};