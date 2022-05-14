// 93. 复原 IP 地址

/*
题目：
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

    例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

 
示例 1：
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]

示例 2：
输入：s = "0000"
输出：["0.0.0.0"]

示例 3：
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/

/*思路：
    和131. 分割回文串类似，都是切割问题！切割问题可以抽象为树型结构，如图：https://img-blog.csdnimg.cn/20201123203735933.png
递归终止条件：
    ip地址只会分成4段，所以不能用切割线切到最后作为终止条件，而是分割的段数作为终止条件。
    pointNum表示逗点数量，pointNum为3说明字符串分成了4段了。
    然后验证一下第四段是否合法，如果合法就加入到结果集里
*/
class Solution {
private:
    vector<string> result;
    // startIndex: 搜索的起始位置，pointNum: 添加'.'号的数量
    void backtrack(string& s, int startIndex, int pointNum) {
        // pointNum=3表示ip地址已经为4段了，判断第四段是否合法，合法就加入结果集里
        if (pointNum == 3) {    // 逗点数量为3时，分割结束
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {    // 判断 [startIndex,i] 这个区间的子串是否合法
                s.insert(s.begin() + i + 1, '.');   // 在i的后面插入一个'.'
                pointNum++;
                backtrack(s, i + 2, pointNum);  // 插入'.'之后下一个子串的起始位置为i+2
                pointNum--; // 回溯
                s.erase(s.begin() + i + 1); // 回溯，删掉'.'
            } else break;   // 不合法，直接结束本层循环
        }
    }

    // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) {  // 0开头的数字不合法
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');      // s[i] - '0' 是将string的数字转为int
            if (num > 255) {    // 大于255了不合法
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return result;   // ip地址最长12位
        backtrack(s, 0, 0);
        return result;
    }
};
