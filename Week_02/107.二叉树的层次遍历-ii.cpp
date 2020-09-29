/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (66.34%)
 * Likes:    294
 * Dislikes: 0
 * Total Accepted:    78.1K
 * Total Submissions: 117.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         queue<TreeNode*> tmp_queue ;
        vector<vector<int>> wrapList ;
        
        if(root == NULL) return wrapList;
        
        tmp_queue.push(root);
        while(!tmp_queue.empty()){
            int levelNum = tmp_queue.size();
            vector<int> subList;
            for(int i=0; i<levelNum; i++) {
                if(tmp_queue.front()->left != NULL) tmp_queue.push(tmp_queue.front()->left);
                if(tmp_queue.front()->right != NULL) tmp_queue.push(tmp_queue.front()->right);
                subList.push_back(tmp_queue.front()->val);
                tmp_queue.pop();
            }
            wrapList.push_back(subList);
            
        }
        reverse(wrapList.begin(), wrapList.end());
        return wrapList;
    }
};
// @lc code=end

