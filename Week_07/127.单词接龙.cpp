/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (43.22%)
 * Likes:    409
 * Dislikes: 0
 * Total Accepted:    56.4K
 * Total Submissions: 130.2K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start
#if 1
class Solution{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        //加入所有节点，访问过一次，删除一个。
        unordered_set<string> s;
        for (auto &i : wordList) s.insert(i);

        queue<pair<string, int>> q;
        //加入beginword
        q.push({beginWord, 1});

        string tmp; //每个节点的字符
        int step;    //抵达该节点的step

        while ( !q.empty() ){
            if ( q.front().first == endWord){
                return (q.front().second);
            }
            tmp = q.front().first;
            step = q.front().second;
            q.pop();

            //寻找下一个单词了
            char ch;
            for (int i = 0; i < tmp.length(); i++){
                ch = tmp[i];
                for (char c = 'a'; c <= 'z'; c++){
                    //从'a'-'z'尝试一次
                    if ( ch == c) continue;
                    tmp[i] = c ;
                    //如果找到的到
                    if (  s.find(tmp) != s.end() ){
                        q.push({tmp, step+1});
                        s.erase(tmp) ; //删除该节点
                    }
                tmp[i] = ch; //复原
                }
               
            }
            
        }
        return 0;
    }
};
#endif
