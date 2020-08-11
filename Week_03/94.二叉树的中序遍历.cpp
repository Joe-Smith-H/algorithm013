/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include<stack>
using namespace std;
class Solution {
public:
    vector<int>res;
    vector<int> inorderTraversal(TreeNode* root) {
       if (root == NULL) return res;
       stack<TreeNode *>tmp;
       while(root != NULL || !tmp.empty())
       {
           while (root != NULL)//找左节点
           {
               tmp.push(root);
               root = root->left;
           }
           root = tmp.top();
           tmp.pop();
           res.push_back(root->val);
           root = root->right;
       }

     
       return res;

    }
};
// @lc code=end

