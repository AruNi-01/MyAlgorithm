/*
 * @Descripttion: 49. 字母异位词分组
 * @Author: AruNi
 * @Date: 2022-03-29 22:58:39
 */

/*
题目：
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

示例 2:
输入: strs = [""]
输出: [[""]]

示例 3:
输入: strs = ["a"]
输出: [["a"]]
*/

//思路：可以用一个map集合将排序后的字符串存起来，key为字符串，value为下标（一组字母异位词对应一个下标），map集合的value可以重复
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        //key是排序后的字符串，对于字母异位词来说，排序后字符串的相同的，value是同一组字母异位词的下标
        map<string, int> mp;
        int index = 0;      //作为一组字母异位词的下标
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            //对字符串排序
            sort(strs[i].begin(), strs[i].end());
            //排序后的字符串如果已经在map中存在，则直接添加到对应下标的字符串组中
            //vector中find函数是寻找一个数据，当这个数据存在返回当前位置的迭代器，不存在则返回end函数返回的迭代器
            if (mp.find(strs[i]) != mp.end()) {
                //结果是一个二维数组，mp[strs[i]]是取该strs[i]字符串在map中对应的字母异位词的下标，result[mp[strs[i]]]是结果中该字母异位词在result中的下标
                //.push_back(temp)就是把这个字符串添加进该字符串组下标的位置中
                result[mp[strs[i]]].push_back(temp);
            } else {
                //如果map中没有该字符串，则开辟一个组合
                mp[strs[i]] = index;    //该字符串所对应的下标为新的index
                result.push_back({temp});       //在结果中添加该字符串，{}作为一个组，后面有该字符串所对应的字母异位词直接加入该组
                index++;
            }
        }
        return result;
    }
};