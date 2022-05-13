// 17. 电话号码的字母组合

/*
题目：
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]
*/

class Solution {
private:
    // 定义一个数组来将数字和字母映射起来
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };
public:
    vector<string> result;
    string s;   // 用于收集叶子节点的结果
    // index 记录遍历第几个数字了，就是用来遍历digits的（题目中给出数字字符串），同时index也表示树的深度。
    void backtrack(const string& digits, int index) {
        // 终止条件
        // 如果index 等于 输入的数字个数（digits.size）了（本来index就是用来遍历digits的）
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }

        // 因为digits是一串数字(string)，所以要先将第index个数字取出来，并且将string类型的数字转为int类型
        int digit = digits[index] - '0';    // 将index指向的数字转为int类型
        string letters = letterMap[digit];   // 取数字对应的字符集
        // 遍历该数字对应的字符集
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);
            backtrack(digits, index + 1);   // 注意index + 1，下一层要处理下一个数字
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return result;
        }
        backtrack(digits, 0);
        return result;
    }
};
