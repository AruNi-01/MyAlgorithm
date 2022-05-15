/*
 * @Descripttion: 491. 递增子序列
 * @Author: AruNi
 * @Date: 2022-05-15 22:17:03
 */

/*
题目：
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

 

示例 1：

输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

示例 2：

输入：nums = [4,4,3,2,1]
输出：[[4,4]]
*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    // 一个元素不能重复使用，所以需要startIndex，调整下一层递归的起始位置
    void backtrack(vector<int>& nums, int startIndex) {
        // 要求递增子序列大小至少为2
        if (path.size() > 1) {
            result.push_back(path);
            // 注意这里不要return，因为要取树上的所有节点
        }

        // 去重：同一父节点下的同层使用过的元素就不能在使用了
        unordered_set<int> uset;    // 使用set对本层元素进行去重
        for (int i = startIndex; i < nums.size(); i++) {
            // 如果nums[i]元素值小于path中最后一个元素的值，则说明不是递增的，跳过此数
            // 或者set集合中找到了与本层相同的值，也跳过
            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]);   // 记录这个元素在本层用过，本层后面不能再用
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
            /*
            注意：unordered_set<int> uset; 是记录本层元素是否重复使用，
            新的一层uset都会重新定义（清空），uset只负责本层，不用回溯。
            */
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};

/*
优化：
以上代码用我用了unordered_set<int>来记录本层元素是否重复使用。

其实用数组来做哈希，效率就高了很多。

注意题目中说了，数值范围[-100,100]，所以完全可以用数组来做哈希。

程序运行的时候对unordered_set 频繁的insert，unordered_set需要做哈希映射（也就是把key通过hash function
映射为唯一的哈希值）相对费时间，而且每次重新定义set，insert的时候其底层的符号表也要做相应的扩充，也是费事的。
*/
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
        }
        int used[201] = {0}; // 这里使用数组来进行去重操作，题目说数值范围[-100, 100]
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) || used[nums[i] + 100] == 1) {
                    continue;
            }
            // [nums[i] + 100]是因为负数不能做数组的index，所以集体index+100
            used[nums[i] + 100] = 1;    // 记录这个元素在本层用过了，本层后面不能再用了；
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};