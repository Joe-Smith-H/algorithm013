/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (42.80%)
 * Likes:    1801
 * Dislikes: 0
 * Total Accepted:    383.1K
 * Total Submissions: 894.9K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include<algorithm>
#include<stack>
using namespace std;
    
class Solution {
   public: bool isValid(string s) {
        stack<char> tmp_stack;
        for (char c:s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
               tmp_stack.push(c);
                break;
            case ')':
            {
                if( tmp_stack.empty() || tmp_stack.top()!= '(')
                {
                    return false;
                }
                else
                {
                    tmp_stack.pop();
                }
                break;
            }
            case ']':
             {
                if( tmp_stack.empty() || tmp_stack.top()!= '[')
                {
                    return false;
                }
                else
                {
                    tmp_stack.pop();
                }
                break;
            }
            case '}':
             {
                if( tmp_stack.empty() || tmp_stack.top()!= '{')
                {
                    return false;
                }
                else
                {
                    tmp_stack.pop();
                }
                break;
            }
            default:
                break;
            }
        }
        return tmp_stack.empty();
    }
};
// @lc code=end

