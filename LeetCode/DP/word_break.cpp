/*
 * @Descripttion: 139. 单词拆分
 * @Author: AruNi
 * @Date: 2022-06-3 19:49:35
 */

/*
题目：
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。

示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/

/*
思路：
看到这道题目的时候，应该回想起之前回溯法专题的一道题目回溯算法：131. 分割回文串，
就是枚举字符串的所有分割情况。枚举分割后的所有子串，判断是否回文。
本道是枚举分割所有字符串，判断是否在字典里出现过。
回溯法C++代码：
class Solution {
private:
    bool backtracking (const string& s, const unordered_set<string>& wordSet, int startIndex) {
        if (startIndex >= s.size()) {
            return true;
        }
        for (int i = startIndex; i < s.size(); i++) {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, i + 1)) {
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return backtracking(s, wordSet, 0);
    }
};
时间复杂度：O(2^n)，因为每个单词有两个状态，切割和不切割。 LC中是超时的！

其实应该用背包问题来解决此题。单词就是物品，字符串s就是背包，单词能否组成
字符串s，就是问物品能不能把背包装满。
拆分时可以重复使用字典中的单词，说明这就是一个完全背包。
DP五部曲：
    1. 确定dp数组和其下标含义
        dp[i]：字符串长度为i，当dp[i]为true时，表示可以拆分一个或者多个在字典中出现的单词。
    2. 确定递推公式
        如果确定dp[j]为true，且[j,i]这个区间的子串出现在字典里，那么dp[i]一定是true。（j<i)
        所以递推公式是 if([j,i]) 这个区间的子串出现在字典里 && dp[j]=true，那么dp[i]=true。
    3. dp数组的初始化
        从递推公式可以看出，dp[i]的状态依靠dp[j]是否为true，那么dp[0]就是递推的根基，dp[0]一定要
        为true，否则递推下去后面都是false了。
        那么，dp[0]有没有实际意义呢？dp[0]表示如果字符串为空的话，说明出现在字典里。
        但是题目中说了非空字符串s，所以测试数据中不会有i为0的情况，所以dp[0]只是为了推导公式。
        下标非0的dp[i]初始化为false，只要没有被覆盖说明都是不可拆分为一个或者多个在字典中出现的单词。
    4. 确定遍历顺序
        题目中说是拆分为一个或多个在字典中出现的单词，所以这是完全背包。
        还要讨论两层for循环的前后循序。
        如果求组合数就是外层for循环遍历物品，内层for遍历背包。如果求排列数就是外层for遍历背包，内层for循环遍历物品。
        本题最终要求的是是否都出现过，所以对出现单词集合里的元素是组合还是排列，并不在意！
        那么本题使用求排列的方式，还是求组合的方式都可以。所以for循环按什么顺序都可以。
        但本题还有特殊性，因为是要求子串，最好是遍历背包放在外循环，将遍历物品放在内循环。
        如果要是外层for循环遍历物品，内层for遍历背包，就需要把所有的子串都预先放在一个容器里。（如果不理解的话，可以尝试这么写一写）
        所以最终选择的遍历顺序为：遍历背包放在外循环，将遍历物品放在内循环。内循环从前到后。
    5. 举例推导dp数组
        以输入: s = "leetcode", wordDict = ["leet", "code"]为例，dp状态如图：https://img-blog.csdnimg.cn/20210202162652727.jpg
        dp[s.size()]就是最终结果。
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 将词典转成set集合，方便后面查找 截取s的子串 是否在字典中
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        // i <= s.size() 是因为后面substr截取的时候包前不包后
        for (int i = 0; i <= s.size(); i++) {   // 遍历背包
            for (int j = 0; j < i; j++) {       // 遍历物品
                string word = s.substr(j, i - j);   // substr(起始位置，截取的个数)，将[j,i)区间的字符截取出来
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};