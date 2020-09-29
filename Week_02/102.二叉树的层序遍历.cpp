/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (63.31%)
 * Likes:    624
 * Dislikes: 0
 * Total Accepted:    190.4K
 * Total Submissions: 300.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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
#include<vector>
#include<queue>
using namespace std;
#if 0
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 #endif
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       if (root == NULL)  return {};
       vector<vector<int>>res;
       queue<TreeNode*>tmp_queue;
        tmp_queue.push(root);
       while (!tmp_queue.empty())
       {
           res.push_back(vector<int>());
           int N = tmp_queue.size();
           for (int i = 0; i < N; i++)
           {
               TreeNode *p = tmp_queue.front();
               res.back().push_back(p->val);
               tmp_queue.pop();
               if (p->left != NULL) tmp_queue.push(p->left);
               if (p->right != NULL) tmp_queue.push(p->right);
           }
       }
       return res;
    }
};
// @lc code=end

