/*
 * @Descripttion: 283. 移动零
 * @Author: AruNi
 * @Date: 2022-03-20 22:58:01
 */

/*
题目：
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2:
输入: nums = [0]
输出: [0]
*/
class Solution {
public:
    /*
    用双指针法，先将不是零的数保存下来，同时记录数组中0的个数，最后在数组后面补上相应个数的0即可
    */
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int slowIndex = 0;
        int zero = 0;
        for (int fastIndex = 0; fastIndex < size; fastIndex++) {
            if (nums[fastIndex] != 0) {
                nums[slowIndex++] = nums[fastIndex];
            } else {
                zero++;
            }
        }
        for (int j = zero; j > 0; j--) {
            nums[size-j] = 0;
        }
    }
};